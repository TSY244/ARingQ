//
// Created by au9u5t on 24-10-6.
//

#ifndef ARINGQUSEMAKEFILE_EARLYBIRDAPC_INJETCLOAD_H
#define ARINGQUSEMAKEFILE_EARLYBIRDAPC_INJETCLOAD_H



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

using namespace std;

class __declspec(dllimport) MasterEncoderForEarlyBirdAPC_InjetcLoad;

class MasterEncoderForEarlyBirdAPC_InjetcLoad
{
public:
    static MasterEncoderForEarlyBirdAPC_InjetcLoad* getInstance();
    MasterEncoderForEarlyBirdAPC_InjetcLoad();
    ~MasterEncoderForEarlyBirdAPC_InjetcLoad();

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

private:
    static MasterEncoderForEarlyBirdAPC_InjetcLoad* _instance;
    static mutex _mtx;

    unsigned char _codeKey;
    char* _sign;
    int _signLen;

    unsigned char *decodePDF(const string &pdfPath, long &size);
};

#endif //ARINGQUSEMAKEFILE_EARLYBIRDAPC_INJETCLOAD_H
