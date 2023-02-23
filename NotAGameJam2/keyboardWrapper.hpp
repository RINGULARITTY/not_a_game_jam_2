#pragma once

#include <map>
#include <vector>
#include <optional>

class KeyWrapper;

class KeyboardWrapper {
public:
    KeyboardWrapper();

    void addKey(int keyCode, bool pressKey);
    void addKeys(const std::vector<std::pair<int, bool>>& keys);

    void pressedInput(int keyCode);
    void releasedInput(int keyCode);

    std::optional<KeyWrapper*> getKeyWrapper(int keyCode);
    void printStatus(bool clearConsole = true);

    void clearKeys();

private:
    std::map<int, KeyWrapper> keys;
};


class KeyWrapper {
public:
    enum class KeyStatus {
        IDLE = 0,
        PRESSED = 1
    };

    // pressKey = false to increment counter only if released
    KeyWrapper(bool pressKey_);

    void pressedInput();
    void releasedInput();

    int consumeCounter(int amount);
    int consumeAllCounter();

    int getCounter() const;
    const KeyStatus& getStatus() const;

    bool pressKey;
private:
    int counter;
    KeyStatus keyStatus;
};