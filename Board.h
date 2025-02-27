#include "Piece.h"
#pragma once

class Board
{
private:
	Piece* _board[18][27] = { nullptr };
public:
	void Init();
	void Render();
};

