#pragma once
#include "Window.hpp"

struct GLFWwindow;

namespace Alloy::Internal
{
	/// <summary>
	/// GLFW implementation of the Window class.
	/// </summary>
	class GLFWWindow : public Window
	{
	public:
		GLFWWindow() = default;
		~GLFWWindow();

		void Init(const WindowInitProperties& initProperties);

		GLFWwindow* GetHandle();

	private:
		inline static bool s_GLFWInitialized = false;

		GLFWwindow* m_pWindow;
	};
}