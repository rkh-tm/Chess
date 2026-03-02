#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H

typedef enum{
	WHITE, BLACK
} Color;

typedef enum{
	PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
} Type;

typedef enum{
	ALIVE, DEAD
} State;

typedef struct{
	Color color;
	Type type;
	State state;
} Piece;

#endif