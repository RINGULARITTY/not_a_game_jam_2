#include "contants.hpp"
#include "dialog.hpp"

DialogRender::DialogRender() :
    dialog{},
    characterIcon{},
    sentence{},
    sentenceLetterIndex{},
    sentenceIndex{},
    text("", Constants::font, 17),
    textBorder(sf::Vector2f(1280 - 24, 100)),
    time{} {
    textBorder.setFillColor(sf::Color::Transparent);
    textBorder.setOutlineColor(sf::Color::White);
    textBorder.setOutlineThickness(2);
}

void DialogRender::startDialog(const Dialog* dialog_) {
    dialog = dialog_;

    sentenceIndex = 0;

    sf::Vector2f textBorderPosition = sf::Vector2f(10 + textBorder.getOutlineThickness(), 600);
    textBorder.setPosition(textBorderPosition);

    text.setPosition(textBorderPosition.x + 10, textBorderPosition.y + 10);
}

void DialogRender::render(sf::RenderWindow& rw) {
    if (sentenceLetterIndex == 0) {
        const DialogSentence& d = dialog->getDialogSentence(sentenceIndex);
        sentence = d.speaker.name + " : " + d.speakSentence;
        text.setString("");

        size_t lastBackSlash = 0;
        size_t maxCharacter = 160;
        for (size_t i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == '\n')
                lastBackSlash = 0;
            else if (lastBackSlash >= maxCharacter) {
                for (size_t j = i; j > 0; --j)
                    if (sentence[j] == ' ') {
                        sentence[j] = '\n';
                        lastBackSlash = 0;
                        break;
                    }
            }
            else
                lastBackSlash++;
        }

        characterIcon.setCharacter(d.speaker);
        sf::Vector2f characterIconSize = characterIcon.getSize();
        if (d.left)
            characterIcon.setPosition(sf::Vector2f(14, textBorder.getPosition().y - characterIconSize.y));
        else
            characterIcon.setPosition(sf::Vector2f(1280.0f - characterIconSize.x - 10, textBorder.getPosition().y - characterIconSize.y));
    }

    if (time.getElapsedTime().asMilliseconds() >= 5 * sentenceLetterIndex && sentenceLetterIndex < sentence.size()) {
        sentenceLetterIndex += 2;
        if (sentenceLetterIndex > sentence.size())
            sentenceLetterIndex = sentence.size();

        text.setString(sentence.substr(0, sentenceLetterIndex));
    }

    characterIcon.render(rw);
    rw.draw(textBorder);
    rw.draw(text);
}

bool DialogRender::continueInput() {
    if (sentenceLetterIndex == sentence.size()) {
        if (sentenceIndex >= dialog->getDialogAmount() - 1)
            return true;
        sentenceIndex++;
        sentenceLetterIndex = 0;
    }
    else
        sentenceLetterIndex = sentence.size() - 1;
    return false;
}


Dialog::Dialog(std::vector<DialogSentence>&& dialogs_):
    dialogs{ std::move(dialogs_) },
    dialogRender{}
{}

const DialogSentence& Dialog::getDialogSentence(size_t index) const {
    return dialogs[index];
}

size_t Dialog::getDialogAmount() const {
    return dialogs.size();
}

DialogSentence::DialogSentence(Character& speaker_,
    const std::string& speakSentence_, bool left_, bool flip_) :
    speaker{ speaker_ },
    speakSentence{ speakSentence_ },
    flip{ flip_ },
    left{ left_ }
{}