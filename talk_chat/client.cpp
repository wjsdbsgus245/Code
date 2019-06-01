#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <conio.h>

#define PORT 4567
#define BUFSIZE 1024

void ErrorHandling(char const *message);

int main(int argc, char **argv)
{
    SOCKET clntSock;
    WSADATA wsaData;
    SOCKADDR_IN servAddr;

    char sAddr[15];
    int nRcv;
    unsigned int Addr;
    char message[BUFSIZE];

    struct hostent *host;

    printf("Server Address : "); gets(sAddr);

    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        ErrorHandling("Load WinSock 2.2 DLL Error");

    clntSock = socket(AF_INET, SOCK_STREAM, 0);
    if(clntSock == INVALID_SOCKET)
        ErrorHandling("Socket Error");

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(sAddr);
    servAddr.sin_port = htons(PORT);

    if(connect(clntSock, (struct sockaddr*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
    {
        ErrorHandling("Connection Error");
    }
    else
    {
        printf("Connection OK!\n");
        printf("Start..\n");
    }

    while(1)
    {
        printf("\nSend Message : ");
        gets(message);

        if(strcmp(message, "exit") == 0)
        {
            send(clntSock, message, (int)strlen(message), 0);
            break;
        }

        send(clntSock, message, (int)strlen(message), 0);
        printf("Message Receives ...\n");

        nRcv = recv(clntSock, message, sizeof(message) - 1, 0);
        if(nRcv == SOCKET_ERROR)
        {
            printf("Receive Error..\n");
            break;
        }

        message[nRcv] = '\0';

        if(strcmp(message, "exit") == 0)
        {
            printf("Close Server Connection..\n");
            break;
        }

        printf("Receive Message : %s", message);

    }
    
    closesocket(clntSock);
    WSACleanup();
    printf("Close Connection..\n");
    _getch();

    return 0;
}

void ErrorHandling(char const *message)
{
    WSACleanup();
    fputs(message, stderr);
    fputc('\n', stderr);
    _getch();
    exit(1);
}