#include "spriteWrapper.hpp"

SpriteWrapper::SpriteWrapper():
    texturePath{},
    texture{},
    sprite{}
{}

void SpriteWrapper::load() {
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
}

void SpriteWrapper::setScale(float scale) {
    sprite.setScale(sf::Vector2f(scale, scale));
}

void SpriteWrapper::setPosition(const sf::Vector2f& pos) {
    sprite.setPosition(pos);
}

void SpriteWrapper::render(sf::RenderWindow& rw) {
    rw.draw(sprite);
}

sf::Vector2f SpriteWrapper::getSize() {
    const sf::Vector2u& textSize = texture.getSize();
    const sf::Vector2f& spriteScale = sprite.getScale();

    return sf::Vector2f(textSize.x * spriteScale.x, textSize.y * spriteScale.y);
}