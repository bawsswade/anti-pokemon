#include "Enemy.h"

Enemy::Enemy()
{
	Direction = down;
}
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

float Enemy::CheckNextXPos(float deltaT, float playerX)
{
	/*float temp;

	//set LorR
	if (playerX < x)
	{
	x -= speed * deltaT;
	LorR = 0;
	}
	if (playerX > x)
	{
	x += speed * deltaT;
	LorR = 1;
	}

	if (LorR = 0)
	{
	return temp = x - speed * deltaT;
	}
	else if (LorR = 1)
	{
	return temp = x + speed * deltaT;
	}
	return x;*/
	float temp;
	if (Direction == 1)
		return temp = x - (speed * deltaT);
	else if (Direction == 3)
		return temp = x + (speed * deltaT);
	else
		return x;
}

float Enemy::CheckNextYPos(float deltaT, float playerY)
{
	/*float temp;
	//set UorD
	if (playerY > y)
	{
	y += speed * deltaT;
	UorD = 0;
	}
	if (playerY < y)
	{
	y -= speed * deltaT;
	UorD = 1;
	}

	if (UorD = 0)
	{
	return temp = y + speed * deltaT;
	}
	else if (UorD = 1)
	{
	return temp = y - speed * deltaT;
	}
	return y;*/
	float temp;
	if (Direction == 0)
		return temp = y - (speed * deltaT);
	else if (Direction == 2)
		return temp = y + (speed * deltaT);
	else
		return y;
}

void Enemy::ChangeDir(float pX, float pY)
{
	if (Direction == down)
		Direction = left;
	else if (Direction == left)
		Direction = up;
	else if (Direction == up)
		Direction = right;
	else if (Direction == right)
		Direction = down;
}

void Enemy::SetActive(bool a_isActive)
{
	isActive = a_isActive;
}

bool Enemy::GetActive()
{
	return isActive;
}

void Enemy::Move(float deltaT, float pX, float pY)
{
	if (Direction == down){
		y -= speed * deltaT;
		if (pY > y){
			if (pX < x)
				Direction = left;
			else
			Direction = right;
		}
	}
	else if (Direction == left){
		x -= speed * deltaT;
		if (pX > x){
			if (pY < y)
				Direction = down;
			else
				Direction = up;
		}
	}
	else if (Direction == up){
		y += speed * deltaT;
		if (pY < y){
			if (pX < x)
				Direction = left;
			else
				Direction = right;
		}
	}
	else if (Direction == right){
		x += speed * deltaT;
		if (pX < x){
			if (pY < y)
				Direction = down;
			else
				Direction = up;
		}
	}

	MoveSprite(spriteID, x, y);
	//cout << x << ", " << y << endl;
}

void Enemy::Draw()
{
	if (isActive)
		DrawSprite(spriteID);
}

Enemy::~Enemy(){}