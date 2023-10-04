#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

/* Function to check whether an integer value is in an array */
int valueIsInArray(int value, int *arr, int length) {
    for(int i = 0; i < length; i++) {
        if(arr[i] == value)
            return 1;
    }
    return 0;
    // Possible future change: change these with _Bool C89 or bool C99 <stdbool.h> library types for better readability
}


/* Function to calculate all possible moves for a knight in a determined position */

int * calculateAllowedMovesKnight(int rows, int cols, int *board, int rowPosition, int columnPosition, int code) {
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
    /* Check if the piece in the position passed is actually a knight (code 3 or 9)*/
    if (board[rowPosition * 8 + columnPosition] == code) {
        int eatingRange[6];
        if (code == 3) {
            eatingRange[0] = 7;
            eatingRange[1] = 8;
            eatingRange[2] = 9;
            eatingRange[3] = 10;
            eatingRange[4] = 11;
            eatingRange[5] = 12;
        } else if (code == 9) {
            eatingRange[0] = 1;
            eatingRange[1] = 2;
            eatingRange[2] = 3;
            eatingRange[3] = 4;
            eatingRange[4] = 5;
            eatingRange[5] = 6;        
        }
        /* Check all the possible allowed moves: knight can move in at most 8 places */
        // Spot 1
        if (rowPosition + 1 <= 7 && columnPosition + 2 <=7) {
            if (board[rowPosition*8 + columnPosition + 10] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition + 10], eatingRange, 6)) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition + 1;
                allowedMoves[count - 1] = columnPosition + 2;
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
        // Spot 2
        if (rowPosition + 1 <= 7 && columnPosition - 2 >= 0) {
            if (board[rowPosition*8 + columnPosition + 6] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition + 6], eatingRange, 6)) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition + 1;
                allowedMoves[count - 1] = columnPosition - 2;
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
        // Spot 3
        if (rowPosition + 2 <= 7 && columnPosition +1 <= 7) {
            if (board[rowPosition*8 + columnPosition + 17] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition + 17], eatingRange, 6)) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition + 2;
                allowedMoves[count - 1] = columnPosition +1;
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
        // Spot 4
        if (rowPosition + 2 <= 7 && columnPosition - 1 >= 0) {
            if (board[rowPosition*8 + columnPosition + 15] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition + 15], eatingRange, 6)) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition + 2;
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
        // Spot 5
        if (rowPosition - 1 >= 0 && columnPosition + 2 <= 7) {
            if (board[rowPosition*8 + columnPosition - 6] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition - 6], eatingRange, 6)) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition - 1;
                allowedMoves[count - 1] = columnPosition + 2;
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
        // Spot 6
        if (rowPosition - 1 >= 0 && columnPosition - 2 >= 0) {
            if (board[rowPosition*8 + columnPosition - 10] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition - 10], eatingRange, 6)) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition - 1;
                allowedMoves[count - 1] = columnPosition - 2;
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
        // Spot 7
        if (rowPosition - 2 >= 0 && columnPosition + 1 <= 7) {
            if (board[rowPosition*8 + columnPosition - 15] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition - 15], eatingRange, 6)) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition - 2;
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
        // Spot 8
        if (rowPosition - 2 >= 0 && columnPosition - 1 >= 0) {
            if (board[rowPosition*8 + columnPosition - 17] == 0 || valueIsInArray(board[rowPosition*8 + columnPosition - 17], eatingRange, 6)) {
                // Store position in our array and then reallocate memory for other possible positions.
                allowedMoves[count - 2] = rowPosition - 2;
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
    }
    // Return the array of allowed positions for our knight.
	// It will be of the following form: [rowplace1,columnplace1,rowplace2,columnplace2, ...]
    return allowedMoves;
}
