#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

int valueIsInArray(int value, int *arr, int length);

int * calculateAllowedMovesTower(int rows, int cols, int *board, int rowPosition, int columnPosition, int code) {
    int count = 3;
    int * allowedMoves = (int*)malloc(sizeof(int) * count);
    if (allowedMoves == NULL) {
        /* Check if memory allocation with malloc is not successful */
        exit(0);
    } else {
        /* Memory allocation is successful. */
    }
    allowedMoves[0] = count;
    allowedMoves[1] = UNDEFINED_VALUE;
    allowedMoves[2] = UNDEFINED_VALUE;
    /* Check if the piece in the position passed is actually a tower (code 2 or 8)*/
    if (board[rowPosition* 8 + columnPosition] == code) {
        int eatingRange[6];
        if (code == 2) {
            eatingRange[0] = 7;
            eatingRange[1] = 8;
            eatingRange[2] = 9;
            eatingRange[3] = 10;
            eatingRange[4] = 11;
            eatingRange[5] = 12;
        } else if (code == 8) {
            eatingRange[0] = 1;
            eatingRange[1] = 2;
            eatingRange[2] = 3;
            eatingRange[3] = 4;
            eatingRange[4] = 5;
            eatingRange[5] = 6;        
        }
        // Check for places where the tower can move:
        // The tower can move radially outwards from the center towards all 4 directions
        // 1) top
        for (int i = 1; i <= rowPosition; i++) {
            if (board[(rowPosition - i)*8 + columnPosition] == 0 ) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition - i;
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
            } else if (valueIsInArray(board[(rowPosition - i)*8 + columnPosition],eatingRange,6)) {
                // Store (since we can move there) and end the cycle (it's the last place where we will be able to move)
                allowedMoves[count - 2] = rowPosition - i;
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
                break;
            } else {
                break;
            }
        } 
        // 2) Down
        for (int i = 1; i <= 7 - rowPosition; i++) {
            if (board[(rowPosition + i)*8 + columnPosition] == 0 ) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition + i;
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
            } else if (valueIsInArray(board[(rowPosition + i)*8 + columnPosition],eatingRange,6)) {
                // Store (since we can move there) and end the cycle (it's the last place where we will be able to move)
                allowedMoves[count - 2] = rowPosition + i;
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
                break;
            } else {
                break;
            }
        } 
        // 3) Right
        for (int i = 1; i <= 7- columnPosition ; i++) {
            if (board[rowPosition*8 + columnPosition + i] == 0 ) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition;
                allowedMoves[count - 1] = columnPosition + i;
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
            } else if (valueIsInArray(board[rowPosition*8 + columnPosition + i],eatingRange,6)) {
                // Store (since we can move there) and end the cycle (it's the last place where we will be able to move)
                allowedMoves[count - 2] = rowPosition;
                allowedMoves[count - 1] = columnPosition + i;
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
                break;
            } else {
                break;
            }
        } 
        for (int i = 1; i <= columnPosition ; i++) {
            if (board[rowPosition*8 + columnPosition - i] == 0 ) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition;
                allowedMoves[count - 1] = columnPosition - i;
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
            } else if (valueIsInArray(board[rowPosition*8 + columnPosition - i],eatingRange,6)) {
                // Store (since we can move there) and end the cycle (it's the last place where we will be able to move)
                allowedMoves[count - 2] = rowPosition;
                allowedMoves[count - 1] = columnPosition - i;
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
                break;
            } else {
                break;
            }
        } 
    }
    return allowedMoves;
}