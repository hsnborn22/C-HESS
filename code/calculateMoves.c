#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

void printBoard(int rows, int cols, int *board);
int valueIsInArray(int value, int *arr, int length);
int * calculateAllowedMovesWhitePawn(int rows, int cols, int *board, int rowPosition, int columnPosition);
int * calculateAllowedMovesBlackPawn(int rows, int cols, int *board, int rowPosition, int columnPosition);
int * calculateAllowedMovesKnight(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);

// Functions to calculate the moves for an undetermined piece

int * calculateMovesPiece(int rows, int cols, int *board, int rowPosition, int columnPosition, int code) {
    int * arrayMoves;
    switch(code) {
        case 1:
            arrayMoves = calculateAllowedMovesWhitePawn(8,8,board,rowPosition, columnPosition);
            break;
        case 3:
            arrayMoves = calculateAllowedMovesKnight(8,8,board, rowPosition, columnPosition, 3);
            break;
        case 7:
            arrayMoves = calculateAllowedMovesBlackPawn(8,8,board,rowPosition, columnPosition);
            break;
        case 9:
            arrayMoves = calculateAllowedMovesKnight(8,8,board, rowPosition, columnPosition, 9);
            break;
    }
    return arrayMoves;
}

int checkIfMoveIsIn(int rowpos, int columnpos, int *moves, int movesLength) {
    for (int i =0; i < movesLength; i+=2) {
        if (moves[i+1] == rowpos && moves[i+2] == columnpos) {
            return 1;
        } else {}
    }
    return 0;
}