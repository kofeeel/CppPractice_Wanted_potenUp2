#include "Tank.h"
#include "CommonFunction.h"

void Tank::Init()
{
	pos.x = WINSIZE_X / 2;
	pos.y = WINSIZE_Y;
	size = 100;
	damage = 10;
	name = "��ũ";
	rcCollision = GetRectAtCenter(pos.x, pos.y, size, size);
	isFire = false;
	// ����
	barrelSize = 90;
	barrelEnd.x = pos.x;
	barrelEnd.y = pos.y - barrelSize;
	barrelAngle = 3.14f / 4.0f;	// 45��
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
	// ����
	RenderEllipseAtCenter(hdc, pos.x, pos.y, size, size);
	// ����
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
