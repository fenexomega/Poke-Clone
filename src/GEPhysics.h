/*
 * GEPhysics.h
 *
 *  Created on: 18/02/2014
 *      Author: jordy
 */

#ifndef GEPHYSICS_H_
#define GEPHYSICS_H_
#include "Graphics/GObject.h"
#include "GEGlobal.h"



class GEPhysics {
public:
	static const  char NO_COL = 0;
 	static const  char X_AXIS_COL = 1;
	static const  char Y_AXIS_COL = 2;
	GEPhysics();
	static bool isColliding(GObject *obj1,GObject  *obj2);
	static int isOnBorders(GObject *obj);
	virtual ~GEPhysics();
};

#endif /* GEPHYSICS_H_ */
