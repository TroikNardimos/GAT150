#include "SpaceGame.h"
#include "Engine.h"

#include <memory>

bool SpaceGame::Initialize()
{

	m_scene = std::make_unique<Scene>(m_engine);
	std::string sceneNames[] = { "Scenes/tilemap.json" , "Scenes/game.json" };

	for (auto sceneName : sceneNames)
	{
		rapidjson::Document document;
		Json::Load(sceneName, document);
		m_scene->Read(document);
	}

	m_scene->Initialize();

	ADD_OBSERVER(PlayerDead, SpaceGame::OnPlayerDead);
	ADD_OBSERVER(AddPoints, SpaceGame::OnAddPoints);

	return true;
}

void SpaceGame::Shutdown()
{
	m_scene->RemoveAll();
}

void SpaceGame::Update(float dt)
{
	m_scene->Update(dt);
}

void SpaceGame::Draw(Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void SpaceGame::OnPlayerDead(const Event& event)
{
	std::cout << "game player dead\n";
}

void SpaceGame::OnAddPoints(const Event& event)
{
	m_score += std::get<int>(event.data);
	std::cout << m_score << std::endl;
}
