#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

int valueIsInArray(int value, int *arr, int length);

/* Function to calculate all possible moves for a pawn in a determined position */

int * calculateAllowedMovesPawn(int rows, int cols, int *board, int rowPosition, int columnPosition, int code) {
    int count = 3;
    int * allowedMoves = (int*)malloc(sizeof(int) * count);
    allowedMoves[0] = count;
    allowedMoves[1] = UNDEFINED_VALUE;
    allowedMoves[2] = UNDEFINED_VALUE;
    if (allowedMoves == NULL) {
        /* Check if memory allocation with malloc is not successful */
        exit(0);
    } else {
        /* Memory allocation is successful. */
    }
    /* Check if the piece in the passed position is actually a pawn (recall the pawn piece code is 1 or 7 (depending if it is white or black))*/
	if (board[rowPosition*8 + columnPosition] == code) {
        int eatingRange[6];
        int jumpValue, initialPos;
        if (code == 1) {
            eatingRange[0] = 7;
            eatingRange[1] = 8;
            eatingRange[2] = 9;
            eatingRange[3] = 10;
            eatingRange[4] = 11;
            eatingRange[5] = 12;
            jumpValue = -1;
            initialPos = 6;
        } else if (code == 7) {
            eatingRange[0] = 1;
            eatingRange[1] = 2;
            eatingRange[2] = 3;
            eatingRange[3] = 4;
            eatingRange[4] = 5;
            eatingRange[5] = 6;  
            jumpValue = 1;
            initialPos = 1;     
        }
        /* For our pawn we have at most 4 possible spots to move in (ignoring en passant for now) */
        /* Spot 1: move one vertical unit towards the bottom/top*/
        // If spot is empty, we can move
        if (board[(rowPosition+ jumpValue)*8 + columnPosition] == 0 ) {
            allowedMoves[count - 2] = rowPosition + jumpValue;
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
        /* Spot 2: move one vertical unit towards the bottom/top and one horizontal unit to the right*/
        // If spot is populated by an enemy piece, we can move and eat.
        if (valueIsInArray(board[(rowPosition+jumpValue)*8 + columnPosition + 1],eatingRange, 6) ) {
            allowedMoves[count - 2] = rowPosition + jumpValue;
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
        /* Spot 3: move one vertical unit towards the bottom/top and one horizontal unit to the left*/
        // If spot is populated by an enemy piece, we can move and eat.
        if (valueIsInArray(board[(rowPosition + jumpValue)*8 + columnPosition - 1],eatingRange,6)) {
            allowedMoves[count - 2] = rowPosition + jumpValue;
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
        /* Spot 4: only check if we have never moved the pawn in the game (i.e if it is at starting position index 6)*/
        // Move 2 vertical units downwards/upwards.
		if (rowPosition == initialPos) {
			if (board[(rowPosition + 2*jumpValue)*8 + columnPosition ] == 0 ) {
                allowedMoves[count - 2] = rowPosition + (2*jumpValue);
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
	}
	// Return the array of allowed positions for our pawn.
	// It will be of the following form: [rowplace1,columnplace1,rowplace2,columnplace2, ...]
	return allowedMoves;
}
