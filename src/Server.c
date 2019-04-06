#include "Server.h"

Args* verifyArgs(int argc, char** argv)
{
    Args* args = (Args*)malloc(sizeof(Args));
    for(size_t i = 1; i<argc; i++)
    {
        // I wish I could do a switch case for this
        if(strcmp(argv[i],"-h") == 0)
        {
            args->help = 1;
        }
        else if(strcmp(argv[i],"-l") == 0)
        {
            args->ip = (char*)calloc(10,sizeof(char));
            strcpy(args->ip,"localhost");
        }
        else if(strcmp(argv[i],"-a") == 0)
        {
            printf("%d\n, %d\n", lenCommandLineArg(argv[i+1]), sizeof(char));
            args->accessControlList = (char*)calloc(lenCommandLineArg(argv[i+1]), sizeof(char));
            strcpy(args->accessControlList, argv[i+1]);
            //printf(args->accessControlList);
        }
    }

    return args;
}

void runOneArg()
{
    printf("No arguments supplied, use the \"-h\" option if you need help running this program.");
}

void runHelp()
{
    printf("The following commands are used by this program:\n\n");
    printf("[-h]   the \"help\" command, prints all commands. This one is kind of redundant but oh well.\n\n");
    printf("[-l]   Runs the server on localhost, use this for testing purposes\n\n");
    printf("[-a]   The argument immediately following this one is the path to the access control list.\n");
    printf("\t This is needed every time the program is run\n\n");
    printf("[-log]   The argument immediately following this one is the path to the log file.\n");
    printf("\t This is also needed every time the program is run\n\n");
}