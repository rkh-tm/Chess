#include "engine.h"

bool board_init(Piece *board[8][8]){
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

void board_free(Piece *board[8][8]){
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			free(board[i][j]);
		}
	}

	return;
}

bool piece_select(Piece *board[8][8], Color turn, int x, int y){
	if(x>=8 || y>=8) return false;
	if(board[x][y]==NULL) return false;
	if(board[x][y]->color!=turn) return false;

	return true;
}