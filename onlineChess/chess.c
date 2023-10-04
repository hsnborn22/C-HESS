#include <stdio.h>
#include <stdlib.h>

void printBoard(int rows, int cols, int *board);
int valueIsInArray(int value, int *arr, int length);
int * calculateAllowedMovesPawn(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateAllowedMovesKnight(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateAllowedMovesTower(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int * calculateMovesPiece(int rows, int cols, int *board, int rowPosition, int columnPosition, int code);
int checkIfMoveIsIn(int rowpos, int columnpos, int *moves, int movesLength);
void movePiece(int initRow, int initColumn, int endRow, int endColumn, int * board, int code, int * turn);
int lookForWhiteCheck(int rows, int cols, int *board);
int lookForBlackCheck(int rows, int cols, int *board);
void generateMenu();



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
	int i1,i2,j1,j2;
	int turn = 0;
	while (1) {
		char initCode, helpChoice;
		// Menu code
		generateMenu();
		// Check for user input
		scanf("/%c", &initCode);
		// Necessary to avoid infinite loops.
		getchar();
		if (initCode == 'p') {
			printf("Starting game... \n \n");
			break;
		} else if (initCode == 'h') {
			printf("Help");
		} else if (initCode == 'e') {
			exit(0);
		} else {
			printf("Not expected.");
		}
	}
	while (1) {
		printBoard(8,8, board[0]);
		printf("White Check: %d \n", lookForWhiteCheck(8,8,board[0]));
		printf("Black Check: %d \n", lookForBlackCheck(8,8,board[0]));
		printf("Turn: %d \n", turn);
		printf("Insert next move: \n");
		scanf("%1d%1d %1d%1d", &i1,&i2,&j1,&j2);
		printf("i1 is: %d i2 is: %d j1 is: %d j2 is: %d \n",i1,i2,j1,j2);
		if (i1 > 7 || i2 > 7 || j1 > 7 || j2 > 7) {
			printf("Position values not valid: they lie outside the board \n");
		} else if (board[i1][i2] == 0) {
			printf("There is no piece in position [%d,%d] \n",i1,i2);
		} else {
			int pieceCode = board[i1][i2];
			if (turn == 0 && pieceCode >= 7) {
				printf("It's white's turn, can't move black pieces.\n");
			} else if (turn == 1 && pieceCode < 7) {
				printf("It's black's turn, can't move white pieces.\n");
			} else {
				int *possibleMoves = calculateMovesPiece(8, 8, board[0], i1, i2, pieceCode);
				int lengthMovesArr = possibleMoves[0] - 2;
				if (checkIfMoveIsIn(j1,j2,possibleMoves,lengthMovesArr)) {
					movePiece(i1,i2,j1,j2,board[0],pieceCode, &turn);
				} else {
					printf("The inserted move is not allowed!\n");
				}
				free(possibleMoves);
			}
		}
	}
	return 0;

}
