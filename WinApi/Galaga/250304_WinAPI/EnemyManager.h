#pragma once
#include "GameObject.h"
#include <vector>

// 1. WinSizeX, Y�� �縷��濡 ���缭 ����
// 2. ��׶��带 �縷���� ����
// 3. �÷��̾� rocket bmp ����
// 4. �� 10���� ������ ����
// 5. �̻��� �Ŵ��� ���� - �÷��̾ ���, �� ���
// 6. ���� 1������ ������ �����Ѵ�.(�߰��� �̻��� 1�� �߻�)

class Enemy;
class EnemyManager : public GameObject
{
private: 
	Enemy* enemys;
	vector<Enemy*> vecEnemys;
	wchar_t szText[128];

public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void AddEnemy(int size);
};

