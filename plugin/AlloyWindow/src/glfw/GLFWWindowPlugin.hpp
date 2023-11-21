#pragma once
#include "AlloyCore/plugin/Plugin.hpp"

namespace Alloy::Internal
{
	/// <summary>
	/// GLFW implementation of the window plugin.
	/// </summary>
	class GLFWWindowPlugin : public Plugin
	{
	public:
		void Build(Application& app) override;
	};
}