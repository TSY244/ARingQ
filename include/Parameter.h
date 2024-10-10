//
// Created by au9u5t on 24-9-29.
//

#ifndef ARINGQUSEMAKEFILE_PARAMETER_H
#define ARINGQUSEMAKEFILE_PARAMETER_H


#include <iostream>
#include <cstring>
#include "File.h"

namespace Parameter {
    void printHelp();

    bool checkParameters(int argc, char *argv[]);

    class parameter {
    public:
        bool checkParameterNumber(int argc, int number) {
            if (argc == number) {
                return true;
            }
            return false;
        }

        bool isHasParameter(int argc) {
            if (argc == 1) {
                return false;
            }
            return true;
        };

        bool checkOperation(char *argv[], int operation) {
            if (strcmp(argv[1], std::to_string(operation).c_str()) == 0) {
                return true;
            }
            return false;
        };

        int getOperation(char *mode) {
            if(strcmp(mode, "1") == 0) {
                return 1;
            } else {
                return 0;
            }
        };

        bool checkFileExistence(std::string filePath) {
            if (!File::isFileExists(filePath)) {
                return false;
            }
            return true;
        };

        bool checkFunctionMode(std::string functionMode) {
            int mode = std::stoi(functionMode);
            if (mode<=0 || mode>14) {
                return false;
            }
            return true;
        };

        bool checkEncryptionMethod(int argc, char *argv[]) {
            std::string encryptionMethod = argv[3];
            if (encryptionMethod == "6N_XOR") {
                std::string key = argv[4];
                if (key.length() != 6) {
                    std::cout << "Key must be 6 characters long!" << std::endl;
                    return false;
                }
            } else if (encryptionMethod == "file_XOR") {
                std::string key = argv[4];
                if (!File::isFileExists(key)) {
                    std::cout << "Key file does not exist!" << std::endl;
                    return false;
                }
            } else {
                std::cout << "Invalid encryption method!" << std::endl;
                return false;
            }
            return true;
        };

        bool checkOpt1(int argc, char *argv[]) {
            if (checkParameterNumber(argc, 6)) {
                std::string filePath{argv[2]};
                if (!checkFileExistence(filePath)) {
                    std::cout << "File does not exist!" << std::endl;
                    return false;
                }

                if (!checkEncryptionMethod(argc, argv)) {
                    std::cout << "Invalid encryption method!" << std::endl;
                    return false;
                }

                std::string functionMode = argv[5];
                if (!checkFunctionMode(functionMode)) {
                    std::cout << "Invalid func mode!" << std::endl;

                    return false;
                }

                return true;
            }

            return false;
        };
    };
}

#endif //ARINGQUSEMAKEFILE_PARAMETER_H
