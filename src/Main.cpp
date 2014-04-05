/*
 ==============================================================
 | Name        : Main.cpp                                     |
 | Author      : Jordy                                        |
 | Version     :                                              |
 | Copyright   : Your copyright notice                        |
 | Description : Hello World in C, Ansi-style                 |
 ==============================================================
 */

#include "Main.h"

#include "DebugGames/CollisionTest.h"
#include "DebugGames/ScrollingTest.h"
#include "DebugGames/PlayerTest.h"
#include "DebugGames/FontTest.h"
#include "DebugGames/DialogueTest.h"
#include "DebugGames/RandTest.h"

int main(int argc, char **argv) 
{

	GEGraphicsCore::initGraphics();
    CollisionTest game;
	GETimer timer;
    GERandom::initRandomSeed();
    while(event.type != SDL_QUIT)
	{
        timer.Update();
        deltaTime = timer.getMedia();
        totalTime = timer.getTotalTime();
		
        SDL_PollEvent(&event);
		SDL_Delay(1000/GE_GLOBAL_FPS);
		GEInput::update();
		game.gameUpdate(timer.getSecondTime());

        //Clean the screen, draw, then update screen.
        GEGraphicsCore::clearScreen(0,0,0);
        game.gameDraw();
        GEGraphicsCore::UpdateScreen();
	}
	game.gameDispose();
	SDL_Quit();
	return EXIT_SUCCESS;
}
