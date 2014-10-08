#include "background.h"

void background::SetSprite(unsigned int sprite)
{
	spriteID = sprite;
}

int background::GetSprite()
{
	return spriteID;
}

bool background::Scrolling()
{
	return isMoving;
}

void background::MoveBG(float playerXPos, float playerYPos, float deltaT)
{
	if (playerXPos < SCREENWIDTH * .4f && IsKeyDown(GLFW_KEY_LEFT))
	{
		x += deltaT * 150;
		if (x > SCREENWIDTH * .85f)
		{
			x = SCREENWIDTH * .85f;
			isMoving = false;
		}
		else
			isMoving = true;
	}
	else if (playerXPos > SCREENWIDTH * .6f && IsKeyDown(GLFW_KEY_RIGHT))
	{
		x -= deltaT * 150;
		if (x < SCREENWIDTH * .2f)
		{
			x = SCREENWIDTH * .2f;
			isMoving = false;
		}
		else
			isMoving = true;
	}
	else if (playerYPos > SCREENHEIGHT * .6f && IsKeyDown(GLFW_KEY_UP))
	{
		y -= deltaT * 150;
		if (y < SCREENHEIGHT * .25f)
		{
			y = SCREENWIDTH * .25f;
			isMoving = false;
		}
		else
			isMoving = true;
	}
	else if (playerYPos < SCREENHEIGHT * .4f && IsKeyDown(GLFW_KEY_DOWN))
	{
		y += deltaT * 150;
		if (y > SCREENHEIGHT * .75f)
		{
			y = SCREENWIDTH * .75f;
			isMoving = false;
		}
		else
			isMoving = true;
	}
	else
	{
		isMoving = false;
	}
	MoveSprite(spriteID, x, y);
}