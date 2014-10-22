#include "AIE.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
//#include <Windows.h>

#ifndef _PLAYER_H_
#define _PLAYER_H_



const int SCREENWIDTH = 1536;
const int SCREENHEIGHT = 1536;

class Player
{
public:
	//player();
	//~player();

	// moves player checking restrictions
	void MovePlayer(float deltaT, bool scrolling, char gridValue);
	/*		- deltaT is used to to increment movement
			- scrolling checks if the BG is moving (if BG moving, dont move player)
			- checks next gridValue to see if can move 
	*/
	float CheckNextXPos(float deltaT);
	float CheckNextYPos(float deltaT);

	int GetSprite();
	float GetXPos();
	float GetYPos();
	void SetSprite(unsigned int sprite);
	void SetSize(float a_width, float a_height);
	float GetWidth();
	float GetHeight();

	void SetPos(float a_x, float a_y);
	
	
private:
	enum movement{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	static const char CANWALK = '0';
	static const char NOCANWALK = '1';
	const float ONEBLOCK = 16.f;

	
	unsigned int spriteID;
	float x = 300;
	float y = SCREENHEIGHT * .5f;
	float timePassed = 0;
	float lastChange = 0;
	bool changeSprite = 0;  
	bool changeSpriteAgain = 0;
	float width;
	float height;
	int speed = 150.f;
	
	movement move = DOWN;

	//BG shit
	bool beginBlock = true;
};


#endif
