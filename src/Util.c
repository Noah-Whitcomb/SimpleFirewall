#include "Util.h"

int acceptIP(Args* args, char* ip)
{
    for(size_t i = 0; i<args->ipListSize; i++)
    {
        if(strcmp(args->ipList[i], ip) == 0)
        {
            return  1;
        }
    }
    return 0;
}

//This actually isn't needed because fscanf is apparently a thing
int getIntFromFile(FILE* f)
{
    char arr[50];
    size_t size = 0;
    int c;
    do
    {
        c = fgetc(f);
        arr[size] = c;
        size++;
    } while(c != 0x20 && c != EOF);

    arr[size-1] = '\0';

    long int result;
    char * errorCheck;
    result = strtol(arr, &errorCheck, 10);
    if(*errorCheck != '\0')
    {
        return -100;
    }
    return result;
}

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

void printCommandLineArgs(const Args* args)
{
    printf("IP address: %s\n", args->ip);
    printf("Help: %d\n", args->help);
    printf("Accepted IP's: ");
    for(size_t i = 0; i<args->ipListSize; i++)
    {
        printf("%s ", args->ipList[i]);
    }
    printf("\n");

}
