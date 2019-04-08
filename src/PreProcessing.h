#ifndef NETWORKINGFINAL_PREPROCESSING_H
#define NETWORKINGFINAL_PREPROCESSING_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "Util.h"

void runOneArg();
void runBadArgs(int badFile, int badArgs);
void runHelp();
Args* verifyArgs(int argc, char** argv);

#endif //NETWORKINGFINAL_PREPROCESSING_H
