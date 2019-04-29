#include "Server.h"

void runServer(Args* args)
{
    WSADATA wsaData;
    int iResult;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[BUFLEN];
    int recvbuflen = BUFLEN;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(args->ip, PORT, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return;
    }

    SOCKET ListenSocket = INVALID_SOCKET;
    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return;
    }

    // Setup the TCP listening socket
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }

    freeaddrinfo(result);

    SOCKET ClientSocket = INVALID_SOCKET;
    int count = 0;
    int limit = 5;
    while(count < limit)
    {
        printf("##################\nListening for connection....\n");

        iResult = listen(ListenSocket, SOMAXCONN);
        if (iResult == SOCKET_ERROR) {
            printf("listen failed with error: %d\n", WSAGetLastError());
            closesocket(ListenSocket);
            WSACleanup();
            return;
        }

        SOCKADDR_IN client_info;
        int addrsize = sizeof(client_info);
        // Accept a client socket
        ClientSocket = accept(ListenSocket, (struct sockaddr *) &client_info, &addrsize);
        if (ClientSocket == INVALID_SOCKET)
        {
            printf("accept failed with error: %d\n", WSAGetLastError());
            closesocket(ListenSocket);
            WSACleanup();
            return;
        }

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        fprintf(args->logFile, "#######################\n");
        fprintf(args->logFile, "Date/Time of connection: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

        // check to see if the connection should be shut down
        // assumes connection will be ipv4
        struct sockaddr_in ip_info = (struct sockaddr_in) client_info;
        char *ip = inet_ntoa(ip_info.sin_addr);
        if (!acceptIP(args, ip))
        {
            printf("connection from %s rejected! attempt logged.\n", ip);
            fprintf(args->logFile, "WARNING: REJECTED connection from %s\n", ip);
//            fprintf(args->logFile, "################\nREJECTED connection from: %s\n at %s", ip, asctime(timeinfo));
//            fprintf(args->logFile, " at %s", ip, asctime(timeinfo));

            iResult = shutdown(ClientSocket, SD_SEND);
            if (iResult == SOCKET_ERROR)
            {
                printf("shutdown failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return;
            }
            count++;
            continue;
        }
        printf("connection from %s accepted! logged.\n", ip);
        fprintf(args->logFile, "Connection accepted from %s\n", ip);

        // Receive until the peer shuts down the connection
        do
        {

            iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
            if (iResult > 0)
            {
                printf("Bytes received: %d\n", iResult);

                // Echo the buffer back to the sender
                iSendResult = send(ClientSocket, recvbuf, iResult, 0);
                if (iSendResult == SOCKET_ERROR)
                {
                    printf("send failed with error: %d\n", WSAGetLastError());
                    closesocket(ClientSocket);
                    WSACleanup();
                    return;
                }
                printf("Bytes sent: %d\n", iSendResult);
            } else if (iResult == 0)
                printf("Connection closing...\n");
            else
            {
                printf("recv failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return;
            }

        } while (iResult > 0);

        // shutdown the connection since we're done
        iResult = shutdown(ClientSocket, SD_SEND);
        if (iResult == SOCKET_ERROR)
        {
            printf("shutdown failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return;
        }
        count++;
    }
    printf("\nServer shutting down...\n");
    // cleanup
    closesocket(ListenSocket);
    closesocket(ClientSocket);
    WSACleanup();

}