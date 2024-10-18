//
// Created by au9u5t on 24-9-30.
//

#include "File.h"

bool File::isFileExists(const std::string &filePath) {
    std::ifstream file(filePath);
    return file.good();
}
