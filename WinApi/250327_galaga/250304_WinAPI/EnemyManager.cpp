#include "EnemyManager.h"
#include "Enemy.h"

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
	for (int i = 0; i < 10; i++)
	{
		vEnemies[i]->Release();
		delete vEnemies[i];
	}
	vEnemies.clear(); //���� ��� ����, capacity ����
}

void EnemyManager::Update()
{
	for (int i = 0; i < 10; i++)
	{
		vEnemies[i]->Update();
	}
}

void EnemyManager::Render(HDC hdc)
{
	for (int i = 0; i < vEnemies.size(); i++)
	{
		vEnemies[i]->Render(hdc);
	}
}

void EnemyManager::Move()
{
	for (int i = 0; i < vEnemies.size(); i++)
	{
		vEnemies[i]->Move();
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
