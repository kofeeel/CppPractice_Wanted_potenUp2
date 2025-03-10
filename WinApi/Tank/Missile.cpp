#include "Missile.h"
#include "CommonFunction.h"
#include "config.h"

void Missile::Init() //�̻����� �����ġ, ����
{
	pos.x = 0;
	pos.y = 0;
	size = 20;
	angle = 3.14f / 4.0f;
	fSpeed = 10.0;
	InScreen = false;
	//������ ����
}

void Missile::Release()
{
}

void Missile::Update() //�̻����� ���� ��ġ ����
{
	if (InScreen == true)
	{
		pos.x += cos(angle) * fSpeed;  //�ڻ��� 90�� 0
		pos.y -= sin(angle) * fSpeed;
		InScreenCheck();
	}
}

void Missile::Render(HDC hdc)
{
	if (InScreen)
	{
		RenderEllipseAtCenter(hdc, pos.x, pos.y, size, size);
	}	
}

bool Missile::InScreenCheck()
{
	if (pos.x < 0 || pos.x > WINSIZE_X || pos.y < 0 || pos.y > WINSIZE_Y)
	{
		InScreen = false;
		return InScreen;
	}
	else
	{
		InScreen = true;
		return InScreen;
	}
}

void Missile::ReadyToFire(POINT pos, float angle)
{
	this->pos = pos;
	this->angle = angle;
	InScreen = true;
}

Missile::Missile() 
{
	Init();
}

Missile::~Missile()
{
}



