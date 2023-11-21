-- glfw project --
project "glfw"
	location "glfw"

	kind "StaticLib"
	staticruntime "On"

	language "C"

	targetdir ("bin/" .. OUTPUT_DIR .. "/%{prj.name}")
	objdir ("int/" .. OUTPUT_DIR .. "/%{prj.name}")

	defines { "_CRT_SECURE_NO_WARNINGS" }

	files
	{
		-- see glfw cmake files for needed includes per system
		
		"%{prj.name}/src/context.c",
		"%{prj.name}/src/init.c",
		"%{prj.name}/src/input.c",
		"%{prj.name}/src/monitor.c",
		"%{prj.name}/src/platform.c",
		"%{prj.name}/src/vulkan.c",
		"%{prj.name}/src/window.c",
		"%{prj.name}/src/egl_context.c",
		"%{prj.name}/src/osmesa_context.c",
		
		"%{prj.name}/src/null_init.c",
		"%{prj.name}/src/null_monitor.c",
		"%{prj.name}/src/null_window.c",
		"%{prj.name}/src/null_joystick.c"
	}

	filter "system:windows"
		files
		{
			"%{prj.name}/src/win32_module.c",
			"%{prj.name}/src/win32_time.c",
			"%{prj.name}/src/win32_thread.c",

			"%{prj.name}/src/win32_init.c",
			"%{prj.name}/src/win32_joystick.c",
			"%{prj.name}/src/win32_monitor.c",
			"%{prj.name}/src/win32_window.c",
			"%{prj.name}/src/wgl_context.c"
		}

		defines
		{
			"_GLFW_WIN32"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		runtime "Release"
		optimize "On"
