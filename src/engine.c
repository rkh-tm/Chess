#include "engine.h"

bool init_board(Piece *board[8][8]){
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			board[i][j] = NULL;
		}
	}

	Type pieces[] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
	for(int col='a'; col<='h'; col++){
		board[col-'a'][2-1] = malloc(sizeof(Piece));
		if(!board[col-'a'][2-1]) return false;
		*board[col-'a'][2-1] = (Piece){WHITE, PAWN};

		board[col-'a'][7-1] = malloc(sizeof(Piece));
		if(!board[col-'a'][7-1]) return false;
		*board[col-'a'][7-1] = (Piece){BLACK, PAWN};

		board[col-'a'][1-1] = malloc(sizeof(Piece));
		if(!board[col-'a'][1-1]) return false;
		*board[col-'a'][1-1] = (Piece){WHITE, pieces[col-'a']};

		board[col-'a'][8-1] = malloc(sizeof(Piece));
		if(!board[col-'a'][8-1]) return false;
		*board[col-'a'][8-1] = (Piece){BLACK, pieces[col-'a']};
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