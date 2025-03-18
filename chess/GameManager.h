#pragma once
#include "ChessBoard.h"
#include "FileManager.h"

class GameManager {
public:
    ChessBoard board;
    bool isWhiteTurn = true;
    void playGame();
};
