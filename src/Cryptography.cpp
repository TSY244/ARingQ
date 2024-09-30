//
// Created by au9u5t on 24-9-29.
//

#include <chrono>
#include <thread>
#include "Cryptography.h"


int Cryptography::generateKey() {
    // 生成1-10 之间的随机数
    int key = 0;
    key = std::rand() % 10 + 1;
    return key;
}

int Cryptography::decryptKey(const long long int &diff, const int &minValue, const int &maxValue, const int &lessThan,
                             const int &greaterThan) {
    for (auto num{minValue}; num <= maxValue; num++) {
        Confusion::generateAndSortArray();
        int randomValue = diff + num;
        Confusion::generateAndSortArray();
        if (lessThan < randomValue && randomValue < greaterThan) {
            return randomValue;
        }
    }
    return 0;
}

std::string Cryptography::x_o_r_EncryptDecrypt(const std::string &data, const std::string &key) {
    std::string output{};
    for (auto i{0}; i < data.size(); i++) {
        output += data[i] ^ key[i % key.size()];
    }
    return output;
}

bool Cryptography::useAes(const std::string &filePath, const std::string &key, const std::string &function_mode) {
        Confusion::generateAndSortArray();
        // AES encryption
        return true;
}

void Cryptography::Euclid(int num1, int num2) {
    std::vector<int> divisor{};
    std::vector<int> remainder{};
    divisor.emplace_back(num1);
    remainder.emplace_back(num2);
    while (num2) {
        std::cout << num1 << "=" << num1 / num2 << "*" << num2 << "+" << num1 % num2 << std::endl;
        int temp{0};
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
        remainder.emplace_back(num2);
        divisor.emplace_back(num1);
    }
    std::cout << divisor.back() << std::endl;
    divisor.pop_back();
    remainder.pop_back();
    int prea{0}; //用于存放上一个除数
    int preb{1};
    for (int i = divisor.size() - 1; i >= 0; --i) {
        if (divisor.empty() || remainder.empty()) {
            break;
        }
        std::cout << "  =" << divisor[i] << "*(" << prea << ")+" << remainder[i] << "*(" << preb << ")" << std::endl;
        int temp{prea};
        prea = preb;
        if (i > 0) {
            preb = temp - (static_cast<int>(divisor[i - 1] / remainder[i - 1])) * preb;
        }
    }
}
