#include "Structs.h"

void freeArgs(Args* args)
{
    free(args->ip);

    free(args);
}
