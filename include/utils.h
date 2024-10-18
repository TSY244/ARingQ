
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <windows.h>

#include "Cryptography.h"
#include "Confusion.h"

namespace util
{
    bool isTimeAccelerated();

    BOOL DisableEvent();

    std::string generateRandomString(const int &length);

    std::string wstringToString(const std::wstring &wstr);

    std::wstring stringToWstring(const std::string &str);


}