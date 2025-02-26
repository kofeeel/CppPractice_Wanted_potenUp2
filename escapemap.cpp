#include <iostream>
#include <conio.h>

using namespace std;
// 탈출맵 생성 nxn 타일종류 3개 랜덤하게 배치하는 배열
enum class Tiletype
{
	Earth,
	Forest,
	Swamp
};

class Map 
{
public:
	int sizeX;
	int sizeY;
	int escapeX;
	int escapeY;

	Map()
	{

	}
	Map()
	{
		sizeX = 0;
		sizeY = 0;
	}

	void changeMapSize(int &mapsize) 
	{
		sizeX = mapsize;
		sizeY = mapsize;
	}
	void createMap(int& mapsize)
	{
		changeMapSize(mapsize);
	}
	void printMap();
	bool gameOver();
};

class Player
{
public:
	int posX;
	int posY;
	bool isDead;
	bool isEscape;

	Player()
	{
	posX = 0;
	posY = 0;
	isDead = false;
	isEscape = false;
	}
	void movePlayer();

};

class Monster
{

};

void startGame(Map &map, Player &player)
{
	cout << "게임을 시작합니다.\n";
	int mapSize = levelSelect();
	map.createMap(mapSize);

	do{
		system("cls");
		map.printMap();
		player.movePlayer();
	} while (!map.gameOver());
}
int levelSelect()
{
	cout << "난이도를 선택하세요, 이지(1)/ 노말(2)/ 하드(3)에 해당하는 숫자키를 입력하세요: ";
	int input = _getch();
	
	switch (input)
	{
	case 1:
		cout << "허접이군요";
		return 3;
		break;
	case 2:
		cout << "노말모드 입니다";
		return 5;
		break;
	case 3:
		cout << "정 말 어 렵 습 니 다";
		return 8;
		break;
	default:
		cout << "잘못된 입력입니다.";
		//창 나가기
		break;
	}
}

void movePlayer(Player player)
{
	cout << "w,a,s,d 방향키로 이동해주세요: ";
	char playerInput = _getch();

	switch (playerInput)
	{
	case 'w': case 'W':
		if (player.posY > 0)
		{
			player.posY++;
		}
		else
		{
			return;
		}
		break;
	case 'a': case 'A':
		if (player.posX > 0)
		{
			player.posX--;
		}
		else
		{
			return;
		}
	case 's': case 'S':
		if (player.posY >= 0)
		{
			player.posY--;
		}
		else
		{
			return;
		}
	case 'd': case 'D':
		if (player.posX >= 0)
		{
			player.posX++;
		}
		else
		{
			return;
		}
	default:
		return;
		break;
	}
}


int main()
{
	Map map{};
	
/*0. 게임 시작
  1. 난이도 선택
  2. 맵 생성
  3. 몬스터 생성
  4. 맵 출력
  5. 플레이어 이동
  6. 탈출/사망시 게임오버*/
}