#include "dialog.hpp"

DialogRender::DialogRender():
    dialog{},
    characterIcon{}
{}

void DialogRender::startDialog(const Dialog* dialog_) {
    dialog = dialog_;
}

void DialogRender::render(sf::RenderWindow& rw) {
    characterIcon.setCharacter(dialog->getDialogSentence(0).speaker);
    characterIcon.render(rw);
}


Dialog::Dialog(std::vector<DialogSentence>&& dialogs_):
    dialogs{ std::move(dialogs_) },
    dialogRender{}
{}

const DialogSentence& Dialog::getDialogSentence(size_t index) const {
    return dialogs[index];
}

DialogSentence::DialogSentence(Character& speaker_,
    const std::string& speakSentence_, bool flip_) :
    speaker{ speaker_ },
    speakSentence{ speakSentence_ },
    flip{ flip_ }
{}