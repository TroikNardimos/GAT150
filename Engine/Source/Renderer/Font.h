#pragma once
#include "../Resources/Resource.h"

#include <string>
#include <SDL_ttf.h>

class Font : public Resource
{
	friend class Text;
public:
	Font() = default;
	~Font();

	bool Create(std::string name, ...) override;
	bool Load(const std::string& name, int fontsize);

protected:
	_TTF_Font* m_ttfFont{ nullptr };
};