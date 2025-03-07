#include "Tank.h"
#include "CommonFunction.h"

void Tank::Init()
{
	pos.x = WINSIZE_X / 2;
	pos.y = WINSIZE_Y;
	size = 100;
	damage = 10;
	name = "탱크";
	rcCollision = GetRectAtCenter(pos.x, pos.y, size, size);

	// 포신
	barrelSize = 90;
	barrelEnd.x = pos.x;
	barrelEnd.y = pos.y - barrelSize;
	barrelAngle = 3.14f / 4.0f;	// 45도
	
}

void Tank::Release()
{
}

void Tank::Update()
{
	barrelEnd.x = pos.x + barrelSize * cosf(barrelAngle);
	barrelEnd.y = pos.y - barrelSize * sinf(barrelAngle);

	for (size_t i = 0; i < missiles.size(); i++)
	{
		missiles[i]->Update();
	}
}

void Tank::Render(HDC hdc)
{
	// 몸통
	RenderEllipseAtCenter(hdc, pos.x, pos.y, size, size);
	// 포신
	MoveToEx(hdc, pos.x, pos.y, NULL);
	LineTo(hdc, barrelEnd.x, barrelEnd.y);
	//미사일 그리기
	for (auto& missile : missiles)
	{
		missile->Render(hdc);
	}
}

void Tank::Move()
{
}

void Tank::Fire()
{
	Missile* missile = new Missile();
	missile->Init(barrelEnd, barrelAngle); //포신에서 발사
	missiles.push_back(missile); //배열에 추가
}

void Tank::RotateBarrel(float angle)
{
	barrelAngle += angle;
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
