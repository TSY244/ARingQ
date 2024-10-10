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


namespace augustEncryption
{

    const std::string custom_base64_chars =
            "!@#$%^&*()-_=+"
            "[]{};:'\",.<>/?"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    std::vector<int> create_reverse_custom_base64_lookup()
    {
        std::vector<int> reverse_custom_base64_lookup(256, -1); // 默认值为-1，表示无效字符
        for (size_t i = 0; i < custom_base64_chars.size(); ++i)
        {
            reverse_custom_base64_lookup[static_cast<unsigned char>(custom_base64_chars[i])] = i;
        }
        return reverse_custom_base64_lookup;
    }

    std::string encode(const std::string &input)
    {
        static const std::vector<int> reverse_custom_base64_lookup = create_reverse_custom_base64_lookup();
        std::string encoded;
        int val = 0, valb = -6;
        for (unsigned char c : input)
        {
            val = (val << 8) + c;
            valb += 8;
            while (valb >= 0)
            {
                encoded.push_back(custom_base64_chars[(val >> valb) & 0x3F]);
                valb -= 6;
            }
        }
        if (valb > -6)
        {
            encoded.push_back(custom_base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
            if (encoded.size() % 4 == 3)
            {
                encoded.push_back('!');
            }
            else if (encoded.size() % 4 == 2)
            {
                encoded.push_back('!');
                encoded.push_back('|');
            }
        }
        return encoded;
    }

    std::string decode(const std::string &encoded)
    {
        static const std::vector<int> reverse_custom_base64_lookup = create_reverse_custom_base64_lookup();
        std::string decoded;
        int val = 0, valb = -8;
        for (unsigned char c : encoded)
        {
            if (c == '!' || c == '|')
                break;
            int index = reverse_custom_base64_lookup[c];
            if (index == -1)
                break;
            val = (val << 6) + index;
            valb += 6;
            if (valb >= 0)
            {
                decoded.push_back(char((val >> valb) & 0xFF));
                valb -= 8;
            }
        }
        return decoded;
    }

}

#endif //ARINGQUSEMAKEFILE_CRYPTOGRAPHY_H
