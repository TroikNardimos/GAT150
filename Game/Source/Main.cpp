#include "Engine.h"

#include <iostream>
#include <cstdlib>
#include <vector>

//GitHub: https://github.com/TroikNardimos/GAT150

int main(int argc, char* argv[])
{
	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();


	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	std::string buffer;
	File::ReadFile("Scenes/scene.json", buffer);
	std::cout << buffer << std::endl;

	rapidjson::Document document;
	Json::Load("Scenes/scene.json", document);

	std::unique_ptr<Scene> scene = std::make_unique<Scene>(engine.get());
	scene->Read(document);

	scene->Initialize();

	{
		/*res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("Skyrim_logo.png", engine->GetRenderer());
		res_t<Font> font = ResourceManager::Instance().Get<Font>("Arcadeclassic.ttf", 50);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Howdy", { 0,0,1,1 });

		auto actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
		actor->transform = Transform{ {30,30} };
		auto component = Factory::Instance().Create<TextureComponent>(TextureComponent::GetTypeName());
		component->texture = texture;
		actor->AddComponent(std::move(component));*/

		while (!engine->IsQuit()) {
			engine->Update();
			scene->Update(engine->GetTime().GetDeltaTime());

			engine->GetRenderer().SetColour(255, 255, 255, 0);
			engine->GetRenderer().BeginFrame();

			//Draw here
			

			scene->Draw(engine->GetRenderer());

			engine->GetRenderer().EndFrame();
		}
	}
	ResourceManager::Instance().Clear();
	engine->Shutdown(); 

	return 0;
}