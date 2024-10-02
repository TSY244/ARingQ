//
// Created by au9u5t on 24-9-29.
//

#include <cstring>
#include "Parameter.h"


void Parameter::printHelp() {
    std::cout << "Usage: tool [opt] " << std::endl;
    std::cout << "for example: tool 1 [filepath] [EncryptionMethod] [Key] [function_mode]" << std::endl;
    std::cout << "             filepath: path to the file" << std::endl;
    std::cout << "             EncryptionMethod: 6N_XOR,file_XOR" << std::endl;
    std::cout << "                               6N_XOR: 6-digit number XOR Key" << std::endl;
    std::cout << "                               file_XOR: XOR Key from file" << std::endl;
    std::cout << "             Key: 6 characters XOR Key or path to the key file" << std::endl;
    std::cout << "             function_mode: 1 means function1 to use directlyLoad" << std::endl;
    std::cout << "                            2 means function2 to use apcLoad" << std::endl;
    std::cout << "                            3 means function3 to use ThreatPoolWait" << std::endl;
}

bool Parameter::checkParameters(int argc, char **argv) {
    parameter p{};
    if (!p.isHasParameter(argc)) {
        return false;
    }
    switch (p.getOperation(argv[1])) {
        case 1: {
            return p.checkOpt1(argc, argv);
        }
        default: {
            return false;
        }

    }

//    auto strMode = argv[1];
//    if (strcmp(strMode, "1") == 0) {
//
//
//        if (argc != 6) {
//            // printHelp();
//            std::cout << "argv length: " << argc << std::endl;
//            return false;
//        }
//        std::string filePath{argv[2]};
//        if (!File::isFileExists(filePath)) {
//            std::cout << "File does not exist!" << std::endl;
//            return false;
//        }
//
//        std::string encryptionMethod = argv[3];
//        if (encryptionMethod == "6N_XOR") {
//            std::string key = argv[4];
//            if (key.length() != 6) {
//                std::cout << "Key must be 6 characters long!" << std::endl;
//                return false;
//            }
//        } else if (encryptionMethod == "file_XOR") {
//            std::string key = argv[4];
//            if (!File::isFileExists(key)) {
//                std::cout << "Key file does not exist!" << std::endl;
//                return false;
//            }
//        } else {
//            // printHelp();
//            std::cout << "Invalid encryption method!" << std::endl;
//            return false;
//        }
//        std::string functionMode = argv[5];
//        if (functionMode != "1") {
//            // printHelp();
//            return false;
//        }
//    } else {
//        // printHelp();
//        return false;
//    }
//    return true;
}
