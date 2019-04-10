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
int parseAccList(Args* args, FILE* f);
int parseRange(Args* args, FILE* f);
int parseList(Args* args, FILE* f);
Args* verifyArgs(int argc, char** argv);
void getArgs(Args* args, int argc, char** argv, int *badFile, int* badArgs);

#endif //NETWORKINGFINAL_PREPROCESSING_H
