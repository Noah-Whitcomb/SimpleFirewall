#ifndef NETWORKINGFINAL_STRUCTS_H
#define NETWORKINGFINAL_STRUCTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    FILE* accList;
    FILE* logFile;
    char* ip;
    size_t help; // 0 means no help, 1 means help
    size_t rangeOrList; // 0 means range, 1 means list
}Args;

void freeArgs(Args* args);

#endif //NETWORKINGFINAL_STRUCTS_H
