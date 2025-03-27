#include "EnemyManager.h"
#include "Enemy.h"
#include "TimerManager.h"

//5. �̻��� �Ŵ��� ���� - �÷��̾ ���, �� ��� 
//6. ���� 1������ ������ �����Ѵ�. 
// (�������ٰ� �̻��� 1�� �߻��ϰ� ȭ������� �����)
//1.�̻��� ���� ���丮 ���� (����ź �̻��� ����, ��ź �̻��� ����)
//2.�÷��̾��� �ൿ ���� ���� (�̻��� �߻�, �̵� ) 

void EnemyManager::Init()
{
	////1.�迭 
	//enemies = new Enemy[10];
	//for (int i = 0; i < 10; i++)
	//{
	//	enemies[i].Init();
	//}
	//2.����
	//push_back()�� ���� : �Ź� �Ҵ����ָ� ������� �߻��ϹǷ� ����������
	//vEnemies.capacity(); //�Ҵ�� �޸� ũ��:  
	//vEnemies.reserve(60); //�޸𸮸� 60�� ��ŭ �̸� �Ҵ�
	//vEnemies.size();	//������ ����: 10
	//vEnemies.resize(60); //������ ����: 60 {0(nullptr) ���� �ʱ�ȭ�� �� �ֱ�} 
	enemyMissiles = new MissileManager();
	enemyMissiles->Init();

	shootInterval = 2.0f;
	shootTimer = 0.0f;

	vEnemies.resize(10);
	for (int i = 0; i < 10; i++)
	{
		vEnemies[i] = new Enemy();
		vEnemies[i]->Init(80.0f + 90.0f * (i % 5),
			30.0f + 40.0f * (i / 5));
	}
}

void EnemyManager::Release()
{
	if (enemyMissiles)
	{
		enemyMissiles->Release();
		delete enemyMissiles;
		enemyMissiles = nullptr;
	}
	for (auto enemy : vEnemies)
	{
		if (enemy)
		{
			enemy->Release();
			delete enemy;
		}
	}
	vEnemies.clear(); //���� ��� ����, capacity ����
}

void EnemyManager::Update()
{
	/*for (int i = 0; i < 10; i++)
	{
		vEnemies[i]->Update();
	}*/
	Move();

	if (enemyMissiles)
	{
		enemyMissiles->Update();
	}

	shootTimer += TimerManager::GetInstance()->GetDeltaTime();
	if (shootTimer >= shootInterval)
	{
		Shoot();
		shootTimer = 0.0f; 
	}
}

void EnemyManager::Render(HDC hdc)
{
	/*for (int i = 0; i < vEnemies.size(); i++)
	{
		vEnemies[i]->Render(hdc);
	}*/

	for (auto enemy : vEnemies)
	{
		if (enemy)
		{
			enemy->Render(hdc);
		}
	}

	if (enemyMissiles)
	{
		enemyMissiles->Render(hdc);
	}
}

void EnemyManager::Move()
{
	for (auto enemy : vEnemies)
	{
		if (enemy)
		{
			enemy->Move();
		}
	}
}

void EnemyManager::AddEnemy(int size)
{
	for (int i = 0; i < vEnemies.size(); i++)
	{
		vEnemies.push_back(new Enemy());
		vEnemies.back()->Init();
	}
}

void EnemyManager::Shoot()
{
	for (auto enemy : vEnemies)
	{
		if (enemy && rand() % 2 == 0) 
		{
			FPOINT enemyPos = enemy->GetPos();

			Missile* missile = enemyMissiles->AddMissile();
			if (missile)
			{
				missile->SetPos(enemyPos);
				missile->SetIsActived(true);
				missile->SetAngle(90.0f); 
			}
		}
	}
}