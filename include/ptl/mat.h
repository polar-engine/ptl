#pragma once

#include <ptl/number.h>

#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

namespace ptl {
	using mat4x4 = glm::tmat4x4<decimal, glm::highp>;
}
