#ifndef CHESS_ENGINE_H
#define CHESS_ENGINE_H

#include <stdlib.h>
#include "types.h"

bool init_board(Piece *board[8][8]);
void free_board(Piece *board[8][8]);

#endif