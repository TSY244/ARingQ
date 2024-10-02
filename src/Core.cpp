//
// Created by au9u5t on 24-9-30.
//

#include "Core.h"
#include "utils.h"


int Core::start(int argc, char *argv[]) {
    if (this->mode == 0) {
        this->mode0Function();
    } else if (this->mode == 1) {
        this->mode1Function();
    } else if (this->mode == 2) {
        this->mode2Function();
    } else if (this->mode == 3) {
        this->mode3Function();
    } else if (this->mode == 4) {
        this->mode4Function(argc, argv);
    } else {
        std::cout << "Invalid mode" << std::endl;
    }
    return 0;
}

void Core::setMode(int m) {
    this->mode = m;
}

int Core::getMode() {
    return this->mode;
}

void Core::mode1Function() {
    Cryptography::Euclid(10, 5);
}

void Core::mode0Function() {
    std::cout << "DEBUG MODE" << std::endl;
}

void Core::mode3Function() {
    if (util::isTimeAccelerated()) {
        if (!util::DisableEvent()) {
            return;
        }

        std::cout << "No Find main.txt or StringTable ..." << std::endl;

        std::cout << "\n";

        for (int i = 1; i <= 9; ++i) {
            Confusion::generateAndSortArray();

            for (int j = 1; j <= i; ++j) {
                Confusion::generateAndSortArray();

                std::cout << j << " x " << i << " = " << (i * j);
                if (j < i) {
                    Confusion::generateAndSortArray();

                    std::cout << "\t";
                }
            }
            std::cout << std::endl;
        }
    }
}

void Core::mode2Function() {
    Confusion::generateAndSortArray();
}

void Core::mode4Function(int argc, char **argv) {
    Confusion::generateAndSortArray();
    if (!checkParameter(argc, argv)) {
        Parameter::printHelp();
        return;
    }

    Confusion::generateAndSortArray();
    switch (this->getOperation(argv)) {
        case 1: {
            this->option1(argc, argv);
            break;
        }
        default: {
            this->defaultOption(argc, argv);
            break;
        }
    }
}

bool Core::checkParameter(int argc, char **argv) {
    if (!Parameter::checkParameters(argc, argv)) {
        return false;
    }
    return true;
}

int Core::getOperation(char *argv[]) {
    if (strcmp(argv[1], "1") == 0) {
        return 1;
    } else {
        return 0;
    }
}

void Core::option1(int argc, char **argv) {
    if (!this->analyzeOpt1Parameters(argc, argv)) {
        Parameter::printHelp();
        return;
    }
    Confusion::generateAndSortArray();
    this->initLaunch(this->filePath, this->encryptionMethod, this->key, this->functionMode, this->cycles);
    this->launch->au9u5tDecrypt();
}

void Core::defaultOption(int argc, char **argv) {
    if (util::isTimeAccelerated()) {
        if (!util::DisableEvent()) {
            return;
        }

        std::cout << "No Find main.txt or StringTable ..." << std::endl;

        std::cout << "\n";

        for (int i = 1; i <= 9; ++i) {
            Confusion::generateAndSortArray();

            for (int j = 1; j <= i; ++j) {
                Confusion::generateAndSortArray();

                std::cout << j << " x " << i << " = " << (i * j);
                if (j < i) {
                    Confusion::generateAndSortArray();

                    std::cout << "\t";
                }
            }
            std::cout << std::endl;
        }
    } else {
        Confusion::generateAndSortArray();
    }
}

void
Core::initLaunch(std::string &filePath, std::string &method, std::string &key, std::string &function_mode, int cycles) {
    this->launch = new Launch(filePath, method, key, function_mode);
    this->launch->setCycles(cycles);
}

Core::Core(string &filePath, string &method, string &key, string &function_mode, int cycles) {
    this->initLaunch(filePath, method, key, function_mode, cycles);
}

bool Core::analyzeOpt1Parameters(int argc, char **argv) {
    this->filePath = argv[2];
    if (!File::isFileExists(this->filePath)) {
        std::cout << "File does not exist!" << std::endl;
        return false;
    }

    this->encryptionMethod = argv[3];
    this->key = argv[4];
    this->functionMode = argv[5];

    return true;
}
