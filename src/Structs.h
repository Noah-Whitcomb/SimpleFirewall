#ifndef NETWORKINGFINAL_STRUCTS_H
#define NETWORKINGFINAL_STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    FILE* accList;
    FILE* logFile;
    char* ip;
    int help; // 0 means no help, 1 means help
    char** ipList; // list of accepted IP's
    int ipListSize;

//    int rangeOrList; // 0 means range, 1 means list
//    int portLowBound; //lower bound of port range
//    int portUpBound; // upper bound of port range
//    int* portList; // array of accepted ports
//    int portListSize;
}Args;

void freeArgs(Args* args);
void setDefaultValues(Args* args);

#endif //NETWORKINGFINAL_STRUCTS_H
