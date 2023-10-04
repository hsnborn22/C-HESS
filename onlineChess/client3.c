/*
filename server_ipaddress portno

argv[0] filename
argv[1] server_ipaddress
argv[2] portno

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void printBoard(int rows, int cols, int *board);
int valueIsInArray(int value, int *arr, int length);
int * calculateAllowedMovesPawn(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateAllowedMovesKnight(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateAllowedMovesTower(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateMovesPiece(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int checkIfMoveIsIn(int rowpos, int columnpos, int *moves, int movesLength);
void movePiece(int initRow, int initColumn, int endRow, int endColumn, int * board, int code, int * turn);
int lookForWhiteCheck(int rows, int cols, int *board);
int lookForBlackCheck(int rows, int cols, int *board);
void generateMenu();

void error(const char *msg) {
    perror(msg);
    exit(0);
}

void printBuffer(char buffer[]) {
    for (int i = 0; i < 8; i++) {
        printf("\t \t");
        for (int j = 0; j < 8; j++) {
            switch(buffer[i*8 + j]) {
                case '0':
                    printf("|  |");
                    break;
                case '1':
                    printf("|♙ |");
                    break;
                case '2':
                    printf("|♖ |");
                    break;
                case '3':
                    printf("|♘ |");
                    break;
                case '4':
                    printf("|♗ |");
                    break;
                case '5':
                    printf("|♕ |");
                    break;
                case '6':
                    printf("|♔ |");
                    break;
                case '7':
                    printf("|♟ ︎|");
                    break;
                case '8':
                    printf("|♜ |");
                    break;
                case '9':
                    printf("|♞ |");
                    break;
                case 'a':
                    printf("|♝ |");
                    break;
                case 'b':
                    printf("|♛ |");
                    break;
                case 'c':
                    printf("|♚ |");
                    break;
            }
        }
        printf("\n");
    }
}


int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[255];
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname portn\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET,SOCK_STREAM, 0);
    if (sockfd <0) {
        error("Error opening socket");
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host.");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server ->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) & serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed.");
    }

    int i1,i2,j1,j2;

 S:   
    bzero(buffer, 255);
    n = read(sockfd, buffer, 255);
    if (n <0) error("Error reading from socket");
    printf("Server - %s\n", buffer);
    printBuffer(buffer);

    // Need to exchange board array via socket
    printf("Enter next move:");
    scanf("%1d%1d %1d%1d", &i1, &i2, &j1, &j2);
    
    write(sockfd, &i1, sizeof(int));
    write(sockfd, &i2, sizeof(int));
    write(sockfd, &j1, sizeof(int));
    write(sockfd, &j2, sizeof(int));


    goto S;

    Q:
    printf("Exiting..");
    close(sockfd);
    return 0;
}