//
// Created by au9u5t on 24-10-2.
//

#ifndef ARINGQUSEMAKEFILE_APCLOAD_H
#define ARINGQUSEMAKEFILE_APCLOAD_H

#include <mutex>
#include <string>
#include <iostream>

#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <thread>
#include "windows.h"
#include <vector>
#include <algorithm>
#include <TLHelp32.H>
using namespace std;

class __declspec(dllimport) MasterEncoderForApcLoadder;

class MasterEncoderForApcLoadder
{
public:
    static MasterEncoderForApcLoadder* getInstance();
    MasterEncoderForApcLoadder();
    ~MasterEncoderForApcLoadder();

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
    static bool stringCmp(char *a, std::string b);

private:
    static MasterEncoderForApcLoadder* _instance;
    static mutex _mtx;

    unsigned char _codeKey;
    char* _sign;
    int _signLen;

    unsigned char *decodePDF(const string &pdfPath, long &size);
};
#endif //ARINGQUSEMAKEFILE_APCLOAD_H
