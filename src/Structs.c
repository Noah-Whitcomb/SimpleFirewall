#include "Structs.h"

void freeArgs(Args* args)
{
    free(args->ip);
    //free(args->portList);
    fclose(args->accList);
    fclose(args->logFile);
    for(size_t i = 0; i<args->ipListSize; i++)
    {
        free(args->ipList[i]);
    }
    free(args->ipList);
    free(args);
}

void setDefaultValues(Args* args)
{
    args->help = 0;
//    args->rangeOrList = -100;
//    args->portLowBound = -100;
//    args->portUpBound = -100;
//    args->portListSize = -100;
}
