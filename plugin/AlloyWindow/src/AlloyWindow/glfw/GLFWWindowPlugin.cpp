#include "AlloyWindow/glfw/GLFWWindowPlugin.hpp"

#include "glfw/include/GLFW/glfw3.h"

#include "AlloyWindow/glfw/GLFWWindow.hpp"
#include "AlloyCore/app/Application.hpp"


namespace Alloy::Internal
{

	void Init(Window& window, const WindowInitProperties& initProperties)
	{
		static_cast<GLFWWindow&>(window).Init(initProperties);
	}


	/* -- PUBLIC -- */

	void GLFWWindowPlugin::Build(Commands commands)
	{
		// resources
		commands.AddResourceAs<GLFWWindow, Window>();
		commands.AddResourceIfMissing<WindowInitProperties>();

		// stages
		commands.AddStageBefore(ScheduleID::Startup, "InitWindow", DEFAULT_STARTUP_STAGE);

		// systems
		commands.AddSystem(ScheduleID::Startup, "InitWindow", Init);
	}
}


