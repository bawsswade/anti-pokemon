#include "background.h"

float Background::GetBGOffsetX()
{
	return BGoffsetX;
}

float Background::GetBGOffsetY()
{
	return BGoffsetY;
}

void Background::SetSprite(unsigned int sprite)
{
	spriteID = sprite;
}

int Background::GetSprite()
{
	return spriteID;
}

bool Background::Scrolling()
{
	return isMoving;
}

void Background::MoveBG(float playerXPos, float playerYPos, float deltaT)
{
	if (playerXPos < SCREENWIDTH * 0.f && IsKeyDown(GLFW_KEY_LEFT))
	{
		x += deltaT * 150;
		if (x > SCREENWIDTH)
		{
			x = SCREENWIDTH;
			isMoving = false;
		}
		else
			isMoving = true;
	}
	else if (playerXPos > SCREENWIDTH * 1.f  && IsKeyDown(GLFW_KEY_RIGHT))
	{
		x -= deltaT * 150;
		if (x < 0)
		{
			x = 0;
			isMoving = false;
		}
		else
			isMoving = true;
	}
	else if (playerYPos > SCREENHEIGHT * 1.f  && IsKeyDown(GLFW_KEY_UP))
	{
		y -= deltaT * 150;
		if (y < 0)
		{
			y = 0;
			isMoving = false;
		}
		else
			isMoving = true;
	}
	else if (playerYPos < SCREENHEIGHT * 0.f && IsKeyDown(GLFW_KEY_DOWN))
	{
		y += deltaT * 150;
		if (y > SCREENHEIGHT)
		{
			y = SCREENHEIGHT;
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

void Background::SetFile(char* a_filename)
{
	filename = a_filename;
	fstream file;
	file.open(filename, std::fstream::in);
	if (file.is_open()){
		for (int i = 24; i >= 0; i--)
		{
			for (int j = 0; j < 24; j++)
			{
				file >> map[j][i];
			}
		}
	}
	else
		cout << "cant be found";
	file.close();
}

char Background::CheckGridPosition(float a_x, float a_y)
{
	int mapX = (a_x / 64) /*+ BGoffsetX*/;
	int mapY = (a_y / 64) /*+ BGoffsetY*/;

	//cout << mapX << ", " << mapY << ": " << map[mapX][mapY] << endl;
	//cout << x << " - " << prevX << " = " << check << endl;
	//DEBUGGING////////////////////////////////////////////////////////////
	/*for (int a = 0; a < 24; a++){
		for (int b = 0; b < 24; b++){
			string sX(1, map[a][b]);
			const char* cGrid = sX.c_str();
			DrawString(cGrid, (a)*64+5, (b)*64+5, SColour(0,255,0,255));
		}
	}*/

	/*for (int a = BGoffsetX; a < BGoffsetX +12; a++){
	for (int b = BGoffsetY; b <BGoffsetY + 12; b++){
	string sX(1, map[a][b]);
	const char* cGrid = sX.c_str();
	DrawString(cGrid, (a - 6) * 64, (b - 6) * 64, SColour(0, 255, 0, 255));
	}
	}
	//DEBUGGING////////////////////////////////////////////////////////////*/
	return map[mapX][mapY];
}

void Background::Draw()
{
	DrawSprite(spriteID);
}