//
// Created by au9u5t on 24-9-30.
//

#ifndef ARINGQUSEMAKEFILE_CORE_H
#define ARINGQUSEMAKEFILE_CORE_H

#include <iostream>
#include <vector>
#include "Parameter.h"
#include "LoadLibrary.h"


class Core {
private:
    const int cycles = 1000;
private:
    int mode = 0;
    std::string filePath{};
    std::string encryptionMethod{};
    std::string key{};
    std::string functionMode{};

//    Launch *launch{nullptr};
private:
    void mode0Function();

    void mode1Function();

    void mode2Function();

    void mode3Function();

    void mode4Function(int argc, char *argv[]);

    int checkParameter(int argc, char *argv[]);

    int getOperation(char *argv[]);

    void option1(int argc, char *argv[]);

    void defaultOption(int argc, char *argv[]);

    bool analyzeOpt1Parameters(int argc, char *argv[]);
    bool analyzeOpt2Parameters(int argc,std::vector<std::string> &argv);

    void launchFunction();

    void loadApplication();

public:
    explicit Core(int mode) : mode(mode) {
    }

    Core(std::string &filePath, std::string &method, std::string &key, std::string &function_mode, int cycles);

    ~Core() = default;

public:



    void getParameterFromFile(int argc, std::vector<std::string> &argv);

    void setMode(int m);

    int getMode();

    int start(int argc, char *argv[]);

//    void initLaunch(std::string &filePath, std::string &method, std::string &key, std::string &function_mode, int cycles) ;
};


#endif //ARINGQUSEMAKEFILE_CORE_H
