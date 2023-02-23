#include "character.hpp"
#include "contants.hpp"

Character::Character(const std::string& name_, const std::string& role_):
    name{ name_ },
    role{ role_ }
{}

std::string Character::getIconLocation() const {
    return Constants::execFolder + "\\resources\\characters\\icons\\" + role + ".png";
}


//////////////////////


CharacterIconRender::CharacterIconRender() :
    icon{},
    border{} {
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::White);
    border.setOutlineThickness(2);
}

void CharacterIconRender::setPosition(const sf::Vector2f& pos) {
    border.setPosition(pos.x - 2, pos.y - 2);
    icon.setPosition(pos);
}

void CharacterIconRender::setCharacter(const Character& c) {
    icon.texturePath = c.getIconLocation();
    icon.setScale(0.25f);
    icon.load();

    sf::Vector2f iconSize = icon.getSize();
    border.setSize(sf::Vector2f(iconSize.x + 4, iconSize.y + 4));
}

void CharacterIconRender::render(sf::RenderWindow& rw) {
    rw.draw(border);
    icon.render(rw);
}

sf::Vector2f CharacterIconRender::getSize() {
    sf::Vector2f iconSize = icon.getSize();
    float borderTickness = border.getOutlineThickness();
    return sf::Vector2f(iconSize.x + 2 * borderTickness, iconSize.y + 2 * borderTickness);
}


//////////////////////


Character& Characters::getCharacterByRole(const std::string& role) {
    for (Character& c : characters) {
        if (c.role == role)
            return c;
    }

    return characters[0];
}

inline std::array<Character, 7> Characters::characters = std::array<Character, 7> { {
    Character("Sulphra", "alchemist"),
    Character("Myrin", "barmaid"),
    Character("Chove", "bartender"),
    Character("Gilus", "blacksmith"),
    Character("Sam", "farmer"),
    Character("Variane", "fisherman"),
    Character("Titouan", "kid01")
}};