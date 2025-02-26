#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class TileMap {
private:
    int n;
    char** map;
    int exitX, exitY;
    int monsterCount;

public:
    TileMap(int size) : n(size) {
        srand(time(0));

        // 2차원 배열 동적 할당
        map = new char* [n];
        for (int i = 0; i < n; i++)
            map[i] = new char[n];

        // 맵 초기화 (기본 타일 '.')
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                map[i][j] = '.';

        // 시작 위치 (0,0)
        map[0][0] = 'P';

        // 탈출 위치 설정
        exitX = rand() % n;
        exitY = rand() % n;
        while (exitX == 0 && exitY == 0) { // 시작 위치와 겹치지 않도록 설정
            exitX = rand() % n;
            exitY = rand() % n;
        }
        map[exitX][exitY] = 'E';

        // 몬스터 개수 계산 (n=3 → 1마리, n=5 → 3마리, n=7 → 9마리)
        monsterCount = (n / 2) * (n / 2);
        placeMonsters();
    }

    ~TileMap() {
        for (int i = 0; i < n; i++)
            delete[] map[i];
        delete[] map;
    }

    void placeMonsters() {
        int placed = 0;
        while (placed < monsterCount) {
            int x = rand() % n;
            int y = rand() % n;

            if (map[x][y] == '.' && !(x == exitX && y == exitY)) {
                map[x][y] = 'M';
                placed++;
            }
        }
    }

    void displayMap() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << map[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "맵 크기를 입력하세요 (3 이상의 홀수): ";
    cin >> n;

    if (n < 3 || n % 2 == 0) {
        cout << "3 이상의 홀수를 입력하세요.\n";
        return 1;
    }

    TileMap gameMap(n);
    gameMap.displayMap();

    return 0;
}
