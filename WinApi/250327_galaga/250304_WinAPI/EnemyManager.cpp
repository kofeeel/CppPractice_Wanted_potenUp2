#include "EnemyManager.h"
#include "Enemy.h"
#include "TimerManager.h"

//5. 미사일 매니저 구현 - 플레이어도 사용, 적 사용 
//6. 적이 1마리씩 밑으로 돌격한다. 
// (내려오다가 미사일 1발 발사하고 화면밖으로 사라짐)
//1.미사일 생성 팩토리 패턴 (유도탄 미사일 공장, 폭탄 미사일 공장)
//2.플레이어의 행동 전략 패턴 (미사일 발사, 이동 ) 

void EnemyManager::Init()
{
	////1.배열 
	//enemies = new Enemy[10];
	//for (int i = 0; i < 10; i++)
	//{
	//	enemies[i].Init();
	//}
	//2.벡터
	//push_back()의 단점 : 매번 할당해주면 오버헤드 발생하므로 적당히쓰자
	//vEnemies.capacity(); //할당된 메모리 크기:  
	//vEnemies.reserve(60); //메모리를 60개 만큼 미리 할당
	//vEnemies.size();	//원소의 개수: 10
	//vEnemies.resize(60); //원소의 개수: 60 {0(nullptr) 으로 초기화된 값 넣기} 
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
	vEnemies.clear(); //원소 모두 제거, capacity 유지
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