#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include "types.h"
#include "chess.h"

int main(){
	int error = 0;
	if(!SDL_Init(SDL_INIT_VIDEO)){
		printf("%s", SDL_GetError());
		error = 1;
		goto cleanup;
	}

	switch(chess()){
	case SUCCESS:
		break;
	case SDL:
		printf("%s", SDL_GetError());
		error = 1;
		goto cleanup;
	}

cleanup:
	SDL_Quit();

	return error;
}