#ifndef NETWORKINGFINAL_SERVER_H
#define NETWORKINGFINAL_SERVER_H

#define _WIN32_WINNT 0x0502
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <time.h>

#include "Structs.h"
#include "Util.h"

#define BUFLEN 128
#define PORT "8000"

void runServer(Args* args);



#endif //NETWORKINGFINAL_SERVER_H
