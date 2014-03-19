/*
 ============================================================================
 Name        : TRABALHO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Main.h"

//#include "Game/Game.h"
//#include "DebugGames/InputTest.h"
#include "DebugGames/CollisionTest.h"
#include "DebugGames/ScrollingTest.h"
#include "DebugGames/PlayerTest.h"
#include "DebugGames/FontTest.h"

int main(void) {

	//TODO FRAMECAP
	GEGraphicsCore::initGraphics();
    PlayerTest game;
	GETimer timer;
	game.gameInit();
	while(true)
	{
		SDL_PollEvent(&event);
		timer.Update();
        deltaTime = timer.getMedia();
		SDL_Delay(1000/GE_GLOBAL_FPS);
		GEInput::update();
		game.gameUpdate(timer.getSecondTime());
        GEGraphicsCore::clearScreen(0,0,0);
        game.gameDraw();
//        GEGraphicsCore::Grid(GEColor::Red(),8 * 4);
		SDL_Flip(screen);
		if(event.type == SDL_QUIT)
			break;
	}
	game.gameDispose();
	SDL_Quit();
	return EXIT_SUCCESS;
}
