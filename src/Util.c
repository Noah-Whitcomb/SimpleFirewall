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

void printCommandLineArgs(const Args* args)
{
    printf("Access control list: %s\n", args->accessControlList);
    printf("Log file: %s\n", args->logFile);
    printf("IP address: %s\n", args->ip);
    printf("Help: %d\n", args->help);

}
