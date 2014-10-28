#include "AIE.h"
#include "player.h"
#include "background.h"
#include "enemy.h"
#include <iostream>
#include <fstream>

using namespace std;

enum GAMESTATE
{
	MAIN_MENU,
	INTRO,
	GAMEPLAY,
	HIGH_SCORES,
	QUIT
};

Player* Red = new Player;
Background BG;
Enemy Pokemon;

bool CheckCollision(float x1, float y1, float x2, float y2, float distance);
void Setupgame();
bool Intro();
void ChangeMaps();

static float lastChange = 0;
static float timePassed = 0;

int main(int argc, char* argv[])
{
	Setupgame();
	//float fDeltaT = GetDeltaTime();
	//cout << fDeltaT;
	GAMESTATE state = MAIN_MENU;

    //**********Game Loop********************
    do
    {
		switch (state)
		{
		case MAIN_MENU:
		{
			ClearScreen();
			DrawString("1. NEW GAME", SCREENWIDTH * .3f, SCREENHEIGHT * .8f, SColour(255, 255, 255, 255));
			DrawString("2. HIGH SCORES", SCREENWIDTH * .3f, SCREENHEIGHT * .75f, SColour(255, 255, 255, 255));
			DrawString("3. QUIT", SCREENWIDTH * .3f, SCREENHEIGHT * .7f, SColour(255, 255, 255, 255));

			//DrawString("press enter to continue...", SCREENWIDTH * .4f, SCREENHEIGHT * .2f);
			
			if (IsKeyDown('1'))
			{
				state = INTRO;
			}
			if (IsKeyDown('3'))
			{
				state = QUIT;
			}
			break;
		}

		case INTRO:
		{
			ClearScreen();
			if (!Intro())
				state = GAMEPLAY;
			break;
		}

		case GAMEPLAY:
		{
			ClearScreen();
			float fDeltaT = GetDeltaTime();
			Red->MovePlayer(fDeltaT, BG.Scrolling(), BG.CheckGridPosition(Red->CheckNextXPos(fDeltaT), Red->CheckNextYPos(fDeltaT)));
			
			BG.MoveBG(Red->GetXPos(), Red->GetYPos(), fDeltaT);
			Red->Shoot();
			
			Pokemon.Move(fDeltaT, Red->GetXPos(), Red->GetYPos(), BG.CheckGridPosition(Pokemon.CheckNextXPos(fDeltaT), Pokemon.CheckNextYPos(fDeltaT)));

			ChangeMaps();
			
			if (IsKeyDown(GLFW_KEY_ESCAPE))
				state = QUIT;

			//collision
			for (int i = 0; i < MAX_BULLETS; i++)
			{
				if (Red->Rock[i].GetActive())
				{
						if (CheckCollision(Red->Rock[i].GetX(), Red->Rock[i].GetY(), Pokemon.GetX(), Pokemon.GetY(), 20.0f) && Pokemon.GetActive())
						{
							Pokemon.SetActive(false);
							Red->Rock[i].SetActive(false);			//it just werks
						}
				}
			}

			// draw everything
			DrawSprite(BG.GetSprite());
			DrawSprite(Red->GetSprite());
			if (Pokemon.GetActive())
			{
				DrawSprite(Pokemon.GetSprite());
			}

			for (int i = 0; i < MAX_BULLETS; i++)
			{
				if (Red->Rock[i].GetActive()){
					Red->Rock[i].Update(fDeltaT, Red->Rock[i].GetDirection(), BG.CheckGridPosition(Red->Rock[i].GetX(), Red->Rock[i].GetY()));
					Red->Rock[i].Draw();
				}

			}
			
			break;
		}

		case HIGH_SCORES:
			break;

		case QUIT:
			delete Red;
			DestroySprite(BG.GetSprite());
			DestroySprite(Pokemon.GetSprite());
			return 0;
			break;
			
		}

    } while(FrameworkUpdate() == false);
	//**************************************
	
	delete Red;
    Shutdown();

    return 0;
}

void Setupgame()
{
	Initialise(SCREENWIDTH, SCREENHEIGHT, false, "Anti-Pokemon");

	BG.SetFile("oaksLab.txt");

	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

	Red->SetSize(SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f);
	Pokemon.SetSize(SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f);
	Red->SetSprite(CreateSprite("./images/playerDown.png", Red->GetWidth(), Red->GetHeight(), true));
	BG.SetSprite(CreateSprite("./images/oaksLab.png", 1536.f, 1536.f, true));

	MoveSprite(BG.GetSprite(), SCREENWIDTH * .5f, SCREENHEIGHT * .5f);

	// spawn pokemon
	Pokemon.SetSprite(CreateSprite("./images/pikachu.png", Pokemon.GetWidth(), Pokemon.GetHeight(), true));
	// gotta add offset
	Pokemon.SetPosition(13.f * 64.f, 23.f * 64.f);

	static float lastChange = 0;
	static float timePassed = 0;
}

