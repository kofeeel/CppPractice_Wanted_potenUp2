#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::saveGame(const ChessBoard& board, bool isWhiteTurn) {
    std::ofstream file("chess_game.txt");
    if (!file) {
        std::cout << "������ �����Ҽ� �����ϴ�.\n";
        return;
    }
    file << (isWhiteTurn ? "White" : "Black") << std::endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            file << board.board[i][j] << ' ';
        }
        file << std::endl;
    }
    file.close();
}

bool FileManager::loadGame(ChessBoard& board, bool& isWhiteTurn) {
    std::ifstream file("chess_game.txt");
    if (!file) {
        std::cout << "����� ������ �����ϴ�.\n";
        return false;
    }
    std::string turn;
    file >> turn;
    isWhiteTurn = (turn == "White");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            file >> board.board[i][j];
        }
    }
    file.close();
    return true;
}
