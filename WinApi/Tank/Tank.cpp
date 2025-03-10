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

	//�̻��� ����
	missile = new Missile();
}

void Tank::Release()
{
	
	delete missile;
}

void Tank::Update()
{
	barrelEnd.x = pos.x + barrelSize * cosf(barrelAngle);
	barrelEnd.y = pos.y - barrelSize * sinf(barrelAngle);
	missile->Update();
}

void Tank::Render(HDC hdc)
{
	// ����
	RenderEllipseAtCenter(hdc, pos.x, pos.y, size, size);
	// ����
	MoveToEx(hdc, pos.x, pos.y, NULL);
	LineTo(hdc, barrelEnd.x, barrelEnd.y);

	missile->Render(hdc);
}

void Tank::Move()
{
}

void Tank::Fire()
{
	bool isFire;        //ȭ��ȿ� �̻��� ������ true
	isFire = missile->InScreenCheck();
	//�̻��� pos, angle�� barrelEnd, barrelAngle�ֱ�
	if (false == isFire)
	{
		missile->ReadyToFire(barrelEnd, barrelAngle);
	}
	
}

void Tank::Burst()
{
}


//void Tank::MachineGun()
//{
//	bool isFire;        //ȭ��ȿ� �̻��� ������ true
//
//	for (int i = 0; i < 10; i++)
//	{
//		isFire = LoadedMissile[i]->InScreenCheck();
//		//�̻��� pos, angle�� barrelEnd, barrelAngle�ֱ�
//		if (false == isFire)
//		{
//			missile->ReadyToFire(barrelEnd, barrelAngle);
//		}
//	}
//}

void Tank::RotateBarrel(float angle)
{
	barrelAngle += angle;
}

void Tank::Dead()
{
}

Tank::Tank()
{
	Init();
	missiles.clear();
}

Tank::~Tank()
{
}
