#include <stdio.h>
#include <stdlib.h>

void printBoard(int rows, int cols, int *board);
int valueIsInArray(int value, int *arr, int length);
int * calculateAllowedMovesWhitePawn(int rows, int cols, int *board, int rowPosition, int columnPosition);
int * calculateAllowedMovesBlackPawn(int rows, int cols, int *board, int rowPosition, int columnPosition);
int * calculateAllowedMovesKnight(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);

/*  ------------  Pieces notation: ------------
1 -> white pawn          | 7 -->  black pawn
2 -> white tower         | 8 -->  black tower
3 -> white knight        | 9 -->  black knight
4 -> white bishop        | 10 -> black bishop
5 -> white queen         | 11 -> black queen
6 -> white king          | 12 -> black king */

int main(void) {
	/* Initialize board and pieces */
	int board[8][8] = {
	{8,9,10,11,12,10,9,8},
	{7,7,7,7,7,7,7,7},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1},
	{2,3,4,5,6,4,3,2}
	};
	printBoard(8,8, board[0]);
	int * ourArray = calculateAllowedMovesWhitePawn(8,8, board[0], 6, 3);
	for (int i = 0; i < 4; i++) {
        printf("%d", ourArray[i]);
	}
	free(ourArray);
	return 0;

}
