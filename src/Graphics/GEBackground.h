/*
 * GEBackground.h
 *
 *  Created on: 24/02/2014
 *      Author: jordy
 */

#ifndef GEBACKGROUND_H_
#define GEBACKGROUND_H_

#include "GObject.h"
#include <iostream>

class GEBackground: public GObject {
public:
	GEBackground();
	GEBackground(int x, int y,std::string spriteloc);
	virtual ~GEBackground();
	void Draw();
};

#endif /* GEBACKGROUND_H_ */
