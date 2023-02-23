#pragma once

#include "renderElement.hpp"
#include "spriteWrapper.hpp"

#include <string>
#include <array>
#include <optional>
#include <SFML/Graphics/RectangleShape.hpp>

class Character {
public:
    Character(const std::string& name_, const std::string& role_);

    std::string getIconLocation() const;

    std::string name, role;
};

class CharacterIconRender : RenderElement {
public:
    CharacterIconRender();
    void setPosition(const sf::Vector2f& pos);
    void setCharacter(const Character& c);

    void render(sf::RenderWindow& rw);

    sf::Vector2f getSize();

private:
    sf::RectangleShape border;
    SpriteWrapper icon;
};

class Characters {
public:
    static Character& getCharacterByRole(const std::string& role);

private:
    static std::array<Character, 7> characters;
};