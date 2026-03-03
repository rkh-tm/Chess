#include "chess.h"

#define CHECK_SDL(x) if(!(x)) {error=SDL; goto cleanup;}

Error chess(){
	Error error = SUCCESS;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *surface_pieces, *surface_board;
	SDL_Texture *texture_pieces, *texture_board;

	window = SDL_CreateWindow("Chess", 640, 640, 0);
    CHECK_SDL(window);

	renderer = SDL_CreateRenderer(window, NULL);
    CHECK_SDL(renderer)

	surface_pieces = SDL_LoadPNG("assets/Pieces.png");
	CHECK_SDL(surface_pieces)
	texture_pieces = SDL_CreateTextureFromSurface(renderer, surface_pieces);
	CHECK_SDL(texture_pieces)

	surface_board = SDL_LoadPNG("assets/Board.png");
	CHECK_SDL(surface_board)
	texture_board = SDL_CreateTextureFromSurface(renderer, surface_board);
	CHECK_SDL(texture_board);

	CHECK_SDL(SDL_SetTextureScaleMode(texture_pieces, SDL_SCALEMODE_PIXELART));
	CHECK_SDL(SDL_SetTextureScaleMode(texture_board, SDL_SCALEMODE_PIXELART));

	CHECK_SDL(render_board(renderer, texture_board));

	bool running = true;
    while (running){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_EVENT_QUIT:
				running = false;
				break;
			case SDL_EVENT_KEY_DOWN:
				// CTRL-Q to Quit
				if((event.key.mod & SDL_KMOD_CTRL) && event.key.key==SDLK_Q && event.key.down) running = false;
				break;
			default: continue;
			}
		}
		
		SDL_Delay(16);
    }

cleanup:
	SDL_DestroySurface(surface_pieces);
	SDL_DestroySurface(surface_board);
	SDL_DestroyTexture(texture_pieces);
	SDL_DestroyTexture(texture_board);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return error;
}