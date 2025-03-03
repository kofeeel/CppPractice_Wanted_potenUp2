#pragma once
#include "ChessBoard.h"

class FileManager {
public:
    static void saveGame(const ChessBoard& board, bool isWhiteTurn);
    static bool loadGame(ChessBoard& board, bool& isWhiteTurn);
};
