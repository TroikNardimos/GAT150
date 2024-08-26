#include "TextureAnimationComponent.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"
#include "Resources/ResourceManager.h"
#include "Engine.h"

FACTORY_REGISTER(TextureAnimationComponent)

void TextureAnimationComponent::Initialize()
{
	TextureComponent::Initialize();
}

void TextureAnimationComponent::Update(float dt)
{
	TextureComponent::Update(dt);
	frameTimer -= dt;
	if (frameTimer <= 0)
	{
		frameTimer = 1.0f / fps;
		frame += 1;
		if ((frame > endFrame) && (loop = true)) frame = startFrame;
	}

	Vector2 size = texture.get()->GetSize() / Vector2{numColumns, numRows};
	int column = (frame - 1) % numColumns;
	int row = (frame - 1) / numColumns;

	source.x = (int)(column * size.x);
	source.y = (int)(row * size.y);
	source.w = (int)(size.x);
	source.h = (int)(size.y);
}

void TextureAnimationComponent::Read(const json_t& value)
{
	TextureComponent::Read(value);

	READ_DATA(value, fps);
	READ_DATA(value, loop);
	READ_DATA(value, numColumns);
	READ_DATA(value, numRows);
	READ_DATA(value, startFrame);
	READ_DATA(value, endFrame);
}

void TextureAnimationComponent::Write(json_t& value)
{
	//
}
