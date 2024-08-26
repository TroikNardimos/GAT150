#include "Scene.h"
#include "Actor.h"
#include "Core/Factory.h"
#include "Core/EAssert.h"
#include "Components/CollisionComponent.h"
#include <algorithm>

Scene::Scene(const Scene& other)
{
	ASSERT(false);
}

void Scene::Initialize()
{
	for (auto& actor : actors)
	{
		actor->Initialize();
	}
}


void Scene::Update(float dt)
{
	for (auto& actor : actors)
	{
		if (actor->active) actor->Update(dt);
	}

	// destroy
	actors.erase(std::remove_if(actors.begin(), actors.end(), [](const std::unique_ptr<Actor>& actor) { return actor->destroyed; }), actors.end());
}

void Scene::Draw(Renderer& renderer)
{
	for (auto& actor : actors)
	{
		if (actor->active)
		{
			actor->Draw(renderer);
		}
	}
}

void Scene::AddActor(std::unique_ptr<Actor> actor, bool initialize)
{
	actor->scene = this;
	if (initialize) actor->Initialize();
	actors.push_back(std::move(actor));
}

void Scene::RemoveAll()
{
	actors.clear();
}

void Scene::Read(const json_t& value)
{
	if (HAS_DATA(value, actors) && GET_DATA(value, actors).IsArray())
	{
		for (auto& actorValue : GET_DATA(value, actors).GetArray())
		{
			auto actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
			actor->Read(actorValue);

			bool prototype = false;
			READ_DATA(actorValue, prototype);

			if (prototype)
			{
				std::string name = actor->name;
				Factory::Instance().RegisterPrototype<Actor>(name, std::move(actor));
			}
			else
			{
				AddActor(std::move(actor));
			}
		}
	}
}

void Scene::Write(json_t& value)
{
	//
}