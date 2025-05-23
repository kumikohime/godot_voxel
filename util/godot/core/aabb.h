#ifndef ZN_GODOT_AABB_H
#define ZN_GODOT_AABB_H

#if defined(ZN_GODOT)
#include <core/math/aabb.h>
#elif defined(ZN_GODOT_EXTENSION)
#include <godot_cpp/variant/aabb.hpp>
using namespace godot;
#endif

#include "../../string/std_stringstream.h"

namespace zylann {

StdStringStream &operator<<(StdStringStream &ss, const AABB &v);

} // namespace zylann

#endif // ZN_GODOT_AABB_H
