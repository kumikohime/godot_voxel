#ifndef SAVE_BLOCK_DATA_TASK_H
#define SAVE_BLOCK_DATA_TASK_H

#include "../engine/ids.h"
#include "../engine/streaming_dependency.h"
#include "../util/memory/memory.h"
#include "../util/tasks/threaded_task.h"

namespace zylann {

class AsyncDependencyTracker;

namespace voxel {

class SaveBlockDataTask : public IThreadedTask {
public:
	// For saving voxels only
	SaveBlockDataTask(
			VolumeID p_volume_id,
			Vector3i p_block_pos,
			uint8_t p_lod,
			std::shared_ptr<VoxelBuffer> p_voxels,
			std::shared_ptr<StreamingDependency> p_stream_dependency,
			std::shared_ptr<AsyncDependencyTracker> p_tracker,
			bool flush_on_last_tracked_task
	);

#ifdef VOXEL_ENABLE_INSTANCER
	// For saving instances only
	SaveBlockDataTask(
			VolumeID p_volume_id,
			Vector3i p_block_pos,
			uint8_t p_lod,
			UniquePtr<InstanceBlockData> p_instances,
			std::shared_ptr<StreamingDependency> p_stream_dependency,
			std::shared_ptr<AsyncDependencyTracker> p_tracker,
			bool flush_on_last_tracked_task
	);
#endif

	~SaveBlockDataTask();

	const char *get_debug_name() const override {
		return "SaveBlockData";
	}

	void run(ThreadedTaskContext &ctx) override;
	TaskPriority get_priority() override;
	bool is_cancelled() override;
	void apply_result() override;

	static int debug_get_running_count();

private:
	std::shared_ptr<VoxelBuffer> _voxels;
#ifdef VOXEL_ENABLE_INSTANCER
	UniquePtr<InstanceBlockData> _instances;
#endif
	Vector3i _position; // In data blocks of the specified lod
	VolumeID _volume_id;
	uint8_t _lod;
	bool _has_run = false;
	bool _save_instances = false;
	bool _save_voxels = false;
	bool _flush_on_last_tracked_task = false;
	std::shared_ptr<StreamingDependency> _stream_dependency;
	// Optional tracking, can be null
	std::shared_ptr<AsyncDependencyTracker> _tracker;
};

} // namespace voxel
} // namespace zylann

#endif // SAVE_BLOCK_DATA_TASK_H
