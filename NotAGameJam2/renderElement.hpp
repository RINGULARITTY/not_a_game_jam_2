#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class RenderElement {
protected:
    RenderElement() = default;

    virtual void render(sf::RenderWindow& rw) = 0;
};