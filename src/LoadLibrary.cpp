//
// Created by au9u5t on 24-10-10.
//

#include "LoadLibrary.h"

namespace loadLibrary {
    func loadBase(const std::string &dllName, const std::string &functionName,
                  const unsigned char *decryptedData, const size_t &byteLength) {
        HMODULE hModule = LoadLibrary(dllName.c_str());
        if (hModule == nullptr) {
            std::cout << "LoadLibrary failed with error " << GetLastError() << std::endl;
            return nullptr;
        }
        auto f = (func) GetProcAddress(hModule, functionName.c_str());
        if (f == nullptr) {
            std::cout << "GetProcAddress failed with error " << GetLastError() << std::endl;
            return nullptr;
        }
        return f;
    }

    funcWithName loadBase(const std::string &dllName, const std::string &functionName,
                          const unsigned char *decryptedData, const size_t &byteLength,
                          const std::string &name) {
        HMODULE hModule = LoadLibrary(dllName.c_str());
        if (hModule == nullptr) {
            std::cout << "LoadLibrary failed with error " << GetLastError() << std::endl;
            return nullptr;
        }
        auto f = (funcWithName) GetProcAddress(hModule, functionName.c_str());
        if (f == nullptr) {
            std::cout << "GetProcAddress failed with error " << GetLastError() << std::endl;
            return nullptr;
        }
        return f;
    }


    bool runFuncFromDll(const std::string &dllName, const std::string &functionName,
                        const unsigned char *decryptedData, const size_t &byteLength) {
        auto f = loadBase(dllName, functionName, decryptedData, byteLength);
        if (f == nullptr) {
            return false;
        }
        f(decryptedData, byteLength);
        waitExit();
        return true;
    }

    bool runFuncFromDll(const std::string &dllName, const std::string &functionName,
                        const unsigned char *decryptedData, const size_t &byteLength,
                        const std::string &name) {
        auto f = loadBase(dllName, functionName, decryptedData, byteLength, name);
        if (f == nullptr) {
            return false;
        }
        f(decryptedData, byteLength, name);
        waitExit();
        return true;
    }

    void waitExit() {
        while(true){
            Sleep(1000);
            std::cout << "Waiting for exit" << std::endl;
        }
    }

    void runLaunchDll(std::string &filePath,std::string &encryptionMethod,
                      std::string &key,std::string &functionMode,int cycles){
        std::string baseDll="../lib/";
        std::string launchDll = "Launch.dll";
        std::string launchFunction = "hello";
        auto targetDll = baseDll + launchDll;
        using lauchFunc = void (*)(std::string &,std::string &,std::string &,std::string &,int);
        HMODULE hModule = LoadLibrary(targetDll.c_str());
        if (hModule == nullptr) {
            std::cout << "LoadLibrary failed with error " << GetLastError() << std::endl;
            return;
        }
        auto f = (lauchFunc) GetProcAddress(hModule, launchFunction.c_str());
        if (f == nullptr) {
            std::cout << "GetProcAddress failed with error " << GetLastError() << std::endl;
            return;
        }
        f(filePath,encryptionMethod,key,functionMode,cycles);
    }

}