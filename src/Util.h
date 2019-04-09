#ifndef NETWORKINGFINAL_UTIL_H
#define NETWORKINGFINAL_UTIL_H

#include "Structs.h"
#include <stdlib.h>
#include <stdio.h>

// return length of string that has decayed to a pointer
// including null terminator
int getIntFromFile(FILE* f);

void printCommandLineArgs(const Args* args);

#endif //NETWORKINGFINAL_UTIL_H
