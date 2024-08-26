#include "Engine.h"
#include "SpaceGame.h"

#include <iostream>
#include <cstdlib>
#include <vector>

//GitHub: https://github.com/TroikNardimos/GAT150

int main(int argc, char* argv[])
{
	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();

	std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>(engine.get());
	game->Initialize();
		

	while (!engine->IsQuit()) {
		engine->Update();
		game->Update(engine->GetTime().GetDeltaTime());

		//render
		engine->GetRenderer().SetColour(255, 255, 255, 0);
		engine->GetRenderer().BeginFrame();

		//Draw here
		game->Draw(engine->GetRenderer());

		engine->GetRenderer().EndFrame();
	}
	game->Shutdown();
	ResourceManager::Instance().Clear();
	engine->Shutdown(); 

	return 0;
}