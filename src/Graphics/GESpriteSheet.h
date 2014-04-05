/*
 * GESpriteSheet.h
 *
 *  Created on: 10/03/2014
 *      Author: jordy
 */

#ifndef GESPRITESHEET_H_
#define GESPRITESHEET_H_

#include "GObject.h"


class GESpriteSheet: public GObject
{
private:
	std::vector<SDL_Rect*> tiles;
public:
    GESpriteSheet(string image, char tileSize, int type);
	virtual ~GESpriteSheet();
    SDL_Rect *getRect(int n);
	void Draw();
};

#endif /* GESPRITESHEET_H_ */
