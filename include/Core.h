//
// Created by au9u5t on 24-9-30.
//

#ifndef ARINGQUSEMAKEFILE_CORE_H
#define ARINGQUSEMAKEFILE_CORE_H

#include <iostream>
#include "Cryptography.h"
#include "Parameter.h"
#include "Launch.h"

class Core {
private:
    int mode = 0;
    Launch *launch{nullptr};
private:
    void mode0Function();

    void mode1Function();

    void mode2Function();

    void mode3Function();

    void mode4Function(int argc, char *argv[]);

    bool checkParameter(int argc, char *argv[]);

    int getOperation(char *argv[]);

    void option1(int argc, char *argv[]);

    void defaultOption(int argc, char *argv[]);

public:
    explicit Core(int mode) : mode(mode) {
    }

    ~Core() = default;

public:

    void setMode(int m);

    int getMode();

    int start(int argc, char *argv[]);

    void initLaunch(std::string &filePath, std::string &method, std::string &key, std::string &function_mode, int cycles) ;
};


#endif //ARINGQUSEMAKEFILE_CORE_H
