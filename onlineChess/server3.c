#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Port number not provided. Program terminated.\n");
        exit(1);
    }

    int sockfd , newsockfd , portno, n;
    char buffer[255];

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen; // 32 bit data type in socket.h

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket.");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr * ) &serv_addr, sizeof(serv_addr)) <0) {
        error("Binding failed");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
        error("Error on Accept");
    }

    int board[8][8] = {
	{8,9,10,11,12,10,9,8},
	{7,7,7,7,7,7,7,7},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{2,3,4,5,6,4,3,2}
	};
	int i1,i2,j1,j2;
	int turn = 0;
 S :   
    n = write(newsockfd, "Enter move: ", strlen("Enter move: "));
    
    if (n< 0) error("Error writing to socket.");
    printBoard(8,8, board[0]);
    printf("White Check: %d \n", lookForWhiteCheck(8,8,board[0]));
    printf("Black Check: %d \n", lookForBlackCheck(8,8,board[0]));
    printf("Turn: %d \n", turn);
    printf("Insert next move: \n");
    read(newsockfd, &i1, sizeof(int));
    read(newsockfd, &i2, sizeof(int));
    read(newsockfd, &j1, sizeof(int));
    read(newsockfd, &j2, sizeof(int));

    if (i1 > 7 || i2 > 7 || j1 > 7 || j2 > 7) {
        printf("Position values not valid: they lie outside the board \n");
        goto S;
    } else if (board[i1][i2] == 0) {
        printf("There is no piece in position [%d,%d] \n",i1,i2);
        goto S;
    } else {
        int pieceCode = board[i1][i2];
        if (turn == 0 && pieceCode >= 7) {
            printf("It's white's turn, can't move black pieces.\n");
            goto S;
        } else if (turn == 1 && pieceCode < 7) {
            printf("It's black's turn, can't move white pieces.\n");
            goto S;
        } else {
            int *possibleMoves = calculateMovesPiece(8, 8, board[0], i1, i2, pieceCode);
            int lengthMovesArr = possibleMoves[0] - 2;
            if (checkIfMoveIsIn(j1,j2,possibleMoves,lengthMovesArr)) {
                movePiece(i1,i2,j1,j2,board[0],pieceCode, &turn);
            } else {
                printf("The inserted move is not allowed!\n");
                goto S;
            }
            free(possibleMoves);
        }
    }
    printBoard(8,8,board[0]);

    int k1,k2,l1,l2;
    scanf("%1d%1d %1d%1d", &k1,&k2,&l1,&l2);
    if (k1 > 7 || k2 > 7 || l1 > 7 || l2 > 7) {
        printf("Position values not valid: they lie outside the board \n");
    } else if (board[k1][k2] == 0) {
        printf("There is no piece in position [%d,%d] \n",k1,k2);
    } else {
        int pieceCode = board[k1][k2];
        if (turn == 0 && pieceCode >= 7) {
            printf("It's white's turn, can't move black pieces.\n");
        } else if (turn == 1 && pieceCode < 7) {
            printf("It's black's turn, can't move white pieces.\n");
        } else {
            int *possibleMoves = calculateMovesPiece(8, 8, board[0], k1, k2, pieceCode);
            int lengthMovesArr = possibleMoves[0] - 2;
            if (checkIfMoveIsIn(l1,l2,possibleMoves,lengthMovesArr)) {
                movePiece(k1,k2,l1,l2,board[0],pieceCode, &turn);
            } else {
                printf("The inserted move is not allowed!\n");
            }
            free(possibleMoves);
        }
    }


    goto S;

Q:  close(newsockfd);
    close(sockfd);
    return 0;
}