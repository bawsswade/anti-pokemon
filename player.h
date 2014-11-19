#include "AIE.h"
#include "Weapon.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
//#include <Windows.h>

#ifndef _PLAYER_H_
#define _PLAYER_H_

const int SCREENWIDTH = 1536;
const int SCREENHEIGHT = 1536;
const int MAX_BULLETS = 10;

class Player
{
public:
	Player();
	~Player();

	// moves player checking restrictions
	void MovePlayer(float deltaT, bool scrolling, char gridValue);
	/*		- deltaT is used to to increment movement
			- scrolling checks if the BG is moving (if BG moving, dont move player)
			- checks next gridValue to see if can move 
	*/
	float CheckNextXPos(float deltaT);
	float CheckNextYPos(float deltaT);

	void Shoot();

	int GetSprite();
	float GetXPos();
	float GetYPos();
	void SetSprite(unsigned int sprite);
	void SetSize(float a_width, float a_height);
	float GetWidth();
	float GetHeight();
	int GetDirection();

	void Draw();

	void SetPos(float a_x, float a_y);
	void UpdateWeapon(float deltaT);

	Weapon& GetInactiveBullet();
	
	//vector<Weapon> Rock;
	Weapon Rock[MAX_BULLETS];

	enum movement{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
	movement move = DOWN;

private:
	static const char CANWALK = '0';
	static const char NOCANWALK = '1';
	const float ONEBLOCK = 16.f;

	
	unsigned int spriteID;
	float x = SCREENWIDTH * .5f;
	float y = SCREENHEIGHT * .5f;
	float timePassed = 0;
	float lastChange = 0;
	bool changeSprite = 0;  
	bool changeSpriteAgain = 0;
	float width;
	float height;
	float speed = 150.f;
	
	float currentReloadBulletTime = 0.0f;
	float maxBulletReloadTime = 0.25f;

	//BG shit
	bool beginBlock = true;
};


#endif
