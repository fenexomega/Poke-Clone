/*
 * GETileMap.h
 *
 *  Created on: 11/03/2014
 *      Author: jordy
 */

#ifndef GETILEMAP_H_
#define GETILEMAP_H_

#include "GESpriteSheet.h"
#include <fstream>


class GETileMap {
private:
	SDL_Rect rect;
	GESpriteSheet *spritesheet;
	ifstream file;
    vector<int> layer1;
    vector<int> layer2;
    vector<int> animatedTiles;
    int animatedAux;
public:
    GETileMap(int x,int y,string filename,string tileimage);
	virtual ~GETileMap();
	void Draw();
    void UpdateAnimations();
	void Update(int yVel, int xVel);
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
