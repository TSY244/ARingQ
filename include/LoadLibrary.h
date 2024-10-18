//
// Created by au9u5t on 24-10-10.
//

#ifndef ARINGQUSEMAKEFILE_LOADLIBRARY_H
#define ARINGQUSEMAKEFILE_LOADLIBRARY_H

#include <windows.h>

#include <string>
#include <iostream>

namespace loadLibrary {
    using func = void (*)(const unsigned char *, const size_t &);
    using funcWithName = void (*)(const unsigned char *, const size_t &, const std::string &);

    using generateFunction = void (*)();

    func loadBase(const std::string &dllName, const std::string &functionName,
                  const unsigned char *decryptedData, const size_t &byteLength);

    funcWithName loadBase(const std::string &dllName, const std::string &functionName,
                          const unsigned char *decryptedData, const size_t &byteLength,
                          const std::string &name);


    bool runFuncFromDll(const std::string &dllName, const std::string &functionName,
                        const unsigned char *decryptedData, const size_t &byteLength,
                        const std::string &name);

    bool runFuncFromDll(const std::string &dllName, const std::string &functionName,
                        const unsigned char *decryptedData, const size_t &byteLength);

    void waitExit();
}

#endif //ARINGQUSEMAKEFILE_LOADLIBRARY_H
