#pragma once
#include <iostream>
using namespace std;

constexpr int BOARD_SIZE = 8;

class ChessPiece {
public:
    char symbol;
    ChessPiece() : symbol(' ') {}  // 기본 생성자 추가
    ChessPiece(char s) : symbol(s) {}
    virtual bool isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) = 0;
};

class Pawn : public ChessPiece {
public:
    Pawn() : ChessPiece('P') {}  // 기본 생성자 추가
    Pawn(char s) : ChessPiece(s) {}
    bool isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Rook : public ChessPiece {
public:
    Rook() : ChessPiece('R') {}
    Rook(char s) : ChessPiece(s) {}
    bool isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Knight : public ChessPiece {
public:
    Knight() : ChessPiece('N') {}
    Knight(char s) : ChessPiece(s) {}
    bool isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Bishop : public ChessPiece {
public:
    Bishop() : ChessPiece('B') {}
    Bishop(char s) : ChessPiece(s) {}
    bool isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Queen : public ChessPiece {
public:
    Queen() : ChessPiece('Q') {}
    Queen(char s) : ChessPiece(s) {}
    bool isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) override;
};

class King : public ChessPiece {
public:
    King() : ChessPiece('K') {}
    King(char s) : ChessPiece(s) {}
    bool isValidMove(int sx, int sy, int dx, int dy, char board[BOARD_SIZE][BOARD_SIZE]) override;
    static bool isChecked(char board[BOARD_SIZE][BOARD_SIZE], int kx, int ky);
};