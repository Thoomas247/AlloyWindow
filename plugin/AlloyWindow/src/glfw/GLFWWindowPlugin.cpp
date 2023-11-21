#include "GLFWWindowPlugin.hpp"

#include "glfw/include/GLFW/glfw3.h"

#include "GLFWWindow.hpp"
#include "AlloyCore/app/Application.hpp"


namespace Alloy::Internal
{

	void Init(Window& window, const WindowInitProperties& initProperties)
	{
		static_cast<GLFWWindow&>(window).Init(initProperties);
	}


	/* -- PUBLIC -- */

	void GLFWWindowPlugin::Build(Application& app)
	{
		// resources
		app.AddResourceAs<GLFWWindow, Window>();
		app.AddResourceIfMissing<WindowInitProperties>();

		// stages
		app.AddStageBefore(ScheduleID::Startup, "InitWindow", DEFAULT_STARTUP_STAGE);

		// systems
		app.AddSystem(ScheduleID::Startup, "InitWindow", Init);
	}
}


