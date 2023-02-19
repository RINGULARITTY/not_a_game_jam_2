#include "contants.hpp"
#include "dialog.hpp"

DialogRender::DialogRender() :
    dialog{},
    characterIcon{},
    sentence{},
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
    if (sentenceIndex == 0) {
        const DialogSentence& d = dialog->getDialogSentence(0);
        sentence = d.speaker.role + " : " + d.speakSentence;
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
        characterIcon.setPosition(sf::Vector2f(1280.0f - characterIconSize.x - 10, textBorder.getPosition().y - characterIconSize.y));
    }

    if (time.getElapsedTime().asMilliseconds() >= 5 * sentenceIndex && sentenceIndex < sentence.size()) {
        sentenceIndex += 2;
        if (sentenceIndex > sentence.size())
            sentenceIndex = sentence.size();

        text.setString(sentence.substr(0, sentenceIndex));
    }

    characterIcon.render(rw);
    rw.draw(textBorder);
    rw.draw(text);
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