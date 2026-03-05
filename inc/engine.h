#ifndef CHESS_ENGINE_H
#define CHESS_ENGINE_H

#include <stdlib.h>
#include "types.h"

bool board_init(Piece *board[8][8]);
void board_free(Piece *board[8][8]);
bool piece_select(Piece *board[8][8], Color turn, int x, int y);

#endif