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
#include "DebugGames/CollisionTest.h"
#include "DebugGames/ScrollingTest.h"
#include "DebugGames/PlayerTest.h"
#include "DebugGames/FontTest.h"
#include "DebugGames/DialogueTest.h"

int main(void) {

	//TODO FRAMECAP
	GEGraphicsCore::initGraphics();
    DialogueTest game;
	GETimer timer;
    while(event.type != SDL_QUIT)
	{
		SDL_PollEvent(&event);
        timer.Update();
        deltaTime = timer.getMedia();
		SDL_Delay(1000/GE_GLOBAL_FPS);
		GEInput::update();
		game.gameUpdate(timer.getSecondTime());
        GEGraphicsCore::clearScreen(0,0,0);
        game.gameDraw();
//        GEGraphicsCore::Grid(GEColor::Red(),16 * 4);
		SDL_Flip(screen);

	}
	game.gameDispose();
	SDL_Quit();
	return EXIT_SUCCESS;
}
