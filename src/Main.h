/*
 * main.h
 *
 *  Created on: 12/02/2014
 *      Author: jordy
 */

#ifndef MAIN_H_
#define MAIN_H_
#include "GETimer.h"
#include "GEGraphicsCore.h"
#include "GEGame.h"
#include <vector>
#include "Graphics/Square.h"
#include "SDL/SDL_opengl.h"

#include "GEInput.h"

Uint8 * keys;
vector<int> downKeys;
vector<int> upKeys;
vector<int> currentKeys;

SDL_Surface * screen;
SDL_Event event;

float deltaTime;

#endif /* MAIN_H_ */
