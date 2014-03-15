/*
 * CollisionTest.h
 *
 *  Created on: 18/02/2014
 *      Author: jordy
 */

#ifndef COLLISIONTEST_H_
#define COLLISIONTEST_H_
#include "../GEGame.h"
#include <vector>
#include "../Graphics/GObject.h"
#include "../Graphics/GELoadingAnimation.h"


#include "../GEInput.h"



#define SQUARE_SIZE 50
using namespace std;

class CollisionTest: public GEGame
{
private:
	GELoadingAnimation animation;
	SDL_Surface  * surface;
	vector<GObject *> objects;
public:
	CollisionTest();
	virtual ~CollisionTest();
	void gameInit();
	void gameRun();
	void gameUpdate(long time);
	void gameDraw();
	void gameDispose();
};



#endif /* COLLISIONTEST_H_ */
