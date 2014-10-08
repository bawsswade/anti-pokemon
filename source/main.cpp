#include "AIE.h"
#include "player.h"
#include "background.h"
#include <iostream>

using namespace std;

player Red;
background BG;

int main( int argc, char* argv[] ) 
{	
	//unsigned int spriteID;

	Initialise(SCREENWIDTH, SCREENHEIGHT, false, "Anti-Pokemon");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

	Red.SetSprite(CreateSprite("./images/playerDown.png", SCREENWIDTH * .05f, SCREENHEIGHT * .05f, true));
	BG.SetSprite(CreateSprite("./images/pallet_town.png", SCREENWIDTH * 1.75, SCREENHEIGHT * 1.5, true));
	MoveSprite(BG.GetSprite(), SCREENWIDTH * .5f, SCREENHEIGHT * .5f);
	//MoveSprite(Red.GetSprite(), SCREENWIDTH * .5f, SCREENHEIGHT * .5f);
	
    //**********Game Loop********************
    do
    {
		float fDeltaT = GetDeltaTime();
		ClearScreen();
		DrawSprite(BG.GetSprite());
		DrawSprite(Red.GetSprite());

		Red.MovePlayer(fDeltaT, BG.Scrolling());
		BG.MoveBG(Red.GetXPos(), Red.GetYPos(), fDeltaT);

    } while(FrameworkUpdate() == false);
	//**************************************

    Shutdown();

    return 0;
}

