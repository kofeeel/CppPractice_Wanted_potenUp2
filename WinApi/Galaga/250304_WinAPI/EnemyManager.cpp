#include "EnemyManager.h"
#include "Enemy.h"

void EnemyManager::Init()
{
	vecEnemys.resize(10);
	for (int i = 0; i < 10; i++)
	{
		vecEnemys[i] = new Enemy();
		vecEnemys[i]->Init(310.0f + 130.0f * (i % 5) , 
			80.0f + 90.0f * (i / 5));
	}
}

void EnemyManager::Release()
{
	for (int i = 0; i < 10; i++)
	{
		delete vecEnemys[i];
	}
	vecEnemys.clear();	// 원소가 모두 제거되고 capacity는 유지된다.
}

void EnemyManager::Update()
{
	for (int i = 0; i < vecEnemys.size(); i++)
	{
		vecEnemys[i]->Update();
	}
}

void EnemyManager::Render(HDC hdc)
{
	for (int i = 0; i < vecEnemys.size(); i++)
	{
		vecEnemys[i]->Render(hdc);
	}
}

void EnemyManager::AddEnemy(int size)
{
	for (int i = 0; i < size; i++)
	{
		vecEnemys.push_back(new Enemy());
		vecEnemys.back()->Init();
	}
}
