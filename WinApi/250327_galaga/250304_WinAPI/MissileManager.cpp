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
	// ��Ȱ��ȭ�� �̻��� ã�Ƽ� ��ȯ
	for (auto missile : missiles)
	{
		if (!missile->GetIsActived())
		{
			return missile;
		}
	}
	return nullptr; // ��� ������ �̻����� ������ nullptr ��ȯ
}

Missile* MissileManager::GetMissile()
{
	// AddMissile�� ��������� �߰����� ������ �ʿ��� ��� ���
	return AddMissile();
}