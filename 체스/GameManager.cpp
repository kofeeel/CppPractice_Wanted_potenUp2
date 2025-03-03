#include "GameManager.h"
#include <iostream>

void GameManager::playGame() {
    if (FileManager::loadGame(board, isWhiteTurn)) {
        std::cout << "���� ������ �Ϸ�Ǿ����ϴ�!\n";
    }
    while (true) {
        board.printBoard();
        std::string start, end;
        std::cout << (isWhiteTurn ? "��� ��" : "������ ��") << " (���:�빮�� ������:�ҹ���)\n(��� ���� �Է��� �̵��ϼ���,���� ������ ���ϸ� 'save'�� �Է��ϼ���): ";
        std::cin >> start;
        if (start == "save") {
            FileManager::saveGame(board, isWhiteTurn);
            std::cout << "����Ǿ����ϴ�.\n";
            continue;
        }
        std::cin >> end;
        int sy = toupper(start[0]) - 'A';
        int sx = '8' - start[1];
        int dy = toupper(end[0]) - 'A';
        int dx = '8' - end[1];
        if (board.movePiece(sx, sy, dx, dy)) {
            isWhiteTurn = !isWhiteTurn;
        }
    }
}
