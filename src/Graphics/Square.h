/*
 * Square.h
 *
 *  Created on: 18/02/2014
 *      Author: jordy
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include "GObject.h"
#include "../GEGlobal.h"

class Square: public GObject {
public:
	Square(int x,int y,int w, int h);
	Square(int x,int y,int w, int h,char r, char g, char b);
	virtual ~Square();

	void Draw();

};

#endif /* SQUARE_H_ */
