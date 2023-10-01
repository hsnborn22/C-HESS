#include <stdio.h>
#include <stdlib.h>

void printBoard(int rows, int cols, int *board);
int valueIsInArray(int value, int *arr, int length);
int * calculateAllowedMovesWhitePawn(int rows, int cols, int *board, int rowPosition, int columnPosition);
int * calculateAllowedMovesBlackPawn(int rows, int cols, int *board, int rowPosition, int columnPosition);
int * calculateAllowedMovesKnight(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateMovesPiece(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);

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
	int * ourArray = calculateAllowedMovesWhitePawn(8,8, board[0], 6, 3);
	int *array2 = calculateAllowedMovesKnight(8,8, board[0], 7, 1, 3);
	for (size_t i = 0; i < 4; i++) {
		printf("%d", array2[i]);
	}
	free(array2);
	free(ourArray);
	int i1,i2,j1,j2;
	while (1) {
		printBoard(8,8, board[0]);
		printf("Insert next move: \n");
		scanf("%1d%1d %1d%1d", &i1,&i2,&j1,&j2);
		printf("i1 is: %d i2 is: %d j1 is: %d j2 is: %d \n",i1,i2,j1,j2);
		if (i1 > 7 || i2 > 7 || j1 > 7 || j2 > 7) {
			printf("Position values not valid: they lie outside the board \n");
		} else if (board[i1][i2] == 0) {
			printf("There is no piece in position [%d,%d]",i1,i2);
		} else {
			int pieceCode = board[i1][i2];
			int *possibleMoves = calculateMovesPiece(8, 8, board[0], i1, i2, pieceCode);
			int lengthMovesArr = possibleMoves[0];
			printf("%d", lengthMovesArr);
		}
	}
	return 0;

}
