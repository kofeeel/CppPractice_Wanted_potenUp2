#include "ChessBoard.h"
#include <iostream>
using namespace std;

ChessBoard::ChessBoard() {
    char initialBoard[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = initialBoard[i][j];
        }
    }
}

void ChessBoard::printBoard() {
    system("cls");
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << 8 - i << " | ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "  ---------------------------------" << endl;
    }
    cout << "    A   B   C   D   E   F   G   H" << endl;
}

bool ChessBoard::movePiece(int sx, int sy, int dx, int dy) {
    if (board[sx][sy] == ' ') {
        cout << "잘못된 위치입니다.\n";
        return false;
    }
    if (isupper(board[sx][sy]) == isupper(board[dx][dy]) && board[dx][dy] != ' ') {
        cout << "아군 기물입니다.\n";
        return false;
    }
    board[dx][dy] = board[sx][sy];
    board[sx][sy] = ' ';
    return true;
}