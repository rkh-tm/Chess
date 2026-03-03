#include "render.h"
#include <stdio.h>

bool render_board(SDL_Renderer *renderer, SDL_Texture *texture_board){
	int width, height;
	if(!SDL_GetRenderOutputSize(renderer, &width, &height)) return false;

	float side = (float)width / 8;
	SDL_FRect src_white = {0, 0, 80, 80}, src_black = {80, 0, 80, 80}, dst;
	for(int i=0; i<=7; i++){
		for(int j=0; j<=7; j++){
			dst = (SDL_FRect){i*side, j*side, side, side};
			if((i+j)%2==0){
				if(!SDL_RenderTexture(renderer, texture_board, &src_white, &dst)) return false;
			}
			else{
				if(!SDL_RenderTexture(renderer, texture_board, &src_black, &dst)) return false;
			}
		}
	}

	if(!SDL_RenderPresent(renderer)) return false;

	return true;
}