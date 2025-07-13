#pragma once
#include "nugget.h"

typedef nugget::coords mino;
typedef std::vector<mino> Tetromino;
#define I_TETROMINO  Tetromino{{mino{-2,0}, mino{-1,0}, mino{0,0}, mino{1,0}}}
#define J_TETROMINO  Tetromino{mino{0,-1}, mino{0,0}, mino{1,0}, mino{2,0}}
#define L_TETROMINO  Tetromino{mino{0,-1}, mino{0,0}, mino{-1,0}, mino{-2,0}}
#define O_TETROMINO Tetromino{mino{-1,-1}, mino{0,-1}, mino{-1,0}, mino{0,0}}
#define S_TETROMINO  Tetromino{mino{1,0}, mino{0,0}, mino{0,1}, mino{-1,1}}
#define T_TETROMINO  Tetromino{mino{-1,0}, mino{1,0}, mino{0,0}, mino{0,1}}
#define Z_TETROMINO  Tetromino{mino{-1,0}, mino{0,0}, mino{0,1}, mino{1,1}}

#define I_COLOR "cyan"
#define J_COLOR "blue"
#define L_COLOR "orange"
#define O_COLOR "yellow"
#define S_COLOR "green"
#define T_COLOR "purple"
#define Z_COLOR "red"

typedef enum {
	I,
	J,
	L,
	O,
	S,
	T,
	Z
}Tetromino_Value;