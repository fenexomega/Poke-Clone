/*
 * Square.cpp
 *
 *  Created on: 18/02/2014
 *      Author: jordy
 */

#include "Square.h"

Square::Square(int x,int y,int w, int h, bool visible) : GObject(x,y,w,h,visible) {
	// TODO Auto-generated constructor stub

}

Square::Square(int x,int y,int w, int h, bool visible,  char r, char g, char b) : GObject(x,y,w,h,visible,r,g,b) {
	// TODO Auto-generated constructor stub

}

Square::~Square() {
	// TODO Auto-generated destructor stub
}

