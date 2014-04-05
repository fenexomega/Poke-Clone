/*
 * GETileMap.h
 *
 *  Created on: 11/03/2014
 *      Author: jordy
 */

#ifndef GETILEMAP_H_
#define GETILEMAP_H_

#include <fstream>
#include "../GEParser.h"

class GETileMap {
private:
	SDL_Rect rect;
	GESpriteSheet *spritesheet;
	ifstream file;
    int layer1[GE_GLOBAL_MAP_HEIGHT_IN_TILES][GE_GLOBAL_MAP_WIDTH_IN_TILES];
    int layer2[GE_GLOBAL_MAP_HEIGHT_IN_TILES][GE_GLOBAL_MAP_WIDTH_IN_TILES];
    int animatedTiles[GE_GLOBAL_MAP_HEIGHT_IN_TILES][GE_GLOBAL_MAP_WIDTH_IN_TILES];
    vector<int> unmovableTiles;
    int animatedAux;
public:
    int matrixX,matrixY;
    int X;
    int Y;
    GETileMap(int x,int y,string filename,string tileimage,int type);
	virtual ~GETileMap();
	void Draw();
    void UpdateAnimations();
	void Update(int yVel, int xVel);
    bool isMovable(int direction,int tileX,int tileY);
	SDL_Rect * getRect() {
		return &rect;
	}

    int getX() const {
        return rect.x;
    }

	void setX(int x) {
		this->rect.x = x;
	}

	int getY() const {
		return rect.y;
	}

	void setY(int y) {
		this->rect.y = y;
	}
};

#endif /* GETILEMAP_H_ */
