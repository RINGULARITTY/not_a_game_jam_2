#pragma once

#include "renderElement.hpp"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class SpriteWrapper : RenderElement {
public:
    SpriteWrapper();

    void load();

    void render(sf::RenderWindow& rw);

    std::string texturePath;
private:
    sf::Sprite sprite;
    sf::Texture texture;
};