#include "engine.h"

bool init_board(Piece *board[8][8]){
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			board[i][j] = NULL;
		}
	}

	for(int col='a'; col<='h'; col++){
		board[col-'a'][2-1] = malloc(sizeof(Piece));
		if(!board[col-'a'][2-1]) return false;
		*board[col-'a'][2-1] = (Piece){WHITE, PAWN};

		board[col-'a'][7-1] = malloc(sizeof(Piece));
		if(!board[col-'a'][7-1]) return false;
		*board[col-'a'][7-1] = (Piece){BLACK, PAWN};
	}

	return true;
}

void free_board(Piece *board[8][8]){
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			free(board[i][j]);
		}
	}

	return;
}