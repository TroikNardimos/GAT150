#pragma once

// **core**
#include "Core/ETime.h"
#include "Core/EAssert.h"
#include "Core/EFile.h"

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

// **framework**
#include "Framework/Actor.h"
#include "Framework/Scene.h"

// **resources**
#include "Resources/Resource.h"
#include "Resources/ResourceManager.h"

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
	bool IsQuit();

public:
	bool quit{ false };
	std::unique_ptr<Renderer> m_renderer{ nullptr };
	std::unique_ptr<Input> m_input{ nullptr };
	std::unique_ptr<Audio> m_audio{ nullptr };
};