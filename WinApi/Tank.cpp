#include "Tank.h"
#include "CommonFunction.h"

void Tank::Init()
{
	pos.x = WINSIZE_X / 2;
	pos.y = WINSIZE_Y;
	size = 100;
	damage = 10;
	name = "ÅÊÅ©";
	rcCollision = GetRectAtCenter(pos.x, pos.y, size, size);
	isFire = false;
	// Æ÷½Å
	barrelSize = 90;
	barrelEnd.x = pos.x;
	barrelEnd.y = pos.y - barrelSize;
	barrelAngle = 3.14f / 4.0f;	// 45µµ
}

void Tank::Release()
{
}

void Tank::Update()
{
	barrelEnd.x = pos.x + barrelSize * cosf(barrelAngle);
	barrelEnd.y = pos.y - barrelSize * sinf(barrelAngle);
}

void Tank::Render(HDC hdc)
{
	// ¸öÅë
	RenderEllipseAtCenter(hdc, pos.x, pos.y, size, size);
	// Æ÷½Å
	MoveToEx(hdc, pos.x, pos.y, NULL);
	LineTo(hdc, barrelEnd.x, barrelEnd.y);
}

void Tank::Move()
{
}

void Tank::Fire()
{
	isFire = true;
}

void Tank::RotateBarrel(float angle)
{
	barrelAngle += angle;
}

POINT Tank::GetBarrelPos()
{
	return barrelEnd;
}
void Tank::Dead()
{
}

Tank::Tank()
{
}

Tank::~Tank()
{
}
