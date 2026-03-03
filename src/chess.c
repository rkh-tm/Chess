#include "chess.h"

#define CHECK(x, errcode) if(!(x)) {error=errcode; goto cleanup;}

Error chess(){
	Error error = SUCCESS;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *surface_pieces, *surface_board;
	SDL_Texture *texture_pieces, *texture_board;
	Piece *board[8][8];

	CHECK(init_board(board), MEMORY);

	window = SDL_CreateWindow("Chess", 640, 640, 0);
    CHECK(window, SDL);

	renderer = SDL_CreateRenderer(window, NULL);
    CHECK(renderer, SDL)

	surface_pieces = SDL_LoadPNG("assets/Pieces.png");
	CHECK(surface_pieces, SDL)
	texture_pieces = SDL_CreateTextureFromSurface(renderer, surface_pieces);
	CHECK(texture_pieces, SDL)

	surface_board = SDL_LoadPNG("assets/Board.png");
	CHECK(surface_board, SDL)
	texture_board = SDL_CreateTextureFromSurface(renderer, surface_board);
	CHECK(texture_board, SDL);

	CHECK(SDL_SetTextureScaleMode(texture_pieces, SDL_SCALEMODE_PIXELART), SDL);
	CHECK(SDL_SetTextureScaleMode(texture_board, SDL_SCALEMODE_PIXELART), SDL);

	CHECK(render_board(renderer, texture_board), SDL);

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
	free_board(board);
	SDL_DestroySurface(surface_pieces);
	SDL_DestroySurface(surface_board);
	SDL_DestroyTexture(texture_pieces);
	SDL_DestroyTexture(texture_board);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return error;
}