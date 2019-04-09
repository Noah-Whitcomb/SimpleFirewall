#include "Util.h"

size_t lenCommandLineArg(const char* arg)
{
    size_t i = 0;
    char currentChar = arg[i];

    while(currentChar != '\0')
    {
        i++;
        currentChar = arg[i];
    }

    i++;
    return i;
}

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

    arr[size] = '\0';

    long int result;
    char * errorCheck;
    result = strtol(arr, &errorCheck, 10);
    if(*errorCheck != 0x20 && *errorCheck != '\0')
    {
        return -100;
    }
    return result;

}

void printCommandLineArgs(const Args* args)
{
    printf("IP address: %s\n", args->ip);
    printf("Help: %d\n", args->help);

}
