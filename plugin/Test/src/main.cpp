#include "AlloyCore/app/Application.hpp"
#include "AlloyWindow/WindowPlugin.hpp"

int main()
{
	Alloy::Application app;

	app.AddPlugin<Alloy::WindowPlugin>();

	app.Run();

	return 0;
}