#include "chess.h"

#define CHECK(x, errcode) if(!(x)) {error=errcode; goto cleanup;}

Error chess(){
	Error error = SUCCESS;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *surface_piece, *surface_board;
	SDL_Texture *texture_piece, *texture_board;
	Piece *board[8][8];

	CHECK(board_init(board), MEMORY);

	window = SDL_CreateWindow("Chess", 640, 640, 0);
    CHECK(window, SDL);

	renderer = SDL_CreateRenderer(window, NULL);
    CHECK(renderer, SDL)

	surface_piece = SDL_LoadPNG("assets/Pieces.png");
	CHECK(surface_piece, SDL)
	texture_piece = SDL_CreateTextureFromSurface(renderer, surface_piece);
	CHECK(texture_piece, SDL)

	surface_board = SDL_LoadPNG("assets/Board.png");
	CHECK(surface_board, SDL)
	texture_board = SDL_CreateTextureFromSurface(renderer, surface_board);
	CHECK(texture_board, SDL);

	CHECK(SDL_SetTextureScaleMode(texture_piece, SDL_SCALEMODE_PIXELART), SDL);
	CHECK(SDL_SetTextureScaleMode(texture_board, SDL_SCALEMODE_PIXELART), SDL);

	int width, height;
	CHECK(SDL_GetRenderOutputSize(renderer, &width, &height), SDL);

	bool running = true;
	Color turn = WHITE;
	Position selected = {-1, -1};
	bool marker[8][8];
	memset(marker, 0, sizeof(marker));

    while (running){
		CHECK(SDL_RenderClear(renderer), SDL);
		CHECK(board_render(renderer, texture_board, width, height), SDL);
		CHECK(piece_render_all(renderer, texture_piece, board, width, height), SDL);

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
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				if(event.button.button!=1) break;
				
				Position last = selected;
				selected = (Position){(int)event.button.x/(width/8), 7-(int)event.button.y/(height/8)};

				piece_select(board, &turn, last, &selected, marker);

				break;
			default: continue;
			}
		}

		CHECK(marker_render(renderer, texture_board, board, marker, width, height), SDL);
		CHECK(piece_render(renderer, texture_piece, board, width, height, selected.x, selected.y), SDL);

		CHECK(SDL_RenderPresent(renderer), SDL);
		
		SDL_Delay(16);
    }

cleanup:
	board_free(board);
	SDL_DestroySurface(surface_piece);
	SDL_DestroySurface(surface_board);
	SDL_DestroyTexture(texture_piece);
	SDL_DestroyTexture(texture_board);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return error;
}