/*
 * CollisionTest.cpp
 *
 *  Created on: 19/02/2014
 *      Author: jordy
 */
#include "CollisionTest.h"
#include "../GEPhysics.h"

CollisionTest::CollisionTest()
{
	surface = NULL;
}

CollisionTest::~CollisionTest()
{

}

void CollisionTest::gameInit()
{
	objects.push_back(new Square(100,250,SQUARE_SIZE,SQUARE_SIZE,true));
	objects.push_back(new Square(350, 50,SQUARE_SIZE,SQUARE_SIZE,true,0,0,255));
	objects.push_back(new Square(350,300,SQUARE_SIZE,SQUARE_SIZE,true,255,0,0));
	objects.push_back(new Square(100,400,SQUARE_SIZE,SQUARE_SIZE,true,0,255,0));
	objects.push_back(new Square(50,350,SQUARE_SIZE,SQUARE_SIZE,true,0,127,0));
	objects.push_back(new Square(150,150,SQUARE_SIZE,SQUARE_SIZE,true,64,64,0));
	for(unsigned int i = 0; i < objects.size(); i++)
		objects[i]->setVel(i-5,i);
}

void CollisionTest::gameRun()
{

}

void CollisionTest::gameUpdate(long time)
{
	 int i;
	 int y;

	objects[2]->setVisible(!objects[2]->isVisible());

	if(!animation.isActive())
	{
		for(i = 0; i < objects.size(); i++)
				objects[i]->Update();

			for(i = 0; i < objects.size(); i++)
					if(GEPhysics::isOnBorders(objects[i]) == GEPhysics::X_AXIS_COL)
					{
						objects[i]->setVel(-objects[i]->getXVel(),objects[i]->getYVel());
					}
					else if(GEPhysics::isOnBorders(objects[i]) == GEPhysics::Y_AXIS_COL)
					{
						objects[i]->setVel(objects[i]->getXVel(),-objects[i]->getYVel());
					}

			for(i = 0; i < objects.size(); i++)
				for(y = 0; y < objects.size();y++)
							if(GEPhysics::isColliding(objects[i],objects[y]))
							{
								objects[i]->setVel(-objects[i]->getXVel(),-objects[i]->getYVel());
								objects[y]->setVel(-objects[y]->getXVel(),-objects[y]->getYVel());
							}
			if(GEInput::isKeyDown(SDLK_SPACE))
						animation.Begin();

	}



}

void CollisionTest::gameDraw()
{
	for(unsigned int i = 0; i < objects.size(); i++)
			objects[i]->Draw();

	animation.Left2Right();
}

void CollisionTest::gameDispose()
{
	for(unsigned int i = 0; i < objects.size(); i++)
			delete objects[i];
}


