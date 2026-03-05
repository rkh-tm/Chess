#ifndef CHESS_RENDER_H
#define CHESS_RENDER_H

#include <SDL3/SDL.h>
#include "types.h"

bool board_render(SDL_Renderer *renderer, SDL_Texture *texture_board, int width, int height);
bool piece_render_all(SDL_Renderer *renderer, SDL_Texture *texture_pieces, Piece *board[8][8], int width, int height);

#endif