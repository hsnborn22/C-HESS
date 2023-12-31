#include <stdio.h>
#include <stdlib.h>
#include "moveCounters.h"
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
        if (code == 8 && towerMoveCountBlack1 == 0) {
            if (initRow == 0 && initColumn == 0) {
                towerMoveCountBlack1++;
            }
        } else if (code == 8 && towerMoveCountBlack2 == 0) {
            if (initRow == 0 && initColumn == 7) {
                towerMoveCountBlack2++;
            }
        } else if (code == 12) {
            kingMoveCountBlack++;
            if (endRow == castleBlackRow1 && endColumn == castleBlackColumn1 && longSideFlagBlack == 1) {
                longSideFlagBlack = 0;
                board[3] = 8;
                board[0] = 0;
            } else if (endRow == castleBlackRow2 && endColumn == castleBlackColumn2 && shortSideFlagBlack == 1) {
                shortSideFlagBlack = 0;
                board[5] = 8;
                board[7] = 0;
            }
        } else if (code == 7 && endRow == 7) {
            int promotionCode;
            int possibleCodes[] = {8,9,10,11};
            S:
            printf("Insert the code of the piece you want to promote your pawn to: \n");
            printf("Reference: \n");
            printf("8 -> tower \t 9 -> knight \t 10 -> bishop \t 11 -> queen \n");
            scanf("%d", &promotionCode);
            if (valueIsInArray(promotionCode, possibleCodes, 4)) {
                board[endRow*8 + endColumn] = promotionCode;
            } else {
                printf("The code inserted is not valid: insert one of the codes specified above.\n");
                goto S;
            }
        }
        *turn -= 1;
    } else if (code < 7 && code > 0) {
        if (code == 2 && towerMoveCountWhite1 == 0) {
            if (initRow == 7 && initColumn == 0) {
                towerMoveCountWhite1++;
            }
        } else if (code == 2 && towerMoveCountWhite2 == 0) {
            if (initRow == 7 && initColumn == 7) {
                towerMoveCountWhite2++;
            }
        } else if (code == 6) {
            kingMoveCountWhite++;
            if (endRow == castleWhiteRow1 && endColumn == castleWhiteColumn1 && longSideFlagWhite == 1) {
                longSideFlagWhite = 0;
                board[59] = 2;
                board[56] = 0;
            } else if (endRow == castleWhiteRow2 && endColumn == castleWhiteColumn2 && shortSideFlagWhite == 1) {
                shortSideFlagWhite = 0;
                board[61] = 2;
                board[63] = 0;
            }
        } else if (code == 1 && endRow == 0) {
            int promotionCode;
            int possibleCodes[] = {2,3,4,5};
            X:
            printf("Insert the code of the piece you want to promote your pawn to: \n");
            printf("Reference: \n");
            printf("2 -> tower \t 3 -> knight \t 4 -> bishop \t 5 -> queen \n");
            scanf("%d", &promotionCode);
            if (valueIsInArray(promotionCode, possibleCodes, 4)) {
                board[endRow*8 + endColumn] = promotionCode;
            } else {
                printf("The code inserted is not valid: insert one of the codes specified above.\n");
                goto X;
            }
        }
        *turn += 1;
    }
}
