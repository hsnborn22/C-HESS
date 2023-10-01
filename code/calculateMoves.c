#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

// Functions to calculate the moves for an undetermined piece

int * calculateMovesPiece(int rows, int cols, int *board, int rowPosition, int columnPosition, int code) {
    int * arrayMoves;
    switch(code) {
        case 1:
            arrayMoves = calculateAllowedMovesWhitePawn(8,8,board[0],rowPosition, columnPosition);
            break;
        case 3:
            arrayMoves = calculateAllowedMovesKnight(8,8,board[0], rowPosition, columnPosition, 3);
            break;
        case 7:
            arrayMoves = calculateAllowedMovesBlackPawn(8,8,board[0],rowPosition, columnPosition);
            break;
        case 9:
            arrayMoves = calculateAllowedMovesKnight(8,8,board[0], rowPosition, columnPosition, 9);
            break;
    }
    return arrayMoves;
}