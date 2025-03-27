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
	missiles.clear(); //원소 모두 제거, capacity 유지
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
