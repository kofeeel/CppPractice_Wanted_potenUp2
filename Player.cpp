#include "Player.h"
#include <iostream>

Player::Player() : selectedX(-1), selectedY(-1) {}  // 초기값 설정

// 기물 선택
Player::selectPiece(Board& board ,int goX, int goY)
{
    int x, y;
    std::cout << "선택할 기물의 위치 (X Y) 입력: ";
    std::cin >> x >> y;

    if (x < 0 || x >= 8 || y < 0 || y >= 8)
    {
        std::cout << "잘못된 위치,다시 입력하세요.\n";
        return;
    }

    if (board.getPiece(x, y) == nullptr)
    {
        std::cout << "해당 위치에 기물이 없습니다! 다시 선택하세요.\n";
        return;
    }

    selectedX = x;
    selectedY = y;
    std::cout << "기물 선택 완료: (" << selectedX << ", " << selectedY << ")\n";
}

// 기물 이동 함수
void Player::movePiece(Board& board, int targetX, int targetY)
{
    if (selectedX == -1 || selectedY == -1)
    {
        std::cout << "먼저 기물을 선택하세요!\n";
        return;
    }

    if (targetX < 0 || targetX >= 8 || targetY < 0 || targetY >= 8)
    {
        std::cout << "잘못된 이동 위치입니다!\n";
        return;
    }

    Piece* piece = board.getPiece(selectedX, selectedY);
    if (piece == nullptr)
    {
        std::cout << "선택한 위치에 기물이 없습니다!\n";
        return;
    }

    board.movePiece(selectedX, selectedY, targetX, targetY);
    std::cout << "기물이 이동했습니다: (" << selectedX << ", " << selectedY << ") -> (" << targetX << ", " << targetY << ")\n";
}
