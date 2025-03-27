#include "Player.h"
#include "CommonFunction.h"
#include "KeyManager.h"
#include "MissileManager.h"
#include "Missile.h"

void Player::Init()
{
	pos.x = WINSIZE_X / 2;
	pos.y = WINSIZE_Y / 2;
	moveSpeed = 500.0f;
	angle = -90.0f;
	isAlive = true;
	size = 30;
	animationFrame = 0;
	elapsedFrame = 0;
	rcCollision = GetRectAtCenter(pos.x, pos.y, size, size);
	isShoot = false;

	playerImage = new Image();
	playerImage = ImageManager::GetInstance()->AddImage("Rocket", TEXT("Image/rocket.bmp"), 52, 64,
														true, RGB(255, 0, 255));

	missileImage = new Image();
	missileImage = ImageManager::GetInstance()->AddImage("Bullet", TEXT("Image/bullet.bmp"), 21, 21,
														true, RGB(255, 0, 255));
	missiles = new MissileManager();
	missiles->Init();

	key = new KeyManager();
	KeyManager::GetInstance()->Init();
	key = KeyManager::GetInstance();
}

void Player::Release()
{
	if (missiles)
	{
		missiles->Release();
		delete missiles;
		missiles = nullptr;
	}
	if (playerImage)
	{
		playerImage->Release();
		delete playerImage;
		playerImage = nullptr;
	}
	if (key)
	{
		key->Release();
		delete key;
		key = nullptr;
	}
}

void Player::Render(HDC hdc)
{
	if (isAlive)
	{
		playerImage->PlayerRender(hdc, pos.x, pos.y);
		//RenderRectAtCenter(hdc, pos.x, pos.y, size, size);
	}
	if (isShoot)
	{
		missiles->Render(hdc);
		missileImage->Render(hdc, pos.x, pos.y);
	}
}

void Player::Update()
{
	if (isAlive)
	{
		Move();
	}
	if (isShoot)
	{
		missiles->Update();
	}
}

void Player::Move()
{
	key = KeyManager::GetInstance();

	if (key->IsStayKeyDown('A'))
	{
		pos.x -= moveSpeed * TimerManager::GetInstance()->GetDeltaTime();
	}
	else if (key->IsStayKeyDown('D'))
	{
		pos.x += moveSpeed * TimerManager::GetInstance()->GetDeltaTime();
	}
	else if (key->IsStayKeyDown('S'))
	{
		pos.y += moveSpeed * TimerManager::GetInstance()->GetDeltaTime();
	}
	else if (key->IsStayKeyDown('W'))
	{
		pos.y -= moveSpeed * TimerManager::GetInstance()->GetDeltaTime();
	}
}

void Player::Shoot()
{
	key = KeyManager::GetInstance();

	if (key->IsStayKeyDown(VK_SPACE))
	{
		isShoot = true;
		Update();
	}
}
