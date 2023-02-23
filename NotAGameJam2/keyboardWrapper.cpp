#include "keyboardWrapper.hpp"

#include <iostream>
#include <string>

KeyboardWrapper::KeyboardWrapper():
    keys{}
{}

void KeyboardWrapper::addKey(int keyCode, bool pressKey) {
    keys.emplace(keyCode, pressKey);
}

void KeyboardWrapper::addKeys(const std::vector<std::pair<int, bool>>& keys) {
    for (auto& key : keys)
        addKey(key.first, key.second);
}

void KeyboardWrapper::pressedInput(int keyCode) {
    const auto& it = keys.find(keyCode);
    if (it == keys.end())
        return;

    it->second.pressedInput();
}

void KeyboardWrapper::releasedInput(int keyCode) {
    const auto& it = keys.find(keyCode);
    if (it == keys.end())
        return;

    it->second.releasedInput();
}

std::optional<KeyWrapper*> KeyboardWrapper::getKeyWrapper(int keyCode) {
    const auto& it = keys.find(keyCode);
    if (it == keys.end())
        return std::nullopt;

    return std::optional<KeyWrapper*>{&it->second};
}

void KeyboardWrapper::printStatus(bool clearConsole) {
    system("cls");
    for (const auto& [keyCode, status] : keys) {
        std::cout << std::to_string(keyCode) + " : {\n";
        std::cout << "\tkeyType : ";
        if (status.pressKey)
            std::cout << "press";
        else
            std::cout << "released";
        std::cout << ",\n";
        std::cout << "\tcounter : " + std::to_string(status.getCounter()) + ",\n";
        std::cout << "\tkeyStatus : ";
        if (status.getStatus() == KeyWrapper::KeyStatus::IDLE)
            std::cout << "idle";
        else
            std::cout << "pressed";
        std::cout << "\n}\n";
    }
}

void KeyboardWrapper::clearKeys() {
    keys.clear();
}

/////////////////////

KeyWrapper::KeyWrapper(bool pressKey_):
    pressKey{ pressKey_ },
    counter{},
    keyStatus{ KeyStatus::IDLE }
{}

void KeyWrapper::pressedInput() {
    if (keyStatus == KeyStatus::IDLE)
        keyStatus = KeyStatus::PRESSED;
    else if (pressKey)
        counter++;
}

void KeyWrapper::releasedInput() {
    if (keyStatus == KeyStatus::PRESSED && !pressKey)
        counter++;
    keyStatus = KeyStatus::IDLE;
}

int KeyWrapper::consumeCounter(int amount) {
    int res = counter - amount;
    if (res < 0) {
        counter = 0;
        return counter;
    }

    counter = res;
    return amount;
}

int KeyWrapper::consumeAllCounter() {
    int res = counter;
    counter = 0;
    return res;
}

int KeyWrapper::getCounter() const {
    return counter;
}

const KeyWrapper::KeyStatus& KeyWrapper::getStatus() const {
    return keyStatus;
}