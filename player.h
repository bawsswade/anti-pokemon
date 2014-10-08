#include "AIE.h"
//#include <Windows.h>

#ifndef _PLAYER_H_
#define _PLAYER_H_

const int SCREENWIDTH = 600;
const int SCREENHEIGHT = 600;

enum movement{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class player
{
public:
	void MovePlayer(float deltaT, bool scrolling);
	int GetSprite();
	float GetXPos();
	float GetYPos();
	void SetSprite(unsigned int sprite);

private:
	unsigned int spriteID;
	unsigned char a;
	//COORD loc = {SCREENWIDTH * .5f, SCREENHEIGHT * .5f};
	float x = SCREENWIDTH * .5f;
	float y = SCREENHEIGHT * .5f;
	float timePassed = 0;
	float lastChange = 0;
	bool changeSprite = 0;  
	bool changeSpriteAgain = 0;

	movement move = DOWN;
};


#endif
