#include "ChessPiece.h"

bool Pawn::isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) {
    int direction = (symbol == 'P') ? -1 : 1;
    if (sy == dy && dx == sx + direction && board[dx][dy] == ' ') return true;
    if (sy == dy && dx == sx + 2 * direction && board[dx][dy] == ' ' && board[sx + direction][sy] == ' ' && (sx == 1 || sx == 6)) return true;
    if (abs(sy - dy) == 1 && dx == sx + direction && board[dx][dy] != ' ') return true;
    return false;
}

bool Rook::isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) {
    if (sx != dx && sy != dy) return false;
    int stepX = (dx > sx) ? 1 : (dx < sx) ? -1 : 0;
    int stepY = (dy > sy) ? 1 : (dy < sy) ? -1 : 0;
    for (int x = sx + stepX, y = sy + stepY; x != dx || y != dy; x += stepX, y += stepY) {
        if (board[x][y] != ' ') return false;
    }
    return true;
}

bool Knight::isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) {
    return (abs(sx - dx) == 2 && abs(sy - dy) == 1) || (abs(sx - dx) == 1 && abs(sy - dy) == 2);
}

bool Bishop::isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) {
    if (abs(sx - dx) != abs(sy - dy)) return false;
    int stepX = (dx > sx) ? 1 : -1;
    int stepY = (dy > sy) ? 1 : -1;
    for (int x = sx + stepX, y = sy + stepY; x != dx; x += stepX, y += stepY) {
        if (board[x][y] != ' ') return false;
    }
    return true;
}

bool Queen::isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) {
    return (sx == dx || sy == dy) || (abs(sx - dx) == abs(sy - dy));
}

bool King::isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) {
    return abs(sx - dx) <= 1 && abs(sy - dy) <= 1;
}
