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

void SpriteWrapper::render(sf::RenderWindow& rw) {
    rw.draw(sprite);
}