#include "render.h"

void get_sprite_origin(Piece piece, float *x, float *y){
	*x = (int)piece.type * 80;
	*y = (int)piece.color * 80;

	return;
}

bool board_render(SDL_Renderer *renderer, SDL_Texture *texture_board, int width, int height){
	float side = (float)width / 8;
	SDL_FRect src_white = {0, 0, 80, 80}, src_black = {80, 0, 80, 80}, dst;
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			dst = (SDL_FRect){i*side, j*side, side, side};
			if(!SDL_RenderTexture(renderer, texture_board, ((i+j)%2) ? &src_black : &src_white, &dst)) return false;
		}
	}

	return true;
}

bool piece_render(SDL_Renderer *renderer, SDL_Texture *texture_pieces, Piece *board[8][8], int width, int height){
	float side = (float)width / 8;
	SDL_FRect src, dst;
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			if(board[i][j]==NULL) continue;

			dst = (SDL_FRect){i*side, (7-j)*side, side, side};
			src = (SDL_FRect){0, 0, 80, 80};
			get_sprite_origin(*board[i][j], &src.x, &src.y);
			if(!SDL_RenderTexture(renderer, texture_pieces, &src, &dst)) return false;
		}
	}

	return true;
}