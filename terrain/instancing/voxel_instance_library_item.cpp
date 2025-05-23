#include "voxel_instance_library_item.h"
#include "../../constants/voxel_string_names.h"
#include "voxel_instancer.h"

#include <algorithm>

namespace zylann::voxel {

// TODO Deprecate in favor of resource name?
void VoxelInstanceLibraryItem::set_item_name(String p_name) {
	_name = p_name;

	// Also set resource name, so Godot will use it in array inspector
	set_name(p_name);
	emit_changed();
}

String VoxelInstanceLibraryItem::get_item_name() const {
	return _name;
}

void VoxelInstanceLibraryItem::set_lod_index(int lod) {
	ERR_FAIL_COND(lod < 0 || lod >= VoxelInstancer::MAX_LOD);
	if (_lod_index == lod) {
		return;
	}
	_lod_index = lod;
	notify_listeners(IInstanceLibraryItemListener::CHANGE_LOD_INDEX);
}

int VoxelInstanceLibraryItem::get_lod_index() const {
	return _lod_index;
}

void VoxelInstanceLibraryItem::set_generator(Ref<VoxelInstanceGenerator> generator) {
	if (_generator == generator) {
		return;
	}
	if (_generator.is_valid()) {
		_generator->disconnect(
				VoxelStringNames::get_singleton().changed,
				callable_mp(this, &VoxelInstanceLibraryItem::_on_generator_changed)
		);
	}
	_generator = generator;
	if (_generator.is_valid()) {
		_generator->connect(
				VoxelStringNames::get_singleton().changed,
				callable_mp(this, &VoxelInstanceLibraryItem::_on_generator_changed)
		);
	}
	notify_listeners(IInstanceLibraryItemListener::CHANGE_GENERATOR);
}

Ref<VoxelInstanceGenerator> VoxelInstanceLibraryItem::get_generator() const {
	return _generator;
}

void VoxelInstanceLibraryItem::set_persistent(bool persistent) {
	_persistent = persistent;
}

bool VoxelInstanceLibraryItem::is_persistent() const {
	return _persistent;
}

float VoxelInstanceLibraryItem::get_floating_sdf_threshold() const {
	return _floating_sdf_threshold;
}

void VoxelInstanceLibraryItem::set_floating_sdf_threshold(const float new_threshold) {
	_floating_sdf_threshold = new_threshold;
}

float VoxelInstanceLibraryItem::get_floating_sdf_offset_along_normal() const {
	return _floating_sdf_offset_along_normal;
}

void VoxelInstanceLibraryItem::set_floating_sdf_offset_along_normal(const float new_offset) {
	_floating_sdf_offset_along_normal = new_offset;
}

void VoxelInstanceLibraryItem::add_listener(IInstanceLibraryItemListener *listener, int id) {
	ListenerSlot slot;
	slot.listener = listener;
	slot.id = id;
	ERR_FAIL_COND(std::find(_listeners.begin(), _listeners.end(), slot) != _listeners.end());
	_listeners.push_back(slot);
}

void VoxelInstanceLibraryItem::remove_listener(IInstanceLibraryItemListener *listener, int id) {
	ListenerSlot slot;
	slot.listener = listener;
	slot.id = id;
	auto it = std::find(_listeners.begin(), _listeners.end(), slot);
	ERR_FAIL_COND(it == _listeners.end());
	_listeners.erase(it);
}

#ifdef TOOLS_ENABLED

void VoxelInstanceLibraryItem::get_configuration_warnings(PackedStringArray &warnings) const {
	if (_generator.is_null()) {
		warnings.append(
				String("A {0} has no generator assigned, it is needed for instances to spawn.").format(get_class())
		);
	} else {
		godot::get_resource_configuration_warnings(**_generator, warnings, []() { return "generator: "; });
	}
}

#endif

void VoxelInstanceLibraryItem::notify_listeners(IInstanceLibraryItemListener::ChangeType change) {
	for (unsigned int i = 0; i < _listeners.size(); ++i) {
		ListenerSlot &slot = _listeners[i];
		slot.listener->on_library_item_changed(slot.id, change);
	}
}

void VoxelInstanceLibraryItem::_on_generator_changed() {
	notify_listeners(IInstanceLibraryItemListener::CHANGE_GENERATOR);
}

void VoxelInstanceLibraryItem::_bind_methods() {
	// Can't be just "set_name" because Resource already defines that, despite being for a `resource_name` property
	ClassDB::bind_method(D_METHOD("set_item_name", "name"), &VoxelInstanceLibraryItem::set_item_name);
	ClassDB::bind_method(D_METHOD("get_item_name"), &VoxelInstanceLibraryItem::get_item_name);

	ClassDB::bind_method(D_METHOD("set_lod_index", "lod"), &VoxelInstanceLibraryItem::set_lod_index);
	ClassDB::bind_method(D_METHOD("get_lod_index"), &VoxelInstanceLibraryItem::get_lod_index);

	ClassDB::bind_method(D_METHOD("set_generator", "generator"), &VoxelInstanceLibraryItem::set_generator);
	ClassDB::bind_method(D_METHOD("get_generator"), &VoxelInstanceLibraryItem::get_generator);

	ClassDB::bind_method(D_METHOD("set_persistent", "persistent"), &VoxelInstanceLibraryItem::set_persistent);
	ClassDB::bind_method(D_METHOD("is_persistent"), &VoxelInstanceLibraryItem::is_persistent);

	ClassDB::bind_method(
			D_METHOD("set_floating_sdf_threshold", "sd"), &VoxelInstanceLibraryItem::set_floating_sdf_threshold
	);
	ClassDB::bind_method(D_METHOD("get_floating_sdf_threshold"), &VoxelInstanceLibraryItem::get_floating_sdf_threshold);

	ClassDB::bind_method(
			D_METHOD("set_floating_sdf_offset_along_normal", "sd"),
			&VoxelInstanceLibraryItem::set_floating_sdf_offset_along_normal
	);
	ClassDB::bind_method(
			D_METHOD("get_floating_sdf_offset_along_normal"),
			&VoxelInstanceLibraryItem::get_floating_sdf_offset_along_normal
	);

	ADD_PROPERTY(PropertyInfo(Variant::STRING, "name"), "set_item_name", "get_item_name");
	ADD_PROPERTY(
			PropertyInfo(Variant::INT, "lod_index", PROPERTY_HINT_RANGE, "0,8,1"), "set_lod_index", "get_lod_index"
	);
	ADD_PROPERTY(
			PropertyInfo(Variant::OBJECT, "generator", PROPERTY_HINT_RESOURCE_TYPE, "VoxelInstanceGenerator"),
			"set_generator",
			"get_generator"
	);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "persistent"), "set_persistent", "is_persistent");

	ADD_GROUP("Auto-removal detection", "");

	ADD_PROPERTY(
			PropertyInfo(Variant::FLOAT, "floating_sdf_threshold"),
			"set_floating_sdf_threshold",
			"get_floating_sdf_threshold"
	);

	ADD_PROPERTY(
			PropertyInfo(Variant::FLOAT, "floating_sdf_offset_along_normal"),
			"set_floating_sdf_offset_along_normal",
			"get_floating_sdf_offset_along_normal"
	);
}

} // namespace zylann::voxel
