#pragma once
#include "Board.h"

class Player
{
private:
    int selectedX, selectedY;  // 선택한 기물 위치

public:
    Player();
    void selectPiece(Board& board);  // 기물 선택
    void movePiece(Board& board, int targetX, int targetY);  // 기물 이동
};
