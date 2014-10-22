#include "player.h"
#include <string>

float Player::CheckNextXPos(float deltaT)
{
	float temp;
	if (IsKeyDown(GLFW_KEY_LEFT))
	{
		return temp = x - speed * deltaT;
	}
	else if (IsKeyDown(GLFW_KEY_RIGHT))
	{
		return temp = x + speed * deltaT;
	}	
	return x;
}

float Player::CheckNextYPos(float deltaT)
{
	float temp;
	if (IsKeyDown(GLFW_KEY_UP))
	{
		return temp = y + speed * deltaT;
	}
	else if (IsKeyDown(GLFW_KEY_DOWN))
	{
		return temp = y - speed * deltaT;
	}
	return y;
}

void Player::MovePlayer(float deltaT, bool scrolling, char gridValue)
{
	timePassed += deltaT;
	switch (move)
	{
	case LEFT:
		if (IsKeyDown(GLFW_KEY_LEFT))
		{
			// check grid to determine if can walk or not
			if (!scrolling && (gridValue != NOCANWALK))
				x -= speed * deltaT;

			// offsets grid if background is scrolling (grid is 16 pixels)
			/*if (scrolling)
			{
				if (beginBlock){
					prevX = x;
					beginBlock = false;
				}
				else{
					check = prevX - x ;
				}
				if (check > 1){
					BGoffsetX--;
					beginBlock = true;
					check = 0;
				}
			}*/


			//change sprite every .2 sec
			if (timePassed - lastChange > .2f)
			{
				if (changeSprite == 0)
				{
					spriteID = CreateSprite("./images/playerLeft.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
					changeSprite = 1;
					lastChange = timePassed;
				}
				else if (changeSprite = 1)
				{
					spriteID = CreateSprite("./images/playerWalkLeft.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
					changeSprite = 0;
					lastChange = timePassed;
				}
			}
			//stop if end of screen
			if (x <= SCREENWIDTH *.02f)
			{
				x = SCREENWIDTH * .02f;
			}
		}

		else if (IsKeyDown(GLFW_KEY_RIGHT)){
			move = RIGHT;
			spriteID = CreateSprite("./images/playerRight.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		else if (IsKeyDown(GLFW_KEY_UP)){
			move = UP;
			spriteID = CreateSprite("./images/playerUp.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		else if (IsKeyDown(GLFW_KEY_DOWN)){
			move = DOWN;
			spriteID = CreateSprite("./images/playerDown.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		// so it always end on standing walking sprite
		else 
			spriteID = CreateSprite("./images/playerLeft.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		break;

	case RIGHT:
		if (IsKeyDown(GLFW_KEY_RIGHT))
		{
			if (!scrolling && (gridValue != NOCANWALK))
				x += speed * deltaT;
			/*if (gridValue == NOCANWALK)
			{
				x -= speed * deltaT;
			}*/

			// offsets grid if background is scrolling
			/*if (scrolling)
			{
				if (beginBlock){
					prevX = x;
					beginBlock = false;
				}
				else{
 					check = x - prevX;
				}
				if (check > 1){
					BGoffsetX++;
					beginBlock = true;
					check = 0;
				}		
			}*/

			//change sprite every .2 sec
			if (timePassed - lastChange > .2f)
			{
				if (changeSprite == 0)
				{
					spriteID = CreateSprite("./images/playerRight.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
					changeSprite = 1;
					lastChange = timePassed;
				}
				else if (changeSprite = 1)
				{
					spriteID = CreateSprite("./images/playerWalkRight.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
					changeSprite = 0;
					lastChange = timePassed;
				}
			}
			//stop if end of screen
			if (x >= SCREENWIDTH - SCREENWIDTH * .02f)
			{
				x = SCREENWIDTH - SCREENWIDTH * .02f;
			}

		}
		else if (IsKeyDown(GLFW_KEY_UP)){
			move = UP;
			spriteID = CreateSprite("./images/playerUp.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		else if (IsKeyDown(GLFW_KEY_DOWN)){
			move = DOWN;
			spriteID = CreateSprite("./images/playerDown.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		else if (IsKeyDown(GLFW_KEY_LEFT)){
			move = LEFT;
			spriteID = CreateSprite("./images/playerLeft.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		// so it always end on standing walking sprite
		else
			spriteID = CreateSprite("./images/playerRight.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		break;

	case UP:
		if (IsKeyDown(GLFW_KEY_UP))
		{
			if (!scrolling && (gridValue != NOCANWALK))
				y += speed * deltaT;
			/*if (gridValue == NOCANWALK)
			{
				y -= speed * deltaT;
			}*/

			// offsets grid if background is scrolling
			/*if (scrolling)
			{
				if (beginBlock){
					prevY = y;
					beginBlock = false;
				}
				if ((y - prevY) >= ONEBLOCK){
					BGoffsetY++;
					beginBlock = true;
				}
			}*/

			//change sprite 
			if (timePassed - lastChange > .2f)
			{
				if (changeSprite == 0)
				{
					spriteID = CreateSprite("./images/playerUp.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
					changeSprite = 1;
					lastChange = timePassed;
				}
				else if (changeSprite = 1)
				{
					if (changeSpriteAgain){
						spriteID = CreateSprite("./images/playerWalkUp1.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
						changeSpriteAgain = false;
					}
					else if (!changeSpriteAgain){
						spriteID = CreateSprite("./images/playerWalkUp2.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
						changeSpriteAgain = true;
					}
					changeSprite = 0;
					lastChange = timePassed;
				}
			}
			//stop if end of screen
			if (y >= SCREENHEIGHT - SCREENHEIGHT * .02f)
			{
				y = SCREENHEIGHT - SCREENHEIGHT * .02f;
			}
		}
		else if (IsKeyDown(GLFW_KEY_RIGHT)){
			move = RIGHT;
			spriteID = CreateSprite("./images/playerRight.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		else if (IsKeyDown(GLFW_KEY_DOWN)){
			move = DOWN;
			spriteID = CreateSprite("./images/playerDown.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		else if (IsKeyDown(GLFW_KEY_LEFT)){
			move = LEFT;
			spriteID = CreateSprite("./images/playerLeft.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		// so it always end on standing walking sprite
		else
			spriteID = CreateSprite("./images/playerUp.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		break;

	case DOWN:
		if (IsKeyDown(GLFW_KEY_DOWN))
		{
			if (!scrolling && (gridValue != NOCANWALK))
				y -= speed * deltaT;
			/*if (gridValue == NOCANWALK)
			{
				y += speed * deltaT;
			}*/

			// offsets grid if background is scrolling
			/*if (scrolling)
			{
				if (beginBlock){
					prevY = y;
					beginBlock = false;
				}
				if ((prevY - y) >= ONEBLOCK){
					BGoffsetY--;
					beginBlock = true;
				}
			}*/

			//change sprite
			if (timePassed - lastChange > .2f)
			{
				if (changeSprite == 0)
				{
					spriteID = CreateSprite("./images/playerDown.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
					changeSprite = 1;
					lastChange = timePassed;
				}
				else if (changeSprite = 1)
				{
					if (changeSpriteAgain){
						spriteID = CreateSprite("./images/playerWalkDown1.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
						changeSpriteAgain = false;
					}
					else if (!changeSpriteAgain){
						spriteID = CreateSprite("./images/playerWalkDown2.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
						changeSpriteAgain = true;
					}
					changeSprite = 0;
					lastChange = timePassed;
				}
			}
			//stop if end of screen
			if (y <= SCREENHEIGHT * .03f)
			{
				y = SCREENHEIGHT * .03f;
			}
		}
		else if (IsKeyDown(GLFW_KEY_UP)){
			move = UP;
			spriteID = CreateSprite("./images/playerUp.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		else if (IsKeyDown(GLFW_KEY_RIGHT)){
			move = RIGHT;
			spriteID = CreateSprite("./images/playerRight.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		else if (IsKeyDown(GLFW_KEY_LEFT)){
			move = LEFT;
			spriteID = CreateSprite("./images/playerLeft.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		}
		// so it always end on standing walking sprite
		else
			spriteID = CreateSprite("./images/playerDown.png", SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f, true);
		break;
	default:
		break;
	}
	MoveSprite(spriteID, x, y);
}

void Player::SetSprite(unsigned int sprite)
{
	spriteID = sprite;
}

int Player::GetSprite()
{
	return spriteID;
}

float Player::GetXPos()
{
	return x;
}

float Player::GetYPos()
{
	return y;
}

void Player::SetPos(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

void Player::SetSize(float a_width, float a_height)
{
	width = a_width;
	height = a_height;
}

float Player::GetWidth()
{
	return width;
}

float Player::GetHeight()
{
	return height;
}
