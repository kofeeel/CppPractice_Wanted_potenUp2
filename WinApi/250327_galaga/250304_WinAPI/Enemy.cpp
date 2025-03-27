#include "Enemy.h"
#include "CommonFunction.h"
#include "Tank.h"
#include "Image.h"
#include "Missile.h"
#include "MissileManager.h"
/*
	STL (Standard Template Library) : Vector
	동적배열을 제공하는 표준 템플릿 라이브러리 컨테이너 
	배열과 흡사하지만 크기가 자동으로 조절된다. 

	장점 : 임의접근 ( 인덱스를 사용해서 O(1)의 시간복잡도로 원소접근가능)
	단점 : 중간에 원소 삽입/삭제 할때 비용이 O(n)만큼 든다.

*/
void Enemy::Init(float posX, float posY)
{
	pos = {posX, posY};
	moveSpeed = 0.2f;
	angle = -90.0f;
	isAlive = true;
	size = 10;
	animationFrame = 0;
	elapsedFrame = 0;
	elapsedTime = 0.0f;
	enemyMaxX = WINSIZE_X;

	image = ImageManager::GetInstance()->AddFramedImage("Normal_Enemy", TEXT("Image/ufo.bmp"), 530, 32, 10, 1,
		true, RGB(255, 0, 255));
	moveRight = true;	
	
	missileManager = new MissileManager();
	missileManager->Init();


	missile = new Missile();
	missile->Init();
	missile->SetPos(pos);
	missile->SetAngle(-135);
	missile->SetIsActived(true);
}

void Enemy::Release()
{
	if (missile)
	{
		missile->Release();
		delete missile;
		missile = nullptr;
	}

	if (missileManager)
	{
		missileManager->Release();
		delete missileManager;
		missileManager = nullptr;
	}

	if (image)
	{
		delete image;
		image = nullptr;
	}
}

void Enemy::Update()
{

	if (isAlive)
	{
		Move();
		elapsedFrame++;
		//missileManager->Update();
		elapsedTime += TimerManager::GetInstance()->GetDeltaTime(); //elapsedTime이 5초가 넘어가면 1씩증가
		if (elapsedTime > 0.03f)
		{
			animationFrame++;
			if (animationFrame > image->getMaxFrameX())
			{
				animationFrame = 0;
			}
			elapsedTime = 0.0f;
		}
	}

	if (missile)
		missile->Update();
}

void Enemy::Render(HDC hdc)
{
	if (isAlive)
	{	
		image->FrameRender(hdc, pos.x, pos.y, animationFrame ,false);
		//RenderRectAtCenter(hdc, pos.x, pos.y, size, size);
	}

	if (missile)
		missile->Render(hdc);
}

void Enemy::Move()
{
	float deltaTime = TimerManager::GetInstance()->GetDeltaTime();
	float actualMoveSpeed = moveSpeed * deltaTime;
	if (moveRight)
	{
		if (pos.x < enemyMaxX)
		{
			pos.x += moveSpeed; // actualMoveSpeed; //* TimerManager::GetInstance()->GetDeltaTime() 곱하면 이미지 사라짐
			if (pos.x >= enemyMaxX)
			{
				moveRight = false;
			}
		}
	}
	else
	{
		if (pos.x > 0)
		{
			pos.x -= moveSpeed; // actualMoveSpeed/* * TimerManager::GetInstance()->GetDeltaTime()*/;
			if (pos.x <= 0)
			{
				moveRight = true;
			}
		}
	}

}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}
