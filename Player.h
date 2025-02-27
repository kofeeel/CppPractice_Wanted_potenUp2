#pragma once
#include "Board.h"

class Player
{
private:
    int selectedX, selectedY;  // ������ �⹰ ��ġ

public:
    Player();
    void selectPiece(Board& board);  // �⹰ ����
    void movePiece(Board& board, int targetX, int targetY);  // �⹰ �̵�
};
