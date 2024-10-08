#pragma once

// **core**
#include "Core/ETime.h"
#include "Core/EAssert.h"
#include "Core/EFile.h"
#include "Core/EString.h"
#include "Core/Json.h"
#include "Core/Factory.h"
#include "Core/Singleton.h"

// **systems**
//renderer
#include "Renderer/Renderer.h"
#include "Renderer/Particle.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Model.h"

// input
#include "Input/Input.h"

//audio
#include "Audio/Audio.h"

// **math**
#include "Math/Vector2.h"
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"
#include "Math/Rect.h"

// **framework**
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"

// **resources**
#include "Resources/Resource.h"
#include "Resources/ResourceManager.h"

// **event system**
#include "Event/EventSystem.h"


// **components**
#include "Components/TextureComponent.h"
#include "Components/EnginePhysicsComponent.h"
#include "Components/TextComponent.h"

// **physics**
#include "Physics/Physics.h"


#include <fmod.hpp>
#include <SDL.h>
#include <memory>
#include <cassert>

#define RENDERER g_engine.GetRenderer()
#define INPUT g_engine.GetInput()
#define AUDIO g_engine.GetRenderer()

class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput() { return *m_input; }
	Audio& GetAudio() { return *m_audio; }

	void GetPS();
	bool IsQuit() { return quit; }

	Time& GetTime() { return *m_time; }

	Physics& GetPhysics() { return *m_physics; }

public:
	bool quit{ false };
	std::unique_ptr<Time> m_time;
	std::unique_ptr<Renderer> m_renderer{ nullptr };
	std::unique_ptr<Input> m_input{ nullptr };
	std::unique_ptr<Audio> m_audio{ nullptr };
	std::unique_ptr<Physics> m_physics;
};