#ifndef _BACK_H_
#define _BACK_H_
#include "AIE.h"

#include <iostream>
using namespace std;

class background
{
public:
	int GetSprite();
	void SetSprite(unsigned int sprite);
	void MoveBG(float playerXPos, float playerYPos, float deltaT);
	bool Scrolling();

private:
	const int SCREENWIDTH = 600;
	const int SCREENHEIGHT = 600;
	float x = SCREENWIDTH * .5f;
	float y = SCREENHEIGHT * .5f;
	unsigned int spriteID;
	bool isMoving;
};

#endif