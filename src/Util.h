#ifndef NETWORKINGFINAL_UTIL_H
#define NETWORKINGFINAL_UTIL_H

#include "PreProcessing.h"

// return length of string that has decayed to a pointer
// including null terminator
size_t lenCommandLineArg(const char* str);

void printCommandLineArgs(const Args* args);

#endif //NETWORKINGFINAL_UTIL_H