bool Intro()
{
	float fDeltaT = GetDeltaTime();
	
	timePassed += fDeltaT;
	unsigned int oak = CreateSprite("./images/oak1.png", SCREENWIDTH*.5, SCREENHEIGHT*.5, true);
	MoveSprite(oak, SCREENWIDTH*.5f, SCREENHEIGHT*.5f);
	
	
	//cout << timePassed << endl;
	if (timePassed > .5f && timePassed < 4.f)
	{
		DrawString("Hello there! Welcome to the world of Pokemon!", SCREENWIDTH * .3f, SCREENHEIGHT * .4f, SColour(0,0,0,255));
		DrawString("My name is Oak! People call me the Pokemon Prof!", SCREENWIDTH * .29f, SCREENHEIGHT * .35f, SColour(0, 0, 0, 255));
	}
	if (timePassed > 4.5f && timePassed < 8.5f)
	{
		DrawString("This world is inhabited by creatures called Pokemon.", SCREENWIDTH * .3f, SCREENHEIGHT * .4f, SColour(0, 0, 0, 255));
		DrawString("For some, Pokemon are pets. Others use them to fight.", SCREENWIDTH * .29f, SCREENHEIGHT * .35f, SColour(0, 0, 0, 255));
	}
	if (timePassed > 4.5f)
	{
		oak = CreateSprite("./images/oak2.png", SCREENWIDTH*.5, SCREENHEIGHT*.5, true);
		//MoveSprite(oak, SCREENWIDTH*.5f, SCREENHEIGHT*.5f);
	}
	if (timePassed > 9 && timePassed < 10)
	{
		DrawString("Myself, I...", SCREENWIDTH * .45f, SCREENHEIGHT * .4f, SColour(0, 0, 0, 255));
	}

	if (timePassed > 10 && timePassed < 14.f)
	{
		DrawString("AAAAAAAAHHHHHHHHHH!!!", SCREENWIDTH * .4f, SCREENHEIGHT * .4f, SColour(0, 0, 0, 255));
	}

	if (timePassed > 10 && timePassed < 10.5f)
	{
		oak = CreateSprite("./images/oak3.png", SCREENWIDTH*.5, SCREENHEIGHT*.5, true);
	}
	if (timePassed > 10.5 && timePassed < 11.f)
	{
		oak = CreateSprite("./images/oak4.png", SCREENWIDTH*.5, SCREENHEIGHT*.5, true);
	}
	if (timePassed > 11 && timePassed < 11.5f)
	{
		oak = CreateSprite("./images/oak3.png", SCREENWIDTH*.5, SCREENHEIGHT*.5, true);
	}
	if (timePassed > 11.5 && timePassed < 12.f)
	{
		oak = CreateSprite("./images/oak4.png", SCREENWIDTH*.5, SCREENHEIGHT*.5, true);
	}
	if (timePassed > 12 && timePassed < 12.5f)
	{
		oak = CreateSprite("./images/oak3.png", SCREENWIDTH*.5, SCREENHEIGHT*.5, true);
	}
	if (timePassed > 12.5 && timePassed < 13.f)
	{
		oak = CreateSprite("./images/oak4.png", SCREENWIDTH*.5, SCREENHEIGHT*.5, true);
	}
	if (timePassed > 13 && timePassed < 13.5f)
	{
		oak = CreateSprite("./images/oak3.png", SCREENWIDTH*.5, SCREENHEIGHT*.5, true);
	}
	if (timePassed > 13.5 && timePassed < 14.f)
	{
		oak = CreateSprite("./images/oak4.png", SCREENWIDTH*.5, SCREENHEIGHT*.5, true);
	}
	if (timePassed > 14.f)
	{
		DestroySprite(oak);
		unsigned int splash = CreateSprite("./images/menu.png", SCREENWIDTH, SCREENHEIGHT, true);
		MoveSprite(splash, SCREENWIDTH*.5f, SCREENHEIGHT * .5f);
		DrawSprite(splash);
	}
	if (timePassed > 15.f){
		return false;
	}

	MoveSprite(oak, SCREENWIDTH*.5f, SCREENHEIGHT*.5f);
	DrawSprite(oak);
	return true;
}

void ChangeMaps()
{
	if (BG.CheckGridPosition(Red->GetXPos(), Red->GetYPos()) == '3'){
		unsigned int oaksLab = CreateSprite("./images/oaksLab.png", 1536.f, 1536.f, true);
		BG.SetSprite(oaksLab);
		BG.SetFile("oaksLab.txt");
		Red->SetPos((12.f /*- Red.GetBGOffsetX()*/) * 64.f, (8.f /*- Red.GetBGOffsetY*/) * 64.f);
		Pokemon.SetActive(false);
	}
	if (BG.CheckGridPosition(Red->GetXPos(), Red->GetYPos()) == '2'){
		ClearScreen();
		BG.SetSprite(CreateSprite("./images/pallet_town.png", 1536.f, 1536.f, true));
		MoveSprite(BG.GetSprite(), SCREENWIDTH * .5f, SCREENHEIGHT * .5f);
		BG.SetFile("pallet_town.txt");
		Red->SetPos((14.f /*- Red.GetBGOffsetX()*/) * 64.f, (10.f /*- Red.GetBGOffsetY()*/) * 64.f);
		Pokemon.SetPosition(13.f * 64.f, 23.f * 64.f);
		Pokemon.SetActive(true);
	}
}

bool CheckCollision(float x1, float y1, float x2, float y2, float distance)
{
	float d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	if (d < distance)
		return true;
	else
		return false;
}