#include "character.hpp"
#include "contants.hpp"

Character::Character(const std::string& name_, const std::string& role_):
    name{ name_ },
    role{ role_ }
{}

std::string Character::getIconLocation() const {
    return Constants::execFolder + "\\resources\\characters\\icons\\" + role + ".png";
}


CharacterIconRender::CharacterIconRender() :
    icon{} {}

void CharacterIconRender::setCharacter(const Character& c) {
    icon.texturePath = c.getIconLocation();
    icon.load();
}

void CharacterIconRender::render(sf::RenderWindow& rw) {
    icon.render(rw);
}


Character& Characters::getCharacterByRole(const std::string& role) {
    for (Character& c : characters) {
        if (c.role == role)
            return c;
    }

    return characters[0];
}

inline std::array<Character, 1> Characters::characters = std::array<Character, 1> { {
    Character("Kappa", "alchemist")
}};