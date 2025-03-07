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

	for (size_t i = 0; i < missiles.size(); i++)
	{
		missiles[i]->Update();
	}
}

void Tank::Render(HDC hdc)
{
	// ����
	RenderEllipseAtCenter(hdc, pos.x, pos.y, size, size);
	// ����
	MoveToEx(hdc, pos.x, pos.y, NULL);
	LineTo(hdc, barrelEnd.x, barrelEnd.y);
	//�̻��� �׸���
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
	missile->Init(barrelEnd, barrelAngle); //���ſ��� �߻�
	missiles.push_back(missile); //�迭�� �߰�
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
