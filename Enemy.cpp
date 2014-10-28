#include "Enemy.h"

void Enemy::SetPosition(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

float Enemy::GetX()
{
	return x;
}

float Enemy::GetY()
{
	return y;
}

void Enemy::SetSprite(unsigned int sprite)
{
	spriteID = sprite;
}

unsigned int Enemy::GetSprite()
{
	return spriteID;
}

void Enemy::SetSize(float a_width, float a_height)
{
	width = a_width;
	height = a_height;
}

float Enemy::GetWidth()
{
	return width;
}

float Enemy::GetHeight()
{
	return height;
}

float Enemy::CheckNextXPos(float deltaT)
{
	float temp;
	if (LorR = 0)
	{
		return temp = x - speed * deltaT;
	}
	else if (LorR = 1)
	{
		return temp = x + speed * deltaT;
	}
	return x;
}

float Enemy::CheckNextYPos(float deltaT)
{
	float temp;
	if (UorD = 0)
	{
		return temp = y + speed * deltaT;
	}
	else if (UorD = 1)
	{
		return temp = y - speed * deltaT;
	}
	return y;
}

void Enemy::SetActive(bool a_isActive)
{
	isActive = a_isActive;
}

bool Enemy::GetActive()
{
	return isActive;
}

void Enemy::Move(float deltaT, float playerX, float playerY, char gridValue)
{
	if (moveDir == 1)
	{
		// left
		if (playerX < x /*&& gridValue != '1'*/)
		{
			x -= speed * deltaT;
			LorR = 0;
		}
		//right
		if (playerX > x /*&& gridValue != '1'*/)
		{
			x += speed * deltaT;
			LorR = 1;
		}
		if (abs(playerX - x) < 10.f || (gridValue == '1'))
			moveDir = 0;
	}
	else{
		//up
		if (playerY > y /*&& gridValue != '1'*/)
		{
			y += speed * deltaT;
			UorD = 0;
		}
		//down
		if (playerY < y /*&& gridValue != '1'*/)
		{
			y -= speed * deltaT;
			UorD = 1;
		}
		if (abs(playerY - y) < 10.f || (gridValue == '1'))
			moveDir = 1;
	}
	MoveSprite(spriteID, x, y);
	//cout << x << ", " << y << endl;
}