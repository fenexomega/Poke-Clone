/*
 * ScrollingTest.h
 *
 *  Created on: 24/02/2014
 *      Author: jordy
 */

#ifndef SCROLLINGTEST_H_
#define SCROLLINGTEST_H_
#include "../GEGame.h"
#include "../Graphics/GETileMap.h"
#include "../Graphics/GELoadingAnimation.h"
#include <vector>

using namespace std;

class ScrollingTest: public GEGame {
private:
     GELoadingAnimation anima;
     int i;
     int time;
	 int ymov, xmov;
	 GETileMap * background;
	 vector<GObject *> objects;
     bool isMoving;
public:
	ScrollingTest();
	~ScrollingTest();
	void gameInit();
	void gameRun();
	void gameUpdate(long currentTime);
    void gameDraw();
	void gameDispose();
};

#endif /* SCROLLINGTEST_H_ */
