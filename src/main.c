#include <stdio.h>
#include "types.h"

void print_board(Piece *board[8][8]){
	for(int row=7; row>=0; row--){
		for(int col=0; col<=7; col++){
			if(board[row][col]==NULL){
				printf(".");
				continue;
			}

			char symbol;
			switch(board[row][col]->type){
			case PAWN:
				symbol = 'P';
				break;
			case ROOK:
				symbol = 'R';
				break;
			case KNIGHT:
				symbol = 'H';
				break;
			case BISHOP:
				symbol = 'B';
				break;
			case QUEEN:
				symbol = 'Q';
				break;
			case KING:
				symbol = 'K';
				break;
			}
			if(board[row][col]->color==BLACK) symbol += 32;
			printf("%c", symbol);
		}
		printf("\n");
	}
}

int main(){
	// Create Pieces
	Piece pieces[32];
	for(int i=0, c=0; i<32; i+=16, c++){
		for(int j=i; j<i+8; j++){
			pieces[j] = (Piece){(Color)c, PAWN, ALIVE};
		}
		for(int j=i+8, t=1; j<i+14; j+=2, t++){
			pieces[j] = (Piece){(Color)c, (Type)t, ALIVE};
			pieces[j+1] = pieces[j];
		}
		pieces[i+14] = (Piece){(Color)c, QUEEN, ALIVE};
		pieces[i+15] = (Piece){(Color)c, KING, ALIVE};
	}

	// Create Board
	Piece *board[8][8]; // a1 = [1-1]['a'-'a']
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			board[i][j] = NULL;
		}
	}
	for(int col=0; col<8; col++){
		board[1][col] = &pieces[col];
		board[6][col] = &pieces[col+16];
	}
	for(int col=0; col<3; col++){
		board[0][col] = &pieces[(col*2)+8];
		board[0][7-col] = &pieces[(col*2+1)+8];
		board[7][col] = &pieces[(col*2)+8+16];
		board[7][7-col] = &pieces[(col*2+1)+8+16];
	}
	board[0][3] = &pieces[14];
	board[7][3] = &pieces[14+16];
	board[0][4] = &pieces[15];
	board[7][4] = &pieces[15+16];

	print_board(board);
}