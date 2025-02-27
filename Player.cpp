#include "Player.h"
#include <iostream>

Player::Player() : selectedX(-1), selectedY(-1) {}  // �ʱⰪ ����

// �⹰ ����
Player::selectPiece(Board& board ,int goX, int goY)
{
    int x, y;
    std::cout << "������ �⹰�� ��ġ (X Y) �Է�: ";
    std::cin >> x >> y;

    if (x < 0 || x >= 8 || y < 0 || y >= 8)
    {
        std::cout << "�߸��� ��ġ,�ٽ� �Է��ϼ���.\n";
        return;
    }

    if (board.getPiece(x, y) == nullptr)
    {
        std::cout << "�ش� ��ġ�� �⹰�� �����ϴ�! �ٽ� �����ϼ���.\n";
        return;
    }

    selectedX = x;
    selectedY = y;
    std::cout << "�⹰ ���� �Ϸ�: (" << selectedX << ", " << selectedY << ")\n";
}

// �⹰ �̵� �Լ�
void Player::movePiece(Board& board, int targetX, int targetY)
{
    if (selectedX == -1 || selectedY == -1)
    {
        std::cout << "���� �⹰�� �����ϼ���!\n";
        return;
    }

    if (targetX < 0 || targetX >= 8 || targetY < 0 || targetY >= 8)
    {
        std::cout << "�߸��� �̵� ��ġ�Դϴ�!\n";
        return;
    }

    Piece* piece = board.getPiece(selectedX, selectedY);
    if (piece == nullptr)
    {
        std::cout << "������ ��ġ�� �⹰�� �����ϴ�!\n";
        return;
    }

    board.movePiece(selectedX, selectedY, targetX, targetY);
    std::cout << "�⹰�� �̵��߽��ϴ�: (" << selectedX << ", " << selectedY << ") -> (" << targetX << ", " << targetY << ")\n";
}
