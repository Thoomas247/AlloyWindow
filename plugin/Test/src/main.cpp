#include "AlloyCore/app/Application.hpp"
#include "WindowPlugin.hpp"

int main()
{
	Alloy::Application app;

	app.AddPlugin<Alloy::WindowPlugin>();

	app.Run();

	return 0;
}