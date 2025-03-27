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
	/*for (iterMissiles = missiles.begin(); iterMissiles != missiles.end(); iterMissiles++)
	{
		(*iterMissiles)->Update();
	}*/

	for (auto missile : missiles)
	{
		if (missile->GetIsActived())
		{
			missile->Update();
		}
	}
}

void MissileManager::Render(HDC hdc)
{
	/*for (iterMissiles = missiles.begin(); iterMissiles != missiles.end(); iterMissiles++)
	{
		(*iterMissiles)->Render(hdc);
	}*/

	for (auto missile : missiles)
	{
		if (missile->GetIsActived())
		{
			missile->Render(hdc);
		}
	}
}
Missile* MissileManager::AddMissile()
{
	// 비활성화된 미사일 찾아서 반환
	for (auto missile : missiles)
	{
		if (!missile->GetIsActived())
		{
			return missile;
		}
	}
	return nullptr; // 사용 가능한 미사일이 없으면 nullptr 반환
}

Missile* MissileManager::GetMissile()
{
	// AddMissile과 비슷하지만 추가적인 로직이 필요할 경우 사용
	return AddMissile();
}