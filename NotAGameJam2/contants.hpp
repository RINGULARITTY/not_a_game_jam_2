#pragma once

#include <string>

class Constants {
public:
    static void setExecFolderWithArgv(const std::string& execPath) {
        for (int i = execPath.size(); i >= 0; --i) {
            if (execPath[i] == '\\') {
                execFolder = execPath.substr(0, i + 1);
                break;
            }
        }
    }

    static std::string execFolder;
};

inline std::string Constants::execFolder{};