#include "AlloyWindow/glfw/GLFWWindow.hpp"

#include "glfw/include/GLFW/glfw3.h"

#include "AlloyCore/log/Log.hpp"

namespace Alloy::Internal
{

	/* -- PUBLIC -- */

	GLFWWindow::~GLFWWindow()
	{
		glfwDestroyWindow(m_pWindow);
		glfwTerminate();
	}

	void GLFWWindow::Init(const WindowInitProperties& initProperties)
	{
		ASSERT(!s_GLFWInitialized, "Cannot create more than one window!");

		// init glfw
		int result = glfwInit();
		ASSERT(result, "Failed to initialize GLFW!");

		s_GLFWInitialized = true;

		INFO("Creating window \"{0}\" ({1}px, {2}px)", initProperties.Title, initProperties.Width, initProperties.Height);

		// create the glfw pWindow
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);	// we aren't using OpenGL
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);		// window will be resizable

		m_pWindow = glfwCreateWindow((int)initProperties.Width, (int)initProperties.Height, initProperties.Title.c_str(), nullptr, nullptr);

		ASSERT(m_pWindow, "Failed to create GLFW pWindow!");
	}

	GLFWwindow* GLFWWindow::GetHandle()
	{
		return m_pWindow;
	}

}
