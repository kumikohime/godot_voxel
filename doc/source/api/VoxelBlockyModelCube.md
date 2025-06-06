# VoxelBlockyModelCube

Inherits: [VoxelBlockyModel](VoxelBlockyModel.md)

Generates a cube model with specific tiles on its sides.

## Properties: 


Type                                                                            | Name                                                       | Default                  
------------------------------------------------------------------------------- | ---------------------------------------------------------- | -------------------------
[Vector2i](https://docs.godotengine.org/en/stable/classes/class_vector2i.html)  | [atlas_size_in_tiles](#i_atlas_size_in_tiles)              | Vector2i(16, 16)         
[AABB[]](https://docs.godotengine.org/en/stable/classes/class_aabb[].html)      | [collision_aabbs](#i_collision_aabbs)                      | [AABB(0, 0, 0, 1, 1, 1)] 
[float](https://docs.godotengine.org/en/stable/classes/class_float.html)        | [height](#i_height)                                        | 1.0                      
[int](https://docs.godotengine.org/en/stable/classes/class_int.html)            | [mesh_ortho_rotation_index](#i_mesh_ortho_rotation_index)  | 0                        
<p></p>

## Methods: 


Return                                                                          | Signature                                                                                                                                                           
------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------
[Vector2i](https://docs.godotengine.org/en/stable/classes/class_vector2i.html)  | [get_tile](#i_get_tile) ( [Side](VoxelBlockyModel.md#enumerations) side ) const                                                                                     
[void](#)                                                                       | [set_tile](#i_set_tile) ( [Side](VoxelBlockyModel.md#enumerations) side, [Vector2i](https://docs.godotengine.org/en/stable/classes/class_vector2i.html) position )  
<p></p>

## Property Descriptions

### [Vector2i](https://docs.godotengine.org/en/stable/classes/class_vector2i.html)<span id="i_atlas_size_in_tiles"></span> **atlas_size_in_tiles** = Vector2i(16, 16)

Sets a reference size of texture atlas, in tiles. It must be set so the model generates correct texture coordinates from specified tile positions.

If you are not using an atlas and every side uses the same full texture, use (1,1).

### [AABB[]](https://docs.godotengine.org/en/stable/classes/class_aabb[].html)<span id="i_collision_aabbs"></span> **collision_aabbs** = [AABB(0, 0, 0, 1, 1, 1)]


### [float](https://docs.godotengine.org/en/stable/classes/class_float.html)<span id="i_height"></span> **height** = 1.0

*(This property has no documentation)*

### [int](https://docs.godotengine.org/en/stable/classes/class_int.html)<span id="i_mesh_ortho_rotation_index"></span> **mesh_ortho_rotation_index** = 0

*(This property has no documentation)*

## Method Descriptions

### [Vector2i](https://docs.godotengine.org/en/stable/classes/class_vector2i.html)<span id="i_get_tile"></span> **get_tile**( [Side](VoxelBlockyModel.md#enumerations) side ) 

*(This method has no documentation)*

### [void](#)<span id="i_set_tile"></span> **set_tile**( [Side](VoxelBlockyModel.md#enumerations) side, [Vector2i](https://docs.godotengine.org/en/stable/classes/class_vector2i.html) position ) 

*(This method has no documentation)*

_Generated on Apr 27, 2025_
