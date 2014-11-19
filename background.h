#ifndef _BACK_H_
#define _BACK_H_
#include "AIE.h"
#include <fstream>

#include <iostream>
using namespace std;

class Background
{
public:
	int GetSprite();
	void SetSprite(unsigned int sprite);
	void MoveBG(float playerXPos, float playerYPos, float deltaT);
	bool Scrolling();
	void SetFile(char* a_filename);
	char CheckGridPosition(float a_x, float a_y);
	float GetBGOffsetX();
	float GetBGOffsetY();
	void Draw();

private:
	static const char CANWALK = '0';
	static const char NOCANWALK = '1';
	const int SCREENWIDTH = 1536.f;
	const int SCREENHEIGHT = 1536.f;
	float x = SCREENWIDTH * .5f;
	float y = SCREENHEIGHT * .5f;
	unsigned int spriteID;
	bool isMoving;

	char map[24][24];

	//might have to initialize in a setter: had to do that when in player
	int BGoffsetX = 6;
	int BGoffsetY = 7;
	char* filename;
	bool beginBlock = true;

};

#endif