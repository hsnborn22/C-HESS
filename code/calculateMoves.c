#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

void printBoard(int rows, int cols, int *board);
int valueIsInArray(int value, int *arr, int length);
int * calculateAllowedMovesWhitePawn(int rows, int cols, int *board, int rowPosition, int columnPosition);
int * calculateAllowedMovesBlackPawn(int rows, int cols, int *board, int rowPosition, int columnPosition);
int * calculateAllowedMovesKnight(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateAllowedMovesTower(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);


// Function to calculate the moves for an undetermined piece

int * calculateMovesPiece(int rows, int cols, int *board, int rowPosition, int columnPosition, int code) {
    int * arrayMoves;
    switch(code) {
        // Check if the piece is a white pawn; if so, the list of possible moves is returned by the function defined in whitePawn.c
        case 1:
            arrayMoves = calculateAllowedMovesWhitePawn(8,8,board,rowPosition, columnPosition);
            break;
        // Check if the piece is a white tower; if so, the list of possible moves is returned by the function coded in tower.c
        case 2:
            arrayMoves = calculateAllowedMovesTower(8,8,board,rowPosition, columnPosition, 2);
            break;
        // Check if the piece is a white knight; if so we use the function coded in knight.c to compute the allowed moves.
        case 3:
            arrayMoves = calculateAllowedMovesKnight(8,8,board, rowPosition, columnPosition, 3);
            break;
        // Check if the piece is a black pawn; if so, the list of possible moves is returned by the function defined in blackPawn.c
        case 7:
            arrayMoves = calculateAllowedMovesBlackPawn(8,8,board,rowPosition, columnPosition);
            break;
        // Check if the piece is a black tower; if so, the list of possible moves is returned by the function coded in tower.c
        case 8:
            arrayMoves = calculateAllowedMovesTower(8,8,board,rowPosition, columnPosition, 8);
            break;
        // Check if the piece is a black knight; if so we use the function coded in knight.c to compute the allowed moves.
        case 9:
            arrayMoves = calculateAllowedMovesKnight(8,8,board, rowPosition, columnPosition, 9);
            break;
    }
    // We return the arrayMoves array (containing all the possible moves) to the caller.
    return arrayMoves;
}

// Logic for checking if a determined position is contained in an arrayMoves array

int checkIfMoveIsIn(int rowpos, int columnpos, int *moves, int movesLength) {
    for (int i = 0; i <= movesLength / 2; i++) {
        if (moves[(2*i)+1] == rowpos && moves[(2*i)+2] == columnpos) {
            return 1;
        }
    }
    return 0;
}