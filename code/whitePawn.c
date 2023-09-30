#include <stdio.h>
#include <stdlib.h>
#define UNDEFINED_VALUE 8001

/* Function to calculate all possible moves for a white pawn in a determined position */

int * calculateAllowedMovesWhitePawn(int rows, int cols, int *board, int rowPosition, int columnPosition) {
    int count = 2;
    int * allowedMoves = (int*)malloc(sizeof(int) * count);
    allowedMoves[0] = UNDEFINED_VALUE;
    allowedMoves[1] = UNDEFINED_VALUE;
    if (allowedMoves == NULL) {
        /* Check if memory allocation with malloc is not successful */
        exit(0);
    } else {
        /* Memory allocation is successful. */
    }
    /* Check if the piece in the passed position is actually a pawn (recall the pawn piece code is 1)*/
	if (board[rowPosition*8 + columnPosition] == 1) {
        /* For our pawn we have at most 4 possible spots to move in (ignoring en passant for now) */
        /* Spot 1: move one vertical unit towards the bottom*/
        // If spot is empty, we can move
        if (board[rowPosition*8 + columnPosition - 8] == 0 ) {
            allowedMoves[count - 2] = rowPosition - 1;
            allowedMoves[count - 1] = columnPosition;
            count += 2;
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
        /* Spot 2: move one vertical unit towards the bottom and one horizontal unit to the right*/
        // If spot is populated by an enemy piece, we can move and eat.
        if (board[rowPosition*8 + columnPosition - 7] == 0 ) {
            allowedMoves[count - 2] = rowPosition - 1;
            allowedMoves[count - 1] = columnPosition + 1;
            count += 2;
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
        /* Spot 3: move one vertical unit towards the bottom and one horizontal unit to the left*/
        // If spot is populated by an enemy piece, we can move and eat.
        if (board[rowPosition*8 + columnPosition - 9] == 0 ) {
            allowedMoves[count - 2] = rowPosition - 1;
            allowedMoves[count - 1] = columnPosition - 1;
            count += 2;
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
        // Move 2 vertical units downwards.
		if (rowPosition == 6) {
			if (board[rowPosition*8 + columnPosition - 16] == 0 ) {
                allowedMoves[count - 2] = rowPosition - 2;
                allowedMoves[count - 1] = columnPosition;
                count += 2;
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
