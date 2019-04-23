#ifndef NETWORKINGFINAL_UTIL_H
#define NETWORKINGFINAL_UTIL_H

#include "Structs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getIntFromFile(FILE* f);

void printCommandLineArgs(const Args* args);

//return 1 if ip accepted, 0 if not
int acceptIP(Args* args, char* ip);

void freeArgs(Args* args);
void setDefaultValues(Args* args);

#endif //NETWORKINGFINAL_UTIL_H
