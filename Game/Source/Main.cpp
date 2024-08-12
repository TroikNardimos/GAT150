#include "Engine.h"

#include <iostream>
#include <cstdlib>
#include <vector>

//GitHub: https://github.com/TroikNardimos/GAT150

int main(int argc, char* argv[])
{
	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());
	//auto a = Factory::Instance().Create("Actor");

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	std::string buffer;
	File::ReadFile("json.txt", buffer);
	std::cout << buffer << std::endl;

	rapidjson::Document document;
	Json::Load("json.txt", document);

	std::string name;
	int age;
	float speed;
	bool isAwake;
	Vector2 position;
	Colour colour;

	READ_DATA(document, name);
	READ_DATA(document, age);
	READ_DATA(document, speed);
	READ_DATA(document, isAwake);
	READ_DATA(document, position);
	READ_DATA(document, colour);

	std::cout << name << " " << age << " " << speed << " " << isAwake << std::endl;
	std::cout << position.x << " " << position.y << std::endl;
	std::cout << colour.r << " " << colour.g << " " << colour.b << " " << colour.a << std::endl;

	{
		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("Skyrim_logo.png", engine->GetRenderer());
		res_t<Font> font = ResourceManager::Instance().Get<Font>("Arcadeclassic.ttf", 50);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Howdy", { 0,0,1,1 });

		Transform t{ {30, 30} };
		auto actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
		actor->SetTransform(Transform{ {30,30} });
		auto component = Factory::Instance().Create<TextureComponent>(TextureComponent::GetTypeName());
		component->texture = texture;
		actor->AddComponent(std::move(component));

		while (!engine->IsQuit()) {
			engine->Update();

			actor->Update(engine->GetTime().GetDeltaTime());

			engine->GetRenderer().SetColour(255, 255, 255, 0);
			engine->GetRenderer().BeginFrame();

			//Draw here
			actor->Draw(engine->GetRenderer());
			text->Draw(engine->GetRenderer(), 400, 500);
			//engine->GetRenderer().DrawTexture(texture.get(), 30, 30, 0);

			engine->GetRenderer().EndFrame();
		}
	}
	ResourceManager::Instance().Clear();
	engine->Shutdown(); 

	return 0;
}