#include "Util.h"

size_t lenCommandLineArg(char* str)
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
