#include "Weapon.h"

Weapon::Weapon()
{
	isActive = false;
}

Weapon::~Weapon()
{

}

unsigned int Weapon::GetSpriteID()
{
	return spriteID;
}

float Weapon::GetY()
{
	return y;
}

float Weapon::GetX()
{
	return x;
}

void Weapon::SetY(float a_y)
{
	y = a_y;
}

void Weapon::SetX(float a_x)
{
	x = a_x;
}

float Weapon::GetVelocity()
{
	return velocity;
}

bool Weapon::GetActive()
{
	return isActive;
}

int Weapon::GetDirection()
{
	return direction;
}

void Weapon::SetActive(bool a_isActive)
{
	isActive = a_isActive;
}

void Weapon::InitializeBullet(float a_x, float a_y, int dir)
{
	x = a_x;
	y = a_y;
	height = 8.f;
	width = 8.f;
	velocity = 250.f;
	spriteID = CreateSprite("./images/rock.png", width, height, true);
	direction = dir;
	isActive = true;
}

void Weapon::Update(float deltaT, int num, char tile)
{
	if (isActive)
	{
		if (num == 3)
		{
			y -= deltaT *velocity;
		}
		else if (num == 2)
		{
			y += deltaT * velocity;
		}
		else if (num == 0)
		{
			x -= deltaT * velocity;
		}
		else if (num == 1)
		{
			x += deltaT *= velocity;
		}
	}
	if (tile == '1')
		isActive = false;
}

void Weapon::Draw()
{
	//MoveSprite(spriteID, x, y);
	if (isActive)
	{
		MoveSprite(spriteID, x, y);
		DrawSprite(spriteID);
	}
 }

