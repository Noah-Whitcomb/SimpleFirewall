#ifndef NETWORKINGFINAL_SERVER_H
#define NETWORKINGFINAL_SERVER_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "Util.h"

typedef struct
{
    char* accessControlList;
    char* logFile;
    char* ip;
    int help; // 0 means no help, 1 means help
}Args;

void runOneArg();
void runHelp();
Args* verifyArgs(int argc, char** argv);

#endif //NETWORKINGFINAL_SERVER_H
