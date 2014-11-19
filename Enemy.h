#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "AIE.h"
#include <cmath>
#include <iostream>
#include "background.h"
using namespace std;




class Enemy
{
public:
	
	Enemy();
	void SetPosition(float a_x, float a_y);
	float GetX();
	float GetY();

	void SetSprite(unsigned int sprite);
	unsigned int GetSprite();

	void SetSize(float a_width, float a_height);
	float GetWidth();
	float GetHeight();
	
	float CheckNextXPos(float deltaT, float playerX);
	float CheckNextYPos(float deltaT, float playerY);
	void ChangeDir(float pX, float pY);
	void Move(float deltaT, float pX, float pY);

	void SetActive(bool a_isActive);
	bool GetActive();

	void Draw();
	~Enemy();

private:
	enum dir{
		down,
		left,
		up,
		right
	};
	dir Direction;

	float x, y;
	float width, height;
	unsigned int spriteID;
	float speed = 125.f;
	bool isActive = false;
};

#endif