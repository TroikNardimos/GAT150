#pragma once
#include "../Resources/Resource.h"
#include "../Math/Vector2.h"
#include <string>

struct SDL_Texture;

class Texture : public Resource
{
	friend class Renderer;
public:
	Texture() = default;
	Texture(SDL_Texture* texture) : m_texture{ texture } {}
	~Texture();

	bool Create(std::string name, ...) override;
	bool Load(const std::string& filename, class Renderer& renderer);

	Vector2 GetSize();
private:
	SDL_Texture* m_texture{ nullptr };
};
