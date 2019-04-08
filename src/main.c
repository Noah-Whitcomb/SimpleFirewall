//#include <stdio.h>
#include "PreProcessing.h"
#include "Util.h"
#include "Server.h"

int main(int argc, char** argv)
{
    Args * args = verifyArgs(argc, argv);

    if(args == NULL)
    {
        return 0;
    }

    printCommandLineArgs(args);
    return 0;
}