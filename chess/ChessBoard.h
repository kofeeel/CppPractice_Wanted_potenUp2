#pragma once
#include "ChessPiece.h"

class ChessBoard {
public:
    char board[BOARD_SIZE][BOARD_SIZE];
    ChessBoard();
    void printBoard();
    bool movePiece(int sx, int sy, int dx, int dy);
};