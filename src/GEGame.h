/*
 * game.h
 *
 *  Created on: 12/02/2014
 *      Author: jordy
 */

#ifndef GAME_H_
#define GAME_H_
#include "SDL/SDL.h"
#include "Graphics/GObject.h"

class GEGame
{
public:
	virtual void gameUpdate(long currentTime) = 0;
    virtual void gameDraw() = 0;
	virtual void gameDispose() = 0;
};


/*


void Game::gameUpdate(long currentTime)
{

}

void Game::gameDraw(SDL_Surface * screen)
{

}

void Game::gameDispose()
{

}



 */

#endif /* GAME_H_ */
