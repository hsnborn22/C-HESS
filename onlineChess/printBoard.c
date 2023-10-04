#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void printBoard(int rows, int cols, int *board) {
	for (int i =0; i < rows; ++i) {
        printf("\t \t ");
        for (int j=0; j < cols; ++j) {

            switch(board[i*cols + j]) {
                case 0:
                    printf("|  |");
                    break;
                case 1:
                    printf("|♙ |");
                    break;
                case 2:
                    printf("|♖ |");
                    break;
                case 3:
                    printf("|♘ |");
                    break;
                case 4:
                    printf("|♗ |");
                    break;
                case 5:
                    printf("|♕ |");
                    break;
                case 6:
                    printf("|♔ |");
                    break;
                case 7:
                    printf("|♟ ︎|");
                    break;
                case 8:
                    printf("|♜ |");
                    break;
                case 9:
                    printf("|♞ |");
                    break;
                case 10:
                    printf("|♝ |");
                    break;
                case 11:
                    printf("|♛ |");
                    break;
                case 12:
                    printf("|♚ |");
                    break;
            }
        }
        printf("\n");
	}
}
