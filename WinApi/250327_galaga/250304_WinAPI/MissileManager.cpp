#include "MissileManager.h"
#include "Missile.h"

void MissileManager::Init()
{
	missiles.resize(30);
	for (iterMissiles = missiles.begin(); iterMissiles != missiles.end(); iterMissiles++)
	{
		(*iterMissiles) = new Missile;
		(*iterMissiles)->Init();
	}
}

void MissileManager::Release()
{
	for (iterMissiles = missiles.begin(); iterMissiles != missiles.end(); iterMissiles++)
	{
		(*iterMissiles)->Release();
		delete (*iterMissiles);
	}
	missiles.clear(); //���� ��� ����, capacity ����
}

void MissileManager::Update()
{
	for (iterMissiles = missiles.begin(); iterMissiles != missiles.end(); iterMissiles++)
	{
		(*iterMissiles)->Update();
	}
}

void MissileManager::Render(HDC hdc)
{
	for (iterMissiles = missiles.begin(); iterMissiles != missiles.end(); iterMissiles++)
	{
		(*iterMissiles)->Render(hdc);
	}
}
