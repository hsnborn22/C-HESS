#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

int valueIsInArray(int value, int *arr, int length);

int * calculateAllowedMovesKing(int rows, int cols, int *board, int rowPosition, int columnPosition, int code) {
    int count = 3;
    int * allowedMoves = (int*)malloc(sizeof(int)*count);
    if (allowedMoves == NULL) {
        // Memory allocation with malloc failed
        exit(0);
    } else {
        // Memory allocation successful
    }
    allowedMoves[0] = count;
    allowedMoves[1] = UNDEFINED_VALUE;
    allowedMoves[2] = UNDEFINED_VALUE;
    /* Check if the piece in the position passed is a king (code 6 or 12)*/
    if (board[rowPosition * 8 + columnPosition] == code) {
        int eatingRange[6];
        if (code == 4) {
            eatingRange[0] = 7;
            eatingRange[1] = 8;
            eatingRange[2] = 9;
            eatingRange[3] = 10;
            eatingRange[4] = 11;
            eatingRange[5] = 12;
        } else if (code == 10) {
            eatingRange[0] = 1;
            eatingRange[1] = 2;
            eatingRange[2] = 3;
            eatingRange[3] = 4;
            eatingRange[4] = 5;
            eatingRange[5] = 6;        
        }
        // Logic for king moves; the king can move 1 step backwards,forwards, to the left, to the right, or in any diagonal.
        // 1) Move to the right: if the value of the position one unit to the right w.r.t the king is 0(empty) or is an enemy piece, then we can move.
        if (columnPosition + 1 <= 7) {
            if (board[rowPosition * 8 + columnPosition + 1] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition + 1], eatingRange,6)) {
                allowedMoves[count - 2] = rowPosition ;
                allowedMoves[count - 1] = columnPosition + 1;
                count += 2;
                allowedMoves[0] = count;
                /* Declare a temporary variable storing the value of our array of interest */
                int *temp = allowedMoves;
                allowedMoves = realloc(allowedMoves, count * sizeof(int));
                if (!allowedMoves) {
                    /* Check if memory re-allocation failed */
                    allowedMoves = temp;
                } else {
                    /* Memory re-allocation is sucessful */
                }
            }
        }
        // 2) Move to the left: if the value of the position one unit to the left w.r.t the king is 0(empty) or is an enemy piece, then we can move.
        if (columnPosition - 1 >= 0) {
            if (board[rowPosition * 8 + columnPosition - 1] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition - 1], eatingRange,6)) {
                allowedMoves[count - 2] = rowPosition ;
                allowedMoves[count - 1] = columnPosition - 1;
                count += 2;
                allowedMoves[0] = count;
                /* Declare a temporary variable storing the value of our array of interest */
                int *temp = allowedMoves;
                allowedMoves = realloc(allowedMoves, count * sizeof(int));
                if (!allowedMoves) {
                    /* Check if memory re-allocation failed */
                    allowedMoves = temp;
                } else {
                    /* Memory re-allocation is sucessful */
                }
            }
        }
        // 3) Move upwards: if the value of the position one unit above the king is 0(empty) or is an enemy piece, then we can move.
        if (rowPosition - 1 >= 0) {
            if (board[rowPosition * 8 + columnPosition - 8] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition - 8], eatingRange,6)) {
                allowedMoves[count - 2] = rowPosition - 1;
                allowedMoves[count - 1] = columnPosition;
                count += 2;
                allowedMoves[0] = count;
                /* Declare a temporary variable storing the value of our array of interest */
                int *temp = allowedMoves;
                allowedMoves = realloc(allowedMoves, count * sizeof(int));
                if (!allowedMoves) {
                    /* Check if memory re-allocation failed */
                    allowedMoves = temp;
                } else {
                    /* Memory re-allocation is sucessful */
                }
            }
        }
        // 4) Move upwards: if the value of the position one unit above the king is 0(empty) or is an enemy piece, then we can move.
        if (rowPosition + 1 <= 7) {
            if (board[rowPosition * 8 + columnPosition + 8] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition + 8], eatingRange,6)) {
                allowedMoves[count - 2] = rowPosition + 1;
                allowedMoves[count - 1] = columnPosition;
                count += 2;
                allowedMoves[0] = count;
                /* Declare a temporary variable storing the value of our array of interest */
                int *temp = allowedMoves;
                allowedMoves = realloc(allowedMoves, count * sizeof(int));
                if (!allowedMoves) {
                    /* Check if memory re-allocation failed */
                    allowedMoves = temp;
                } else {
                    /* Memory re-allocation is sucessful */
                }
            }
        }
        // 5) Diagonal move 1: top + right
        if (rowPosition + 1 <= 7 && columnPosition + 1 <= 7) {
            if (board[rowPosition * 8 + columnPosition + 9] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition + 9], eatingRange,6)) {
                allowedMoves[count - 2] = rowPosition + 1;
                allowedMoves[count - 1] = columnPosition + 1;
                count += 2;
                allowedMoves[0] = count;
                /* Declare a temporary variable storing the value of our array of interest */
                int *temp = allowedMoves;
                allowedMoves = realloc(allowedMoves, count * sizeof(int));
                if (!allowedMoves) {
                    /* Check if memory re-allocation failed */
                    allowedMoves = temp;
                } else {
                    /* Memory re-allocation is sucessful */
                }
            }
        }
        // 6) Diagonal move 2: top + left
        if (rowPosition + 1 <= 7 && columnPosition -1 >= 0) {
            if (board[rowPosition * 8 + columnPosition + 7] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition + 7], eatingRange,6)) {
                allowedMoves[count - 2] = rowPosition + 1;
                allowedMoves[count - 1] = columnPosition - 1;
                count += 2;
                allowedMoves[0] = count;
                /* Declare a temporary variable storing the value of our array of interest */
                int *temp = allowedMoves;
                allowedMoves = realloc(allowedMoves, count * sizeof(int));
                if (!allowedMoves) {
                    /* Check if memory re-allocation failed */
                    allowedMoves = temp;
                } else {
                    /* Memory re-allocation is sucessful */
                }
            }
        }
        // 7) Diagonal move 3: bottom + left
        if (rowPosition -1 >= 0 && columnPosition - 1 >= 0) {
            if (board[rowPosition * 8 + columnPosition - 9] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition - 9], eatingRange,6)) {
                allowedMoves[count - 2] = rowPosition - 1;
                allowedMoves[count - 1] = columnPosition - 1;
                count += 2;
                allowedMoves[0] = count;
                /* Declare a temporary variable storing the value of our array of interest */
                int *temp = allowedMoves;
                allowedMoves = realloc(allowedMoves, count * sizeof(int));
                if (!allowedMoves) {
                    /* Check if memory re-allocation failed */
                    allowedMoves = temp;
                } else {
                    /* Memory re-allocation is sucessful */
                }
            }
        }
        // 8) Diagonal move 4: bottom + right
        if (rowPosition - 1 >= 0 && columnPosition + 1 <= 7) {
            if (board[rowPosition * 8 + columnPosition - 7] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition - 7], eatingRange,6)) {
                allowedMoves[count - 2] = rowPosition - 1;
                allowedMoves[count - 1] = columnPosition + 1;
                count += 2;
                allowedMoves[0] = count;
                /* Declare a temporary variable storing the value of our array of interest */
                int *temp = allowedMoves;
                allowedMoves = realloc(allowedMoves, count * sizeof(int));
                if (!allowedMoves) {
                    /* Check if memory re-allocation failed */
                    allowedMoves = temp;
                } else {
                    /* Memory re-allocation is sucessful */
                }
            }
        }   
    }
    return allowedMoves;
}