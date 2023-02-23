#pragma once

#include <string>
#include <SFML/Graphics/Font.hpp>

class Constants {
public:
    static void loadAllRessources(const std::string& execPath) {
        for (size_t i = execPath.size(); i > 0; --i) {
            if (execPath[i] == '\\') {
                execFolder = execPath.substr(0, i + 1);
                break;
            }
        }

        font.loadFromFile(execFolder + "resources\\fonts\\main.ttf");
        const_cast<sf::Texture&>(font.getTexture(17)).setSmooth(false);
    }

    static std::string execFolder;
    static sf::Font font;
};

inline std::string Constants::execFolder{};
inline sf::Font Constants::font{};