#include "Util.h"

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

void printCommandLineArgs(const Args* args)
{
    printf("IP address: %s\n", args->ip);
    printf("Help: %d\n", args->help);

}
