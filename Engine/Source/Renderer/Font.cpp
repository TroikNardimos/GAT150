#include "Font.h"
#include <iostream>

Font::~Font()
{
    if (m_ttfFont != nullptr)
    {
        TTF_CloseFont(m_ttfFont);
    }
}

bool Font::Load(const std::string& name, int fontsize)
{
    m_ttfFont = TTF_OpenFont(name.c_str(), fontsize);
    if (m_ttfFont == nullptr)
    {
        std::cerr << "Could not load font: " << name << std::endl;
    }
    return true;
}

bool Font::Create(std::string name, ...)
{
    va_list args;
    va_start(args, name);
    int fontsize = va_arg(args, int);
    va_end(args);

    return Load(name, fontsize);
}
