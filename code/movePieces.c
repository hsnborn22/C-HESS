#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

// Declaring necessary functions coded in other files.

void printBoard(int rows, int cols, int *board);
int valueIsInArray(int value, int *arr, int length);
int * calculateAllowedMovesPawn(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateAllowedMovesKnight(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);

// Logic for allowed permutations of the chessboard


// Logic for moving a piece from initial position ([initRow, initColumn]) to end position ([endRow,endColumn])
void movePiece(int initRow, int initColumn, int endRow, int endColumn, int * board, int code, int * turn) {
    board[initRow * 8 + initColumn] = 0;
    board[endRow * 8 + endColumn] = code;
    if (code >= 7) {
        *turn -= 1;
    } else if (code < 7 && code > 0) {
        *turn += 1;
    }
}