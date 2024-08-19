#include "Texture.h"
#include "Renderer.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../Core/EAssert.h"
#include <iostream>

Texture::~Texture()
{
    if (m_texture != nullptr) SDL_DestroyTexture(m_texture);
}

bool Texture::Load(const std::string& filename, Renderer& renderer)
{
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if (surface == nullptr)
    {
        std::cerr << "Could not load image: " << filename << std::endl;
        return false;
    }
    m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
    SDL_FreeSurface(surface);
    if (m_texture == nullptr)
    {
        std::cerr << "Could not create texture: " << filename << std::endl;
        return false;
    }

    return true;
}

Vector2 Texture::GetSize()
{
    ASSERT(m_texture != nullptr);

    SDL_Point size;
    SDL_QueryTexture(m_texture, NULL, NULL, &size.x, &size.y );

    return Vector2{size.x, size.y};
}

bool Texture::Create(std::string name, ...)
{
    va_list args;
    va_start(args, name);
    Renderer& renderer = va_arg(args, Renderer);
    va_end(args);

    return Load(name, renderer);
}
