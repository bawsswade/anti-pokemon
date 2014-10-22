#include "AIE.h"
#include "player.h"
#include "background.h"
#include "enemy.h"
#include <iostream>
#include <fstream>

using namespace std;

Player Red;
Background BG;
Enemy Pokemon;

int main(int argc, char* argv[])
{
	BG.SetFile("pallet_town.txt");

	Initialise(SCREENWIDTH, SCREENHEIGHT, false, "Anti-Pokemon");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

	Red.SetSize(SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f);
	Pokemon.SetSize(SCREENWIDTH / 32.f, SCREENHEIGHT / 32.f);
	Red.SetSprite(CreateSprite("./images/playerDown.png",Red.GetWidth(), Red.GetHeight(), true));
	BG.SetSprite(CreateSprite("./images/pallet_town.png", 1536.f, 1536.f, true));
	Pokemon.SetSprite(CreateSprite("./images/pikachu.png", Pokemon.GetWidth(), Pokemon.GetHeight(), true));
	// gotta add offset
	Pokemon.SetPosition(13.f * 64.f, 23.f * 64.f);
	
	MoveSprite(BG.GetSprite(), SCREENWIDTH * .5f, SCREENHEIGHT * .5f);
	

    //**********Game Loop********************
    do
    {
		float fDeltaT = GetDeltaTime();
		ClearScreen();
		
		Red.MovePlayer(fDeltaT, BG.Scrolling(), BG.CheckGridPosition(Red.CheckNextXPos(fDeltaT), Red.CheckNextYPos(fDeltaT)));
		Pokemon.Move(fDeltaT, Red.GetXPos(), Red.GetYPos(), BG.CheckGridPosition(Pokemon.CheckNextXPos(fDeltaT), Pokemon.CheckNextYPos(fDeltaT)));
		BG.MoveBG(Red.GetXPos(), Red.GetYPos(), fDeltaT);

		if (BG.CheckGridPosition(Red.GetXPos(), Red.GetYPos()) == '3'){
			unsigned int oaksLab = CreateSprite("./images/oaksLab.png", 1536.f, 1536.f, true);
			BG.SetSprite(oaksLab);
			BG.SetFile("oaksLab.txt");
			Red.SetPos((12.f /*- Red.GetBGOffsetX()*/) * 64.f, (8.f /*- Red.GetBGOffsetY*/) * 64.f);
		}
		if (BG.CheckGridPosition(Red.GetXPos(), Red.GetYPos()) == '2'){
			ClearScreen();
			BG.SetSprite(CreateSprite("./images/pallet_town.png", 1536.f, 1536.f, true));
			MoveSprite(BG.GetSprite(), SCREENWIDTH * .5f, SCREENHEIGHT * .5f);
			BG.SetFile("pallet_town.txt");
			Red.SetPos((14.f /*- Red.GetBGOffsetX()*/) * 64.f, (10.f /*- Red.GetBGOffsetY()*/) * 64.f);
		}
		if (IsKeyDown(GLFW_KEY_ESCAPE))
			return 0;

		DrawSprite(BG.GetSprite());
		DrawSprite(Red.GetSprite());
		DrawSprite(Pokemon.GetSprite());

    } while(FrameworkUpdate() == false);
	//**************************************

    Shutdown();

    return 0;
}

