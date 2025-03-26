#include "Attack.h"
#include "Character.h"

#include "Image.h"

Attack::Attack()
{

}

Attack::Attack(const wchar_t* filePath, int width, int height, int maxFrameX, int maxFrameY, bool isTransparent, COLORREF transColor)
{
	image = new Image;
	image->Init(filePath, width, height, maxFrameX, maxFrameY, isTransparent, transColor);
}

void Attack::Init(int damage, FPOINT pos, int radius)
{
	this->damage = damage;
	this->pos = pos;
	this->radius = radius;
	// CollisionManager::GetInstance()->CreateCollisionEllipse(this,this->pos.x, this->pos.y, this->radius);
}

void Attack::BeginAttack()
{
	//CollisionManager::GetInstance()->CreateCollisionEllipse(this, this->pos.x, this->pos.y, this->radius);
	//collision 활성화, 특정프레임 or 애니메이션 중간
	//애니메이션 실행

}

void Attack::EndAttack()
{

}

void Attack::CollisionDetected(GameObject* owner)
{
	Character* enemy = dynamic_cast<Character*>(owner);
	enemy->GetDamage(damage);

}

Attack::~Attack()
{
	if (nullptr != image)
	{
		delete image;
		image = nullptr;
	}
}
