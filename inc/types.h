#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H

typedef enum{
	SUCCESS, SDL, MEMORY
} Error;

typedef enum{
	WHITE, BLACK
} Color;

typedef enum{
	PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
} Type;

typedef struct{
	Color color;
	Type type;
} Piece;

typedef struct{
	int x, y;
} Position;

#endif