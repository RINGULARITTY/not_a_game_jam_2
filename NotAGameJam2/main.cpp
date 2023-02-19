#include "dialog.hpp"
#include "contants.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char** argv) {
    Constants::loadAllRessources(argv[0]);
    std::cout << Constants::execFolder;

    sf::RenderWindow rw(sf::VideoMode(1280, 720), "test");
    rw.setFramerateLimit(30);


    Dialog d(std::vector<DialogSentence> {{
        DialogSentence(Characters::getCharacterByRole("alchemist"), "Les temps sont dûrs en ce moment, j'ai vraiment rien à dire c'est très grâve, mais je sais pas c'est plus fort que moi, j'arrive pas à m'arrêter, rien ni personne ne coupera cette discusion vraiment beaucoup trop longue. Tant que je serais vivant, je parlerais, alors fuit si tu ne veux plus m'entendre.")
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