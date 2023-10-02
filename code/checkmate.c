#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

int valueIsInArray(int value, int *arr, int length);
int * calculateAllowedMovesPawn(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateAllowedMovesKnight(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateAllowedMovesTower(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateMovesPiece(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int checkIfMoveIsIn(int rowpos, int columnpos, int *moves, int movesLength);
void movePiece(int initRow, int initColumn, int endRow, int endColumn, int * board, int code);

int *calculateAllEnemyMoves(int rows, int cols, int *board, int team) {
    int count = 3;
    int * totalMoves = (int*)malloc(sizeof(int)*count);
    if (totalMoves == NULL) {
        /* Memory allocation failed */
        exit(0);
    }
    totalMoves[0] = count;
    totalMoves[1] = UNDEFINED_VALUE;
    totalMoves[2] = UNDEFINED_VALUE;
}

/* Logic for checking if theres a check */

int lookForWhiteCheck(int rows, int cols, int *board) {
    int kingRow, kingColumn;
    int count = 1;
    // First loop: look for king position in the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i * 8 + j] == 6) {
                kingRow = i;
                kingColumn = j;
            }
        }
    }
    for (int k = 0; k < 8; k++) {
        for (int l = 0; l < 8; l++) {
            // Check if position on the board is an enemy piece
            if (board[k * 8 + l] >= 7) {
                int *possibleMoves = calculateMovesPiece(8, 8, board, k, l, board[k*8 + l]);
                int arraySize = possibleMoves[0] -2;
                if (checkIfMoveIsIn(kingRow, kingColumn, possibleMoves, arraySize)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int lookForBlackCheck(int rows, int cols, int *board) {
    int kingRow, kingColumn;
    int count = 1;
    // First loop: look for king position in the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i * 8 + j] == 12) {
                kingRow = i;
                kingColumn = j;
            }
        }
    }
    for (int k = 0; k < 8; k++) {
        for (int l = 0; l < 8; l++) {
            // Check if position on the board is an enemy piece
            if (board[k * 8 + l] < 7 && board[k*8 + l] > 0) {
                int *possibleMoves = calculateMovesPiece(8, 8, board, k, l, board[k*8 + l]);
                int arraySize = possibleMoves[0] -2;
                if (checkIfMoveIsIn(kingRow, kingColumn, possibleMoves, arraySize)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}