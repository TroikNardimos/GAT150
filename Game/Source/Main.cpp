#include "Engine.h"

#include <iostream>
#include <vector>

//GitHub: https://github.com/TroikNardimos/GAT150

int main(int argc, char* argv[])
{
	g_engine.Initialize();
	while (!g_engine.IsQuit()) {
		g_engine.Update();

		g_engine.GetRenderer().SetColour(random(255), random(255), random(255), 0);
		g_engine.GetRenderer().BeginFrame();

		//Draw here

		g_engine.GetRenderer().EndFrame();
	}
	g_engine.Shutdown(); 
	return 0;
}