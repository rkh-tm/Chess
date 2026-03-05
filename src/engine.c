#include "engine.h"

// reference is rotated 90 degrees clockwise
// char reference[8][8][2] = {{"WR", "WP", "XX", "XX", "XX", "XX", "BP", "BR"},
// 							{"WN", "WP", "XX", "XX", "XX", "XX", "BP", "BN"},
// 							{"WB", "WP", "XX", "XX", "XX", "XX", "BP", "BB"},
// 							{"WQ", "WP", "XX", "XX", "XX", "XX", "BP", "BQ"},
// 							{"WK", "WP", "XX", "XX", "XX", "XX", "BP", "BK"},
// 							{"WB", "WP", "XX", "XX", "XX", "XX", "BP", "BB"},
// 							{"WN", "WP", "XX", "XX", "XX", "XX", "BP", "BN"},
// 							{"WR", "WP", "XX", "XX", "XX", "XX", "BP", "BR"}};

char reference[8][8][2] = {{"XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"},
							{"XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"},
							{"XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"},
							{"XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"},
							{"XX", "WP", "XX", "XX", "XX", "XX", "XX", "XX"},
							{"XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"},
							{"XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"},
							{"XX", "XX", "XX", "XX", "XX", "XX", "XX", "XX"}};

bool board_init(Piece *board[8][8]){
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			board[i][j] = malloc(sizeof(Piece));
			if(!board[i][j]) return false;

			switch(reference[i][j][0]){
			case 'W':
				board[i][j]->color = WHITE;
				break;
			case 'B':
				board[i][j]->color = BLACK;
				break;
			default:
				free(board[i][j]);
				board[i][j] = NULL;
				continue;
			}

			switch(reference[i][j][1]){
			case 'P':
				board[i][j]->type = PAWN;
				break;
			case 'R':
				board[i][j]->type = ROOK;
				break;
			case 'N':
				board[i][j]->type = KNIGHT;
				break;
			case 'B':
				board[i][j]->type = BISHOP;
				break;
			case 'Q':
				board[i][j]->type = QUEEN;
				break;
			case 'K':
				board[i][j]->type = KING;
				break;
			default:
				free(board[i][j]);
				board[i][j] = NULL;
				continue;
			}
		}
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

void marker_reset(bool marker[8][8]){
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			marker[i][j] = false;
		}
	}

	return;
}

void marker_update(Piece *board[8][8], int x, int y, bool marker[8][8]){
	int color = (board[x][y]->color==WHITE) ? 1 : -1;
	switch(board[x][y]->type){
	case PAWN:
		int startpos = (board[x][y]->color==WHITE) ? 1 : 6;
		if(0<=y+1*color && y+1*color<=7 && board[x][y+1*color]==NULL) marker[x][y+1*color] = true;
		if(y==startpos && 0<=y+2*color && y+2*color<=7 && board[x][y+2*color]==NULL) marker[x][y+2*color] = true;
		break;
	default:
		break;
	}

	return;
}

bool piece_select(Piece *board[8][8], Color turn, int *x, int *y, bool marker[8][8]){
	if(*x>=8 || *y>=8 || board[*x][*y]==NULL || board[*x][*y]->color!=turn){
		*x = -1;
		*y = -1;
		marker_reset(marker);
	}

	marker_update(board, *x, *y, marker);

	return true;
}