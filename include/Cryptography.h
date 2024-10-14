//
// Created by au9u5t on 24-9-29.
//

#ifndef ARINGQUSEMAKEFILE_CRYPTOGRAPHY_H
#define ARINGQUSEMAKEFILE_CRYPTOGRAPHY_H

#include <string>
#include <iostream>
#include <fstream>

#include "Confusion.h"


class Cryptography {

public:

    static int generateKey();
    static int decryptKey(const long long int &diff, const int &minValue, const int &maxValue,
                          const int &lessThan, const int &greaterThan);
    static std::string x_o_r_EncryptDecrypt(const std::string &data, const std::string &key);
    static bool useAes(const std::string &filePath, const std::string &key, const std::string &function_mode);

    static void Euclid(int num1, int num2);

};




#endif //ARINGQUSEMAKEFILE_CRYPTOGRAPHY_H
