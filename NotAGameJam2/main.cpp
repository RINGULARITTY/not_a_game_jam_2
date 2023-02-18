#include "dialog.hpp"
#include "contants.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char** argv) {
    Constants::setExecFolderWithArgv(argv[0]);
    std::cout << Constants::execFolder;

    sf::RenderWindow rw(sf::VideoMode(1280, 720), "test");
    rw.setFramerateLimit(30);


    Dialog d(std::vector<DialogSentence> {{
        DialogSentence(Characters::getCharacterByRole("alchemist"), "Salut à tous")
    }});

    DialogRender dr;
    dr.startDialog(&d);

    sf::Event ev;
    while (rw.isOpen()) {
        while (rw.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                rw.close();
        }

        rw.clear();
        dr.render(rw);
        rw.display();
    }
}