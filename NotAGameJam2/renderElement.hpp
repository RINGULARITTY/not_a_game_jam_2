#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class RenderElement {
protected:
    virtual void render(sf::RenderWindow& rw) = 0;
};