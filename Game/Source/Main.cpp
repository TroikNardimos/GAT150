#include "Engine.h"

#include <iostream>
#include <cstdlib>
#include <vector>

//GitHub: https://github.com/TroikNardimos/GAT150

int main(int argc, char* argv[])
{
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();

	//ResourceManager rm = ResourceManager();

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("Skyrim_logo.png", engine->GetRenderer());
	//res_t<Texture> texture2 = ResourceManager::Instance().Get<Texture>("Skyrim_logo.png", engine->GetRenderer());

	while (!engine->IsQuit()) {
		engine->Update();

		engine->GetRenderer().SetColour(255, 255, 255, 0);
		engine->GetRenderer().BeginFrame();

		//Draw here
		engine->GetRenderer().DrawTexture(texture.get(), 30, 30);

		engine->GetRenderer().EndFrame();
	}
	engine->Shutdown(); 

	return 0;
}