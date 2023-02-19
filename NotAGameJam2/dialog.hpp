#pragma once

#include "character.hpp"
#include "spriteWrapper.hpp"
#include "renderElement.hpp"

#include <vector>
#include <string>
#include <SFML/Graphics/Text.hpp>


class DialogRender;
class Dialog;
class DialogSentence;

class DialogRender: RenderElement {
public:
    DialogRender();

    void startDialog(const Dialog* dialog_);

    void render(sf::RenderWindow& rw);

private:
    const Dialog* dialog;
    CharacterIconRender characterIcon;
    std::string sentence;
    size_t sentenceIndex;
    sf::Text text;
    sf::RectangleShape textBorder;
    sf::Clock time;
};


class Dialog {
public:
    Dialog(std::vector<DialogSentence>&& dialogs_);

    const DialogSentence& getDialogSentence(size_t index) const;

private:
    std::vector<DialogSentence> dialogs;
    DialogRender dialogRender;
};


class DialogSentence {
public:
    DialogSentence(Character& speaker_,
        const std::string& speakSentence_, bool flip_ = false);

    bool flip;
    Character& speaker;
    std::string speakSentence;
};