//
// Created by au9u5t on 24-9-29.
//

#ifndef ARINGQUSEMAKEFILE_PARAMETER_H
#define ARINGQUSEMAKEFILE_PARAMETER_H


#include <iostream>

#include "File.h"


class Parameter {
public:
    static void printHelp();
    static bool checkParameters(int argc, char *argv[]);
};


#endif //ARINGQUSEMAKEFILE_PARAMETER_H
