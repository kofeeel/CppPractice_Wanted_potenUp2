#pragma once
const int SHIFT_X = 3;
const int SHIFT_Y = 2;
enum class Team
{
	None,
	White,
	Black
};
enum class PieceType
{
	None,
	Pawn,
	Rook,
	Knight,
	Bishop,
	Queen,
	King
};
struct Pos
{
	int x;
	int y;
};

