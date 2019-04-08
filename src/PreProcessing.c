#include "PreProcessing.h"

Args* verifyArgs(int argc, char** argv)
{
    int badFile = 0;
    int badArgs = 0;

    Args* args = (Args*)malloc(sizeof(Args));

    // set default values for error testing
    args->help = 0;
    args->rangeOrList = 1111;

    if(argc == 1)
    {
        runOneArg();
        free(args);
        return NULL;
    }

    for(size_t i = 1; i<argc; i++)
    {
        if(strcmp(argv[i],"-a") == 0)
        {
            args->accList = fopen(argv[i+1], "a");
            if(args->accList == NULL)
            {
                free(args);
                badFile = 1;
            }
            i++;
        }
        else if(strcmp(argv[i],"-log") == 0)
        {
            args->logFile = fopen(argv[i+1], "a");
            if(args->logFile == NULL)
            {
                free(args);
                badFile = 1;
            }
            i++;
        }
        else if(strcmp(argv[i],"-logN") == 0)
        {
            args->logFile = fopen(argv[i+1], "w");
            if(args->logFile == NULL)
            {
                free(args);
                badFile = 1;
            }
            i++;
        }
        else if(strcmp(argv[i],"-h") == 0)
        {
            args->help = 1;
        }
        else if(strcmp(argv[i],"-l") == 0)
        {
            args->ip = (char*)malloc(11*sizeof(char));
            strcpy(args->ip, "localhost");
        }
        else if(strcmp(argv[i],"-ip") == 0)
        {
            args->ip = argv[i+1];
        }
        else if(strcmp(argv[i],"-list") == 0)
        {
            if(args->rangeOrList == 1 || args->rangeOrList == 0)
            {
                badArgs = 1;
            }
            args->rangeOrList = 1;
        }
        else if(strcmp(argv[i],"-range") == 0)
        {
            if(args->rangeOrList == 1 || args->rangeOrList == 0)
            {
                badArgs = 1;
            }
            args->rangeOrList = 0;
        }
        else
        {
            badArgs = 1;
        }
    }

    if(badFile || badArgs)
    {
        runBadArgs(badFile, badArgs);
        freeArgs(args);
        return NULL;
    }

    if(args->help)
    {
        runHelp();
        freeArgs(args);
        return NULL;
    }

    return args;
}

void runOneArg()
{
    printf("No arguments supplied, use the \"-h\" option if you need help running this program.");
}

void runBadArgs(int badFile, int badArgs)
{
    if(badFile && badArgs)
    {
        printf("Could not open file(s) at specified path(s), and could not parse command line arguments.\n");
        return;
    }
    else if(badFile)
    {
        printf("Could not open file(s) at specified path(s).\n");
        return;
    }
    else if(badArgs)
    {
        printf("Could not parse the command line arguments. Fix them and run the program again.\n");
    }
    else
    {
        printf("Bad command line arguments, try again.\n");
    }
}

void runHelp()
{
    printf("The following commands are used by this program:\n\n");
    printf("[-h]   the \"help\" command, prints all commands. This one is kind of redundant but oh well.\n\n");
    printf("[-l]   Runs the server on localhost, use this for testing purposes\n\n");
    //TODO check ip address of server. what is it?
    printf("[-ip]   The next argument is the i.p. address to run the server on. \n\n");
    printf("[-a]   The argument immediately following this one is the path to the access control list.\n");
    printf("\t This is needed every time the program is run\n\n");
    printf("[-log(N)]   The argument immediately following this one is the path to the log file.\n");
    printf("\tThe optional \"N\" argument tells the program to write over all information already in the log file, \n");
    printf("\ti.e. start a new log file with the given name. Omitting the \"N\" will append new data to the existing file\n");
    printf("\t This is also needed every time the program is run\n\n");
    printf("[-range]   This argument denotes that the access control list file will consist of ONE range of \n");
    printf("\t port values. This range must be written as \"x - y\" where x and y are the (inclusive) upper and\n");
    printf("\t lower bounds of the range of accepted ports\n\n");
    printf("[-list]   Using this argument means that the access control list file will consist simply of a list of\n");
    printf("\t accepted ports separated by spaces. So for example, \"5000 5001 5002\" is acceptable.\n\n");
}