#include "Text.h"
#include "Texture.h"
#include <iostream>
#include <cassert>

bool Text::Create(Renderer& renderer, const std::string& text, const Colour& colour)
{
    assert(m_font);

    // creates a surface using the font, text, and colour
    SDL_Color c{ Colour::ToInt(colour.r), Colour::ToInt(colour.g), Colour::ToInt(colour.b), Colour::ToInt(colour.a) };
    SDL_Surface* surface = TTF_RenderText_Solid(m_font->m_ttfFont, text.c_str(), c);

    if (surface == nullptr)
    {
        std::cerr << "Could not create surface.\n";
        return false;
    }

    // creates a texture from the surface, only textures can render to the renderer
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
    if (texture == nullptr)
    {
        SDL_FreeSurface(surface);
        std::cerr << "Could not create surface.\n";
        return false;
    }

    //free suface, as its no longer needed after creating texture
    SDL_FreeSurface(surface);

    // create texture object
    m_texture = std::make_shared<Texture>(texture);

    return true;
}

void Text::Draw(Renderer& renderer, float x, float y, float angle)
{
    assert(m_texture);
    
    renderer.DrawTexture(m_texture, x, y, angle);
}
