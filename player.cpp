#include "player.h"

void player::MovePlayer(float deltaT, bool scrolling)
{
	timePassed += deltaT;
	switch (move)
	{
	case LEFT:
		if (IsKeyDown(GLFW_KEY_LEFT))
		{
			if (!scrolling)
				x -= 150 * deltaT;

			//change sprite every .2 sec
			if (timePassed - lastChange > .2f)
			{
				if (changeSprite == 0)
				{
					spriteID = CreateSprite("./images/playerLeft.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
					changeSprite = 1;
					lastChange = timePassed;
				}
				else if (changeSprite = 1)
				{
					spriteID = CreateSprite("./images/playerWalkLeft.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
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
			spriteID = CreateSprite("./images/playerRight.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		else if (IsKeyDown(GLFW_KEY_UP)){
			move = UP;
			spriteID = CreateSprite("./images/playerUp.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		else if (IsKeyDown(GLFW_KEY_DOWN)){
			move = DOWN;
			spriteID = CreateSprite("./images/playerDown.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		// so it always end on standing walking sprite
		else 
			spriteID = CreateSprite("./images/playerLeft.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		break;

	case RIGHT:
		if (IsKeyDown(GLFW_KEY_RIGHT))
		{
			if (!scrolling)
				x += 150 * deltaT;
			//change sprite every .2 sec
			if (timePassed - lastChange > .2f)
			{
				if (changeSprite == 0)
				{
					spriteID = CreateSprite("./images/playerRight.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
					changeSprite = 1;
					lastChange = timePassed;
				}
				else if (changeSprite = 1)
				{
					spriteID = CreateSprite("./images/playerWalkRight.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
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
			spriteID = CreateSprite("./images/playerUp.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		else if (IsKeyDown(GLFW_KEY_DOWN)){
			move = DOWN;
			spriteID = CreateSprite("./images/playerDown.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		else if (IsKeyDown(GLFW_KEY_LEFT)){
			move = LEFT;
			spriteID = CreateSprite("./images/playerLeft.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		// so it always end on standing walking sprite
		else
			spriteID = CreateSprite("./images/playerRight.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		break;

	case UP:
		if (IsKeyDown(GLFW_KEY_UP))
		{
			if (!scrolling)
				y += 150 * deltaT;
			//change sprite 
			if (timePassed - lastChange > .2f)
			{
				if (changeSprite == 0)
				{
					spriteID = CreateSprite("./images/playerUp.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
					changeSprite = 1;
					lastChange = timePassed;
				}
				else if (changeSprite = 1)
				{
					if (changeSpriteAgain){
						spriteID = CreateSprite("./images/playerWalkUp1.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
						changeSpriteAgain = false;
					}
					else if (!changeSpriteAgain){
						spriteID = CreateSprite("./images/playerWalkUp2.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
						changeSpriteAgain = true;
					}
					changeSprite = 0;
					lastChange = timePassed;
				}
			}
			//stop if end of screen
			if (y >= SCREENHEIGHT - SCREENHEIGHT * .03f)
			{
				y = SCREENHEIGHT - SCREENHEIGHT * .03f;
			}
		}
		else if (IsKeyDown(GLFW_KEY_RIGHT)){
			move = RIGHT;
			spriteID = CreateSprite("./images/playerRight.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		else if (IsKeyDown(GLFW_KEY_DOWN)){
			move = DOWN;
			spriteID = CreateSprite("./images/playerDown.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		else if (IsKeyDown(GLFW_KEY_LEFT)){
			move = LEFT;
			spriteID = CreateSprite("./images/playerLeft.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		// so it always end on standing walking sprite
		else
			spriteID = CreateSprite("./images/playerUp.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		break;

	case DOWN:
		if (IsKeyDown(GLFW_KEY_DOWN))
		{
			if (!scrolling)
				y -= 150 * deltaT;
			//change sprite
			if (timePassed - lastChange > .2f)
			{
				if (changeSprite == 0)
				{
					spriteID = CreateSprite("./images/playerDown.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
					changeSprite = 1;
					lastChange = timePassed;
				}
				else if (changeSprite = 1)
				{
					if (changeSpriteAgain){
						spriteID = CreateSprite("./images/playerWalkDown1.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
						changeSpriteAgain = false;
					}
					else if (!changeSpriteAgain){
						spriteID = CreateSprite("./images/playerWalkDown2.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
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
			spriteID = CreateSprite("./images/playerUp.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		else if (IsKeyDown(GLFW_KEY_RIGHT)){
			move = RIGHT;
			spriteID = CreateSprite("./images/playerRight.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		else if (IsKeyDown(GLFW_KEY_LEFT)){
			move = LEFT;
			spriteID = CreateSprite("./images/playerLeft.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		}
		// so it always end on standing walking sprite
		else
			spriteID = CreateSprite("./images/playerDown.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true);
		break;
	default:
		break;
	}
	MoveSprite(spriteID, x, y);
}

void player::SetSprite(unsigned int sprite)
{
	spriteID = sprite;
}

int player::GetSprite()
{
	return spriteID;
}

float player::GetXPos()
{
	return x;
}

float player::GetYPos()
{
	return y;
}