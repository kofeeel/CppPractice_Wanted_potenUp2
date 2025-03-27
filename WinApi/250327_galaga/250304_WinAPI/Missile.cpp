#include "Missile.h"
#include "CommonFunction.h"
#include "Image.h"

void Missile::Init()
{
	pos = { 0, 0 };
	isActived = false;
	color = RGB(255, 255, 255);
	moveSpeed = 3.0f;
	angle = 90.0f;
	size = 5;
	//destination;
	image = new Image;
	image = ImageManager::GetInstance()->AddImage("Bullet", TEXT("Image/bullet.bmp"), 21, 21,
													true,RGB(255, 0, 255));
	/*image->Init(TEXT("Image/bullet.bmp"), 21, 21, 10, 1,
		true, RGB(255, 0, 255));*/
}

void Missile::Release()
{
	if (image)
	{
		image->Release();
		delete image;
		image = nullptr;
	}
}

void Missile::Update()
{
	Move();
	if (isActived && IsOutofScreen())
	{
		isActived = false;
	}
	else
	{
		isActived = true;
	}
}

void Missile::Render(HDC hdc)
{
	if (image)
	{
		//RenderEllipseAtCenter(hdc, pos.x, pos.y, size, size);
		image->Render(hdc, pos.x, pos.y);		
	}
	if (isActived)
	{
		RenderEllipseAtCenter(hdc, pos.x, pos.y, size, size);
	}
}

void Missile::Move()
{
	if (isActived)
	{
		pos.x += moveSpeed * TimerManager::GetInstance()->GetDeltaTime() 
				* cosf(DEG_TO_RAD(-90));
		pos.y += moveSpeed * TimerManager::GetInstance()->GetDeltaTime() 
				* sinf(DEG_TO_RAD(-90));
	}
}

bool Missile::IsOutofScreen()
{
	float right = pos.x + size / 2;
	float left = pos.x - size / 2;
	float top = pos.y - size / 2;
	float bottom = pos.y + size / 2;

	if (right < 0 || left > WINSIZE_X 
		|| bottom < 0 || top > WINSIZE_Y)
		return true;

	return false;
}

Missile::Missile()
{
}

Missile::~Missile()
{
}
