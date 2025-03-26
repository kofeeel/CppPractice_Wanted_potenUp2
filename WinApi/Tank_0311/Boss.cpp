#include "Boss.h"
#include "CommonFunction.h"
#include "Tank.h"

void Boss::Init(Tank* tank)
{
	position.x = uid_0_WINSIZEX(dre);
	position.y = 0;
	target = tank;
	hp = 500;
	size = 500;
	speed = 10;
	damage = 100;
}

void Boss::Release()
{

}

void Boss::Update()
{
	if (hp <= 0) return;

	Move();
}

void Boss::Render(HDC hdc)
{
	if (hp <= 0) return;
	HBRUSH hBrush = CreateSolidBrush(RGB(256, 256, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	RenderEllipseAtCenter(hdc, position.x, position.y, size, size);

	SelectObject(hdc, hOldBrush);
	DeleteObject(hBrush);
}

void Boss::Move()
{
	position.x += 3 * speed;
}
