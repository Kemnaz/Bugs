#include "resourceHolder.h"




resourceHolder::resourceHolder()
    : textures()
{
}

sf::Texture& resourceHolder::getTexture(std::string path)
{
    auto& pairFound = textures.find(path);
    if (pairFound != textures.end()) {

        return pairFound->second;
    }
    else
    {
        auto& texture = textures[path];
        texture.loadFromFile(path);
        return texture;
    }
}

sf::Font& resourceHolder::getFont(std::string path)
{
    auto& pairFound = fonts.find(path);
    if (pairFound != fonts.end()) {

        return pairFound->second;
    }
    else
    {
        auto& font = fonts[path];
        font.loadFromFile(path);
        return font;
    }
}

sf::SoundBuffer& resourceHolder::getSound(std::string path)
{
    auto pairFound = sounds.find(path);
    if (pairFound != sounds.end())
    {
        return pairFound->second;
    }
    else
    {

        auto& sBuffer = sounds[path];
        sBuffer.loadFromFile(path);
        return sBuffer;
    }
}