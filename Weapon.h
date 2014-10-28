#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "AIE.h"

class Weapon
{
public:
	Weapon();
	~Weapon();
	void InitializeBullet(float a_x, float a_y, int dir);
	void Draw();
	void Update(float deltaT, int num, char tile);

	float GetY();
	float GetX();
	bool GetActive();
	void SetActive(bool a_isActive);
	void SetY(float a_y);
	void SetX(float a_x);
	int GetDirection();

	float GetVelocity();

	unsigned int GetSpriteID();
	
	
private:
	float x; 
	float y;
	float width;
	float height;
	float velocity;
	unsigned int spriteID;
	bool isActive;
	int direction;
	
};

#endif