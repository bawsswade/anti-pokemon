#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "AIE.h"
#include <cmath>
#include <iostream>
using namespace std;

class Enemy
{
public:
	void SetPosition(float a_x, float a_y);
	float GetX();
	float GetY();

	void SetSprite(unsigned int sprite);
	unsigned int GetSprite();

	void SetSize(float a_width, float a_height);
	float GetWidth();
	float GetHeight();

	float CheckNextXPos(float deltaT);
	float CheckNextYPos(float deltaT);
	void Move(float deltaT, float playerX, float playerY, char gridValue);

private:
	bool moveDir = 0;
	bool LorR = 0;
	bool UorD = 0;
	float x, y;
	float width, height;
	unsigned int spriteID;
	int speed = 150.f;
};

#endif