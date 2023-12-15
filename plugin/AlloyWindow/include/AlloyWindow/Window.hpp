#pragma once
#include "AlloyCore/standard.hpp"
#include "AlloyCore/resource/Resource.hpp"

namespace Alloy
{
	/// <summary>
	/// Resource to set the initial window properties.
	/// Resource is deleted after the window is created.
	/// To access current window properties, use Window resource.
	/// </summary>
	struct WindowInitProperties : public Resource
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowInitProperties(const std::string& title = "Alloy Engine",
			unsigned int width = 1600,
			unsigned int height = 900)
			: Title(title), Width(width), Height(height)
		{}
	};

	/// <summary>
	/// Interface to interact with a window.
	/// </summary>
	class Window : public Resource
	{
	public:
		Window() = default;
		virtual ~Window() = default;
	};
}