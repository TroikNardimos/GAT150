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
	Time time;

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;
	{
		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("Skyrim_logo.png", engine->GetRenderer());
		res_t<Font> font = ResourceManager::Instance().Get<Font>("Arcadeclassic.ttf", 50);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Howdy", { 0,0,1,1 });

		Transform t{ {30, 30} };
		std::unique_ptr<Actor> actor = std::make_unique<Actor>(t);
		std::unique_ptr<TextureComponent> component = std::make_unique<TextureComponent>();
		component->texture = texture;
		actor->AddComponent(std::move(component));

		while (!engine->IsQuit()) {
			engine->Update();

			actor->Update(engine->GetTime().GetDeltaTime());

			engine->GetRenderer().SetColour(255, 255, 255, 0);
			engine->GetRenderer().BeginFrame();

			//Draw here
			text->Draw(engine->GetRenderer(), 400, 500);
			//engine->GetRenderer().DrawTexture(texture.get(), 30, 30, 0);
			actor->Draw(engine->GetRenderer());

			engine->GetRenderer().EndFrame();
		}
	}
	ResourceManager::Instance().Clear();
	engine->Shutdown(); 

	return 0;
}