# VoxelTool

Inherits: [RefCounted](https://docs.godotengine.org/en/stable/classes/class_refcounted.html)

Inherited by: [VoxelToolBuffer](VoxelToolBuffer.md), [VoxelToolLodTerrain](VoxelToolLodTerrain.md), [VoxelToolMultipassGenerator](VoxelToolMultipassGenerator.md), [VoxelToolTerrain](VoxelToolTerrain.md)

Helper class to easily access and modify voxels

## Description: 

Abstract interface to access and edit voxels. It allows accessing individual voxels, or doing bulk operations such as carving large chunks or copy/paste boxes.

It's not a class to instantiate alone, you may get it from the voxel objects you want to work with, because it has multiple derived implementations.

By default, if an operation overlaps a non-editable area (if not loaded yet for example), the operation will be cancelled. This behavior may vary in derived classes.

## Properties: 


Type                                                                      | Name                                   | Default 
------------------------------------------------------------------------- | -------------------------------------- | --------
[ChannelId](VoxelBuffer.md#enumerations)                                  | [channel](#i_channel)                  |         
[int](https://docs.godotengine.org/en/stable/classes/class_int.html)      | [eraser_value](#i_eraser_value)        |         
[Mode](VoxelTool.md#enumerations)                                         | [mode](#i_mode)                        |         
[float](https://docs.godotengine.org/en/stable/classes/class_float.html)  | [sdf_scale](#i_sdf_scale)              |         
[float](https://docs.godotengine.org/en/stable/classes/class_float.html)  | [sdf_strength](#i_sdf_strength)        |         
[float](https://docs.godotengine.org/en/stable/classes/class_float.html)  | [texture_falloff](#i_texture_falloff)  |         
[int](https://docs.godotengine.org/en/stable/classes/class_int.html)      | [texture_index](#i_texture_index)      |         
[float](https://docs.godotengine.org/en/stable/classes/class_float.html)  | [texture_opacity](#i_texture_opacity)  |         
[int](https://docs.godotengine.org/en/stable/classes/class_int.html)      | [value](#i_value)                      |         
<p></p>

## Methods: 


Return                                                                          | Signature                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[int](https://docs.godotengine.org/en/stable/classes/class_int.html)            | [color_to_u16](#i_color_to_u16) ( [Color](https://docs.godotengine.org/en/stable/classes/class_color.html) color ) static                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
[int](https://docs.godotengine.org/en/stable/classes/class_int.html)            | [color_to_u16_weights](#i_color_to_u16_weights) ( [Color](https://docs.godotengine.org/en/stable/classes/class_color.html) _unnamed_arg0 ) static                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
[void](#)                                                                       | [copy](#i_copy) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) src_pos, [VoxelBuffer](VoxelBuffer.md) dst_buffer, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) channels_mask )                                                                                                                                                                                                                                                                                                                                                                                                                                
[void](#)                                                                       | [do_box](#i_do_box) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) begin, [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) end )                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
[void](#)                                                                       | [do_mesh](#i_do_mesh) ( [VoxelMeshSDF](VoxelMeshSDF.md) mesh_sdf, [Transform3D](https://docs.godotengine.org/en/stable/classes/class_transform3d.html) transform, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) isolevel=0.0 )                                                                                                                                                                                                                                                                                                                                                                                                               
[void](#)                                                                       | [do_path](#i_do_path) ( [PackedVector3Array](https://docs.godotengine.org/en/stable/classes/class_packedvector3array.html) points, [PackedFloat32Array](https://docs.godotengine.org/en/stable/classes/class_packedfloat32array.html) radii )                                                                                                                                                                                                                                                                                                                                                                                                                           
[void](#)                                                                       | [do_point](#i_do_point) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos )                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
[void](#)                                                                       | [do_sphere](#i_do_sphere) ( [Vector3](https://docs.godotengine.org/en/stable/classes/class_vector3.html) center, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) radius )                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
[int](https://docs.godotengine.org/en/stable/classes/class_int.html)            | [get_voxel](#i_get_voxel) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos )                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
[float](https://docs.godotengine.org/en/stable/classes/class_float.html)        | [get_voxel_f](#i_get_voxel_f) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos )                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
[Variant](https://docs.godotengine.org/en/stable/classes/class_variant.html)    | [get_voxel_metadata](#i_get_voxel_metadata) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos ) const                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
[void](#)                                                                       | [grow_sphere](#i_grow_sphere) ( [Vector3](https://docs.godotengine.org/en/stable/classes/class_vector3.html) sphere_center, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) sphere_radius, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) strength )                                                                                                                                                                                                                                                                                                                                                                 
[bool](https://docs.godotengine.org/en/stable/classes/class_bool.html)          | [is_area_editable](#i_is_area_editable) ( [AABB](https://docs.godotengine.org/en/stable/classes/class_aabb.html) box ) const                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
[Color](https://docs.godotengine.org/en/stable/classes/class_color.html)        | [normalize_color](#i_normalize_color) ( [Color](https://docs.godotengine.org/en/stable/classes/class_color.html) _unnamed_arg0 ) static                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
[void](#)                                                                       | [paste](#i_paste) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) dst_pos, [VoxelBuffer](VoxelBuffer.md) src_buffer, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) channels_mask )                                                                                                                                                                                                                                                                                                                                                                                                                              
[void](#)                                                                       | [paste_masked](#i_paste_masked) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) dst_pos, [VoxelBuffer](VoxelBuffer.md) src_buffer, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) channels_mask, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) mask_channel, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) mask_value )                                                                                                                                                                                                                                            
[void](#)                                                                       | [paste_masked_writable_list](#i_paste_masked_writable_list) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) position, [VoxelBuffer](VoxelBuffer.md) voxels, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) channels_mask, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) src_mask_channel, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) src_mask_value, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) dst_mask_channel, [PackedInt32Array](https://docs.godotengine.org/en/stable/classes/class_packedint32array.html) dst_writable_list )  
[VoxelRaycastResult](VoxelRaycastResult.md)                                     | [raycast](#i_raycast) ( [Vector3](https://docs.godotengine.org/en/stable/classes/class_vector3.html) origin, [Vector3](https://docs.godotengine.org/en/stable/classes/class_vector3.html) direction, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) max_distance=10.0, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) collision_mask=4294967295 )                                                                                                                                                                                                                                                                       
[void](#)                                                                       | [set_raycast_normal_enabled](#i_set_raycast_normal_enabled) ( [bool](https://docs.godotengine.org/en/stable/classes/class_bool.html) enabled )                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
[void](#)                                                                       | [set_voxel](#i_set_voxel) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) v )                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
[void](#)                                                                       | [set_voxel_f](#i_set_voxel_f) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) v )                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
[void](#)                                                                       | [set_voxel_metadata](#i_set_voxel_metadata) ( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos, [Variant](https://docs.godotengine.org/en/stable/classes/class_variant.html) meta )                                                                                                                                                                                                                                                                                                                                                                                                                                                   
[void](#)                                                                       | [smooth_sphere](#i_smooth_sphere) ( [Vector3](https://docs.godotengine.org/en/stable/classes/class_vector3.html) sphere_center, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) sphere_radius, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) blur_radius )                                                                                                                                                                                                                                                                                                                                                              
[Vector4i](https://docs.godotengine.org/en/stable/classes/class_vector4i.html)  | [u16_indices_to_vec4i](#i_u16_indices_to_vec4i) ( [int](https://docs.godotengine.org/en/stable/classes/class_int.html) _unnamed_arg0 ) static                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
[Color](https://docs.godotengine.org/en/stable/classes/class_color.html)        | [u16_weights_to_color](#i_u16_weights_to_color) ( [int](https://docs.godotengine.org/en/stable/classes/class_int.html) _unnamed_arg0 ) static                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
[int](https://docs.godotengine.org/en/stable/classes/class_int.html)            | [vec4i_to_u16_indices](#i_vec4i_to_u16_indices) ( [Vector4i](https://docs.godotengine.org/en/stable/classes/class_vector4i.html) _unnamed_arg0 ) static                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
<p></p>

## Enumerations: 

enum **Mode**: 

- <span id="i_MODE_ADD"></span>**MODE_ADD** = **0** --- When editing [VoxelBuffer.CHANNEL_SDF](VoxelBuffer.md#i_CHANNEL_SDF), will add matter. Useful for building.
- <span id="i_MODE_REMOVE"></span>**MODE_REMOVE** = **1** --- When editing [VoxelBuffer.CHANNEL_SDF](VoxelBuffer.md#i_CHANNEL_SDF), will subtract matter. Useful for digging.
- <span id="i_MODE_SET"></span>**MODE_SET** = **2** --- Replace voxel values without any blending. Useful for blocky voxels.
- <span id="i_MODE_TEXTURE_PAINT"></span>**MODE_TEXTURE_PAINT** = **3** --- When editing [VoxelBuffer.CHANNEL_SDF](VoxelBuffer.md#i_CHANNEL_SDF) in smooth Terrain, enables texture painting. The value of [texture_index](VoxelTool.md#i_texture_index) will be added to texture indices of the affected voxels. The texture's weight will be blended based on the values of [texture_falloff](VoxelTool.md#i_texture_falloff) and [texture_opacity](VoxelTool.md#i_texture_opacity). Results will differ depending on which texturing mode is used by the mesher.


## Property Descriptions

### [ChannelId](VoxelBuffer.md#enumerations)<span id="i_channel"></span> **channel**

Set which channel will be edited. When used on a terrain node, it will default to the first available channel, based on the stream and generator.

### [int](https://docs.godotengine.org/en/stable/classes/class_int.html)<span id="i_eraser_value"></span> **eraser_value**

Sets which value will be used to erase voxels when editing the [VoxelBuffer.CHANNEL_TYPE](VoxelBuffer.md#i_CHANNEL_TYPE) channel in [MODE_REMOVE](VoxelTool.md#i_MODE_REMOVE) mode. Only relevant for blocky voxels.

### [Mode](VoxelTool.md#enumerations)<span id="i_mode"></span> **mode**

Sets how `do_*` functions will behave. This may vary depending on the channel.

### [float](https://docs.godotengine.org/en/stable/classes/class_float.html)<span id="i_sdf_scale"></span> **sdf_scale**

When working with smooth voxels, applies a scale to the signed distance field. A high scale (1 or higher) will tend to produce blocky results, and a low scale (below 1, but not too close to zero) will tend to be smoother.


This is related to the [Depth](VoxelBuffer.md#enumerations) configuration on voxels. For 8-bit and 16-bit, there is a limited range of values the Signed Distance Field can take, and by default it is clamped to -1..1, so the gradient can only range across 2 voxels. But when LOD is used, it is better to stretch that range over a longer distance, and this is achieved by scaling SDF values.

### [float](https://docs.godotengine.org/en/stable/classes/class_float.html)<span id="i_sdf_strength"></span> **sdf_strength**

When editing [VoxelBuffer.CHANNEL_SDF](VoxelBuffer.md#i_CHANNEL_SDF) of smooth Terrains in [MODE_ADD](VoxelTool.md#i_MODE_ADD) or [MODE_REMOVE](VoxelTool.md#i_MODE_REMOVE), determines the interpolation phase between current values and values set by the tool. Can be interpreted as the amount of "matter" added or subtracted.

### [float](https://docs.godotengine.org/en/stable/classes/class_float.html)<span id="i_texture_falloff"></span> **texture_falloff**

Range [0.001..1.0]. Determines texture blending strength when tool is set to [MODE_TEXTURE_PAINT](VoxelTool.md#i_MODE_TEXTURE_PAINT). Lower values produce sharper transitions. Can be compared to brush softness in an image editing program. This is only relevant with smooth voxels and texturing modes that support long gradients.

### [int](https://docs.godotengine.org/en/stable/classes/class_int.html)<span id="i_texture_index"></span> **texture_index**

Index of the texture used in smooth voxel texture painting mode. The choice of this index depends on the way you setup rendering of textured voxel meshes (for example, layer index in a texture array).

### [float](https://docs.godotengine.org/en/stable/classes/class_float.html)<span id="i_texture_opacity"></span> **texture_opacity**

Range [0.0..1.0]. Determines the maximum weight of a [texture_index](VoxelTool.md#i_texture_index) when tool is set to [MODE_TEXTURE_PAINT](VoxelTool.md#i_MODE_TEXTURE_PAINT). Can be compared to brush opacity in an image editing program.

### [int](https://docs.godotengine.org/en/stable/classes/class_int.html)<span id="i_value"></span> **value**

Sets which voxel value will be used. This is not relevant when editing [VoxelBuffer.CHANNEL_SDF](VoxelBuffer.md#i_CHANNEL_SDF).

## Method Descriptions

### [int](https://docs.godotengine.org/en/stable/classes/class_int.html)<span id="i_color_to_u16"></span> **color_to_u16**( [Color](https://docs.godotengine.org/en/stable/classes/class_color.html) color ) 

Encodes normalized 4-float color into 16-bit integer data. It is used with the COLOR channel, in cases where the channel represents direct colors (without using a palette).

### [int](https://docs.godotengine.org/en/stable/classes/class_int.html)<span id="i_color_to_u16_weights"></span> **color_to_u16_weights**( [Color](https://docs.godotengine.org/en/stable/classes/class_color.html) _unnamed_arg0 ) 

Encodes normalized 4-float color into 16-bit integer data, for use with the WEIGHTS channel.

### [void](#)<span id="i_copy"></span> **copy**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) src_pos, [VoxelBuffer](VoxelBuffer.md) dst_buffer, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) channels_mask ) 

Copies voxels in a box and stores them in the passed buffer. The source format will overwrite the destination.

`src_pos` is the lowest corner of the box, and its size is determined by the size of `dst_buffer`.

`channels_mask` is a bitmask where each bit tells which channels will be copied. Example: `1 << VoxelBuffer.CHANNEL_SDF` to get only SDF data. Use `0xff` if you want them all.

### [void](#)<span id="i_do_box"></span> **do_box**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) begin, [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) end ) 

Operate on a rectangular cuboid section of the terrain.

With blocky voxels, `begin` and `end` are inclusive.

With smooth voxels, `end` is exclusive.

You may choose which operation to do before calling this function, by setting [mode](VoxelTool.md#i_mode). With blocky voxels, you may also set [value](VoxelTool.md#i_value) to choose which voxel ID to use.

### [void](#)<span id="i_do_mesh"></span> **do_mesh**( [VoxelMeshSDF](VoxelMeshSDF.md) mesh_sdf, [Transform3D](https://docs.godotengine.org/en/stable/classes/class_transform3d.html) transform, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) isolevel=0.0 ) 

Applies the given mesh shape to the terrain. The model must be baked into a signed distance field with [VoxelMeshSDF](VoxelMeshSDF.md). `transform` may be used to position, rotate and scale the model. Non-uniform scale might introduce artifacts. `isolevel` is a distance that inflates or contracts the model if increased or decreased respectively. Quality depends on resolution of the model's SDF, and performance will be lower than primitive shapes such as [do_sphere](VoxelTool.md#i_do_sphere).

### [void](#)<span id="i_do_path"></span> **do_path**( [PackedVector3Array](https://docs.godotengine.org/en/stable/classes/class_packedvector3array.html) points, [PackedFloat32Array](https://docs.godotengine.org/en/stable/classes/class_packedfloat32array.html) radii ) 

Traces a "tube" defined by a list of points, each having a corresponding radius to control the width of the tube at each point. The begin and end of the path is rounded. This is equivalent to placing/carving multiple connected capsules with varying top/bottom radius. The path is not using bezier or splines, each point is connected linearly to the next. If you need more smoothness, you may add points to areas that need them. The more points, the slower it is.

### [void](#)<span id="i_do_point"></span> **do_point**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos ) 

Operates on a single voxel.

You may choose which operation to do before calling this function, by setting [mode](VoxelTool.md#i_mode). With blocky voxels, you may also set [value](VoxelTool.md#i_value) to choose which voxel ID to use.

This function is not well adapted to smooth voxels, and can introduce blockyness.

### [void](#)<span id="i_do_sphere"></span> **do_sphere**( [Vector3](https://docs.godotengine.org/en/stable/classes/class_vector3.html) center, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) radius ) 

Operate on voxels within a sphere.

You may choose which operation to do before calling this function, by setting [mode](VoxelTool.md#i_mode). With blocky voxels, you may also set [value](VoxelTool.md#i_value) to choose which voxel ID to use.

### [int](https://docs.godotengine.org/en/stable/classes/class_int.html)<span id="i_get_voxel"></span> **get_voxel**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos ) 

Gets data from voxel at `pos` coordinates. The returned value will be an unsigned integer. The meaning of the value depends on [channel](VoxelTool.md#i_channel) the tool is set to.

When using [VoxelBuffer.CHANNEL_SDF](VoxelBuffer.md#i_CHANNEL_SDF) for smooth voxels, the returned value will be an encoded value, so you may use [get_voxel_f](VoxelTool.md#i_get_voxel_f) to get a float value instead.

### [float](https://docs.godotengine.org/en/stable/classes/class_float.html)<span id="i_get_voxel_f"></span> **get_voxel_f**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos ) 

Gets data from voxel at `pos` coordinates, interpreting it as a floating-point SDF value. This is recommended to query the [VoxelBuffer.CHANNEL_SDF](VoxelBuffer.md#i_CHANNEL_SDF) channel for smooth voxels.

### [Variant](https://docs.godotengine.org/en/stable/classes/class_variant.html)<span id="i_get_voxel_metadata"></span> **get_voxel_metadata**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos ) 

Gets arbitrary data attached to a specific voxel.

### [void](#)<span id="i_grow_sphere"></span> **grow_sphere**( [Vector3](https://docs.godotengine.org/en/stable/classes/class_vector3.html) sphere_center, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) sphere_radius, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) strength ) 

Adds/removes (depending on `mode`) a value to/from all voxels within a sphere. Added/removed value will be equal to `strength` at the center of the sphere, and decreases linearly to zero at the surface of the sphere. Voxels outside the sphere will not be affected.

`sphere_center` is position in the terrain that will be smoothed out.

`sphere_radius` radius of a sphere from the `center` where voxel values will be affected. Should be greater than zero.

`strength` value that controls maximal value that will be added/removed to/from voxels. Suggested range is [0, 10].

Note 1: This is currently implemented only for terrain that uses SDF data (smooth voxels).

Note 2: This is meant to be analogous to Surface tool from Unreal Engine Voxel Plugin.

### [bool](https://docs.godotengine.org/en/stable/classes/class_bool.html)<span id="i_is_area_editable"></span> **is_area_editable**( [AABB](https://docs.godotengine.org/en/stable/classes/class_aabb.html) box ) 

Returns `true` if the specified voxel area can be edited. This can also be interpreted as the area being "loaded". Note: when using LOD, only the nearest LOD (0) is editable. Other factors can influence whether an area is editable or not, such as streaming mode or terrain bounds.

### [Color](https://docs.godotengine.org/en/stable/classes/class_color.html)<span id="i_normalize_color"></span> **normalize_color**( [Color](https://docs.godotengine.org/en/stable/classes/class_color.html) _unnamed_arg0 ) 

A helper method to set the sum of channels of the `Color` to 1.

### [void](#)<span id="i_paste"></span> **paste**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) dst_pos, [VoxelBuffer](VoxelBuffer.md) src_buffer, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) channels_mask ) 

Paste voxels in a box from the given buffer at a specific location.

`dst_pos` is the lowest corner of the box, and its size is determined by the size of `src_buffer`.

`channels_mask` is a bitmask where each bit tells which channels will be modified. Example: `1 << VoxelBuffer.CHANNEL_SDF` only write SDF data. Use `0xff` if you want them all.

### [void](#)<span id="i_paste_masked"></span> **paste_masked**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) dst_pos, [VoxelBuffer](VoxelBuffer.md) src_buffer, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) channels_mask, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) mask_channel, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) mask_value ) 

Paste voxels in a box from the given buffer at a specific location. Voxels having a specific value in a mask channel will not be pasted.

`dst_pos` is the lowest corner of the box, and its size is determined by the size of `src_buffer`.

`channels_mask` is a bitmask where each bit tells which channels will be modified. Example: `1 << VoxelBuffer.CHANNEL_SDF` only write SDF data. Use `0xff` if you want them all.

`src_mask_channel` channel from the source buffer that will be used to lookup mask values.

`src_mask_value` if voxels of the source buffer have this value in the channel specified for masking, then they won't be pasted.

### [void](#)<span id="i_paste_masked_writable_list"></span> **paste_masked_writable_list**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) position, [VoxelBuffer](VoxelBuffer.md) voxels, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) channels_mask, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) src_mask_channel, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) src_mask_value, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) dst_mask_channel, [PackedInt32Array](https://docs.godotengine.org/en/stable/classes/class_packedint32array.html) dst_writable_list ) 

Paste voxels in a box from the given buffer at a specific location. Voxels having a specific value in a mask channel of the source buffer will not be pasted, and existing voxels at the destination will only be modified if they have specific values.

`dst_pos` is the lowest corner of the box, and its size is determined by the size of `src_buffer`.

`channels_mask` is a bitmask where each bit tells which channels will be modified. Example: `1 << VoxelBuffer.CHANNEL_SDF` only write SDF data. Use `0xff` if you want them all.

`src_mask_channel` channel from the source buffer that will be used to lookup mask values.

`src_mask_value` if voxels of the source buffer have this value in the channel specified for masking, then they won't be pasted.

`dst_mask_channel` channel from the destination that will be used to select writable voxels.

`dst_writable_list` List of values the destination voxels must have in order to be written to. Values in that list must be between 0 and 65535. A very large amount of values can also affect performance.

### [VoxelRaycastResult](VoxelRaycastResult.md)<span id="i_raycast"></span> **raycast**( [Vector3](https://docs.godotengine.org/en/stable/classes/class_vector3.html) origin, [Vector3](https://docs.godotengine.org/en/stable/classes/class_vector3.html) direction, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) max_distance=10.0, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) collision_mask=4294967295 ) 

Runs a voxel-based raycast to find the first hit from an origin and a direction. Coordinates are in world space.

Returns a result object if a voxel got hit, otherwise returns `null`.

This is useful when colliders cannot be relied upon. It might also be faster (at least at short range), and is more precise to find which voxel is hit. It internally uses the DDA algorithm.

`collision_mask` is currently only used with blocky voxels. It is combined with [VoxelBlockyModel.collision_mask](VoxelBlockyModel.md#i_collision_mask) to decide which voxel types the ray can collide with.

### [void](#)<span id="i_set_raycast_normal_enabled"></span> **set_raycast_normal_enabled**( [bool](https://docs.godotengine.org/en/stable/classes/class_bool.html) enabled ) 

Sets whether [raycast](VoxelTool.md#i_raycast) will compute hit normals. This is true by default.

### [void](#)<span id="i_set_voxel"></span> **set_voxel**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) v ) 

Sets the raw integer value of a specific voxel on the current channel.

### [void](#)<span id="i_set_voxel_f"></span> **set_voxel_f**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) v ) 

Sets the signed distance field (SDF) value a specific voxel. This should preferably be used on the SDF channel.

### [void](#)<span id="i_set_voxel_metadata"></span> **set_voxel_metadata**( [Vector3i](https://docs.godotengine.org/en/stable/classes/class_vector3i.html) pos, [Variant](https://docs.godotengine.org/en/stable/classes/class_variant.html) meta ) 

*(This method has no documentation)*

### [void](#)<span id="i_smooth_sphere"></span> **smooth_sphere**( [Vector3](https://docs.godotengine.org/en/stable/classes/class_vector3.html) sphere_center, [float](https://docs.godotengine.org/en/stable/classes/class_float.html) sphere_radius, [int](https://docs.godotengine.org/en/stable/classes/class_int.html) blur_radius ) 

Smoothens out terrain by performing box blur in a spherical area. Strength will be maximal at the center of the sphere, and decreases linearly to zero at the surface of the sphere. Voxels outside the sphere will not be affected.

`sphere_center` is position in the terrain that will be smoothed out.

`sphere_radius` radius of a sphere from the `center` where voxel values will be affected. Should be greater than zero.

`blur_radius` half the box blur length that will be sampled to calculate average voxel values. Higher values results in more aggressive smoothing. Should be at least 1.

Note 1: This is currently implemented only for terrain that uses SDF data (smooth voxels).

Note 2: Beware of using high `sphere_radius` and high `blur_radius` as the performance can drop quickly if this is called 60 times a second.

### [Vector4i](https://docs.godotengine.org/en/stable/classes/class_vector4i.html)<span id="i_u16_indices_to_vec4i"></span> **u16_indices_to_vec4i**( [int](https://docs.godotengine.org/en/stable/classes/class_int.html) _unnamed_arg0 ) 

Decodes raw voxel integer data from the INDICES channel into a 4-integer vector.

### [Color](https://docs.godotengine.org/en/stable/classes/class_color.html)<span id="i_u16_weights_to_color"></span> **u16_weights_to_color**( [int](https://docs.godotengine.org/en/stable/classes/class_int.html) _unnamed_arg0 ) 

Decodes raw voxel integer data from the WEIGHTS channel into a normalized 4-float color.

### [int](https://docs.godotengine.org/en/stable/classes/class_int.html)<span id="i_vec4i_to_u16_indices"></span> **vec4i_to_u16_indices**( [Vector4i](https://docs.godotengine.org/en/stable/classes/class_vector4i.html) _unnamed_arg0 ) 

Encodes a 4-integer vector into 16-bit integer voxel data, for use in the INDICES channel.

_Generated on Apr 27, 2025_
