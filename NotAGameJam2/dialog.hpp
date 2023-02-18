#pragma once

#include "character.hpp"
#include "spriteWrapper.hpp"
#include "renderElement.hpp"

#include <vector>
#include <string>


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