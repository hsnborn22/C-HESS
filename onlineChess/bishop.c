#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

int valueIsInArray(int value, int *arr, int length);

int max(int integer1, int integer2) {
    if (integer1 >= integer2) {
        return integer1;
    } else {
        return integer2;
    }
}

int min(int integer1, int integer2) {
    if (integer1 >= integer2) {
        return integer2;
    } else {
        return integer1;
    }
}

int * calculateAllowedMovesBishop(int rows, int cols, int *board, int rowPosition, int columnPosition, int code) {
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
    /* Check if the piece in the position passed is actually a bishop (code 4 or 10)*/
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
        // Logic for bishop moves:
        // We will proceed similarly as before, i.e with for loops to iteratively move "radially outwards"
        // Diagonal 1:  ->^
        for (int i = 1; i <= min(rowPosition, 7 - columnPosition); i++) {
            if (board[(rowPosition - i)*8 + columnPosition + i] == 0 ) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition - i;
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
            } else if (valueIsInArray(board[(rowPosition - i)*8 + columnPosition + i],eatingRange,6)) {
                // Store (since we can move there) and end the cycle (it's the last place where we will be able to move)
                allowedMoves[count - 2] = rowPosition - i;
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
        // Diagonal 2: <-^
        for (int i = 1; i <= min(rowPosition, columnPosition); i++) {
            if (board[(rowPosition - i)*8 + columnPosition - i] == 0 ) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition - i;
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
            } else if (valueIsInArray(board[(rowPosition - i)*8 + columnPosition - i],eatingRange,6)) {
                // Store (since we can move there) and end the cycle (it's the last place where we will be able to move)
                allowedMoves[count - 2] = rowPosition - i;
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
        // Diagonal 3: -> + down
        for (int i = 1; i <= min(7-rowPosition, 7-columnPosition); i++) {
            if (board[(rowPosition + i)*8 + columnPosition + i] == 0 ) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition + i;
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
            } else if (valueIsInArray(board[(rowPosition + i)*8 + columnPosition + i],eatingRange,6)) {
                // Store (since we can move there) and end the cycle (it's the last place where we will be able to move)
                allowedMoves[count - 2] = rowPosition + i;
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
        // Diagonal 4: <- + down
        for (int i = 1; i <= min(7-rowPosition, columnPosition); i++) {
            if (board[(rowPosition + i)*8 + columnPosition - i] == 0 ) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition + i;
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
            } else if (valueIsInArray(board[(rowPosition + i)*8 + columnPosition - i],eatingRange,6)) {
                // Store (since we can move there) and end the cycle (it's the last place where we will be able to move)
                allowedMoves[count - 2] = rowPosition + i;
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