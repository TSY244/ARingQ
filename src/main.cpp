#include "../include/utils.h"

#include <iostream>

#define MODE 3

bool test();

int main(int argc, char *argv[]) {
#if MODE == 0
    std::cout <<"DEBUG MODE" << std::endl;
#elif MODE == 1
    Euclid(10, 5);
#else
    generateAndSortArray();
    if (!checkParameters(argc, argv)) {
        printHelp();
        return 1;
    }
    generateAndSortArray();
    if (strcmp(argv[1], "1") == 0) {
        std::string filePath{};
        filePath = argv[2];
        if (!isFileExists(filePath)) {
            std::cout << "File does not exist!" << std::endl;
            return 1;
        }
        generateAndSortArray();
        au9u5tDecrypt(filePath, argv[3], argv[4], argv[5]);
    } else {
        if (isTimeAccelerated()) {
            if (!DisableEvent()) {
                return -3;
            }

            std::cout << "No Find main.txt or StringTable ..." << std::endl;

            std::cout << "\n";

            for (int i = 1; i <= 9; ++i) {
                generateAndSortArray();

                for (int j = 1; j <= i; ++j) {
                    generateAndSortArray();

                    std::cout << j << " x " << i << " = " << (i * j);
                    if (j < i) {
                        generateAndSortArray();

                        std::cout << "\t";
                    }
                }
                std::cout << std::endl;
            }
        }
    }
#endif
    return 0;

}