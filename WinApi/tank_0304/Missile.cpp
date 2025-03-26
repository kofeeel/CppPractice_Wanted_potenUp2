#include "Missile.h"
#include "CommonFunction.h"
#include "config.h"

void Missile::Init(POINT startPos, float direction)
{
	pos = startPos;
	angle = direction;	
	fSpeed = 10.0;
}

void Missile::Release()
{
}

void Missile::Update()
{
	if (isActive) 
	{
		return;
	}

	pos.x += cos(angle) * fSpeed;  //코사인 90은 0
	pos.y -= sin(angle) * fSpeed;
	
	if (IsDisappear())
	{
		isActive = false;
	}
}

void Missile::Render(HDC hdc)
{
	if (!isActive)
	{
		return;
	}

	RenderEllipseAtCenter(hdc, pos.x, pos.y, size, size);
}

bool Missile::IsDisappear()
{
	return (pos.x < 0 || pos.x > WINSIZE_X || pos.y < 0 || pos.y > WINSIZE_Y);
}

bool Missile::GetActive()
{
	return isActive;
}

Missile::Missile() 
{
	isActive = true;
	fSpeed = 10.0;
	size = 30;
}

Missile::~Missile()
{
}
