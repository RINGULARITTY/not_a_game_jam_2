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
        DialogSentence(Characters::getCharacterByRole("alchemist"), "Les temps sont dûrs en ce moment, j'ai vraiment rien à dire c'est très grâve, mais je sais pas c'est plus fort que moi, j'arrive pas à m'arrêter, rien ni personne ne coupera cette discusion vraiment beaucoup trop longue. Tant que je serais vivant, je parlerais, alors fuit si tu ne veux plus m'entendre."),
        DialogSentence(Characters::getCharacterByRole("barmaid"), "Qui à demandé ?", false),
        DialogSentence(Characters::getCharacterByRole("bartender"), "C'est vrai qu'on s'ennuit", false),
        DialogSentence(Characters::getCharacterByRole("blacksmith"), "Hihihi !!"),
        DialogSentence(Characters::getCharacterByRole("farmer"), "Toujours aussi heureux le vieux à ce que je vois", false),
        DialogSentence(Characters::getCharacterByRole("fisherman"), "Chéri, arrête de te moquer de lui, il fait ce qu'il peut..."),
        DialogSentence(Characters::getCharacterByRole("kid01"), "Bon vous avez finis ? on a dit qu'on allait pêcher...", false)
    }});

    DialogRender dr;
    dr.startDialog(&d);

    int space = 0;
    bool stopDialog = false;

    sf::Event ev;
    while (rw.isOpen()) {
        while (rw.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                rw.close();
            if (ev.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && space == 0)
                    space = 1;
            }
            if (ev.type == sf::Event::KeyReleased) {
                if (ev.key.code == sf::Keyboard::Space && space == 2)
                    space = 0;
            }
        }

        if (space == 1) {
            space = 2;
            stopDialog = dr.continueInput();
        }

        rw.clear();
        if (!stopDialog)
            dr.render(rw);
        rw.display();
    }
}