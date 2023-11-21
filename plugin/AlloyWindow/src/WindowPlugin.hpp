#pragma once

/*
* Window plugin configuration.
* Depending on the platform, a different backend will be used.
*/

//#ifdef AL_PLATFORM_WINDOWS
#include "glfw/GLFWWindowPlugin.hpp"
namespace Alloy { using WindowPlugin = Internal::GLFWWindowPlugin; }
//#endif // AL_PLATFORM_WINDOWS