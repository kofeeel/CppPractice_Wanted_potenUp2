#include "GameManager.h"
#include <iostream>

void GameManager::playGame() {
    if (FileManager::loadGame(board, isWhiteTurn)) {
        std::cout << "게임 저장이 완료되었습니다!\n";
    }
    while (true) {
        board.printBoard();
        std::string start, end;
        std::cout << (isWhiteTurn ? "흰색 턴" : "검은색 턴") << " (흰색:대문자 검은색:소문자)\n(행과 열을 입력해 이동하세요,게임 저장을 원하면 'save'를 입력하세요): ";
        std::cin >> start;
        if (start == "save") {
            FileManager::saveGame(board, isWhiteTurn);
            std::cout << "저장되었습니다.\n";
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
