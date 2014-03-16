///*
// * Game.h
// *
// *  Created on: 12/02/2014
// *      Author: jordy
// */
//
//#ifndef REAL_GAME_H_
//#define REAL_GAME_H_
//
//#define SQUARE_SIZE 150
//
//SDL_Surface  * surface;
//
//vector<GObject *> objects;
//
//void gameInit()
//{
//	objects.push_back(new Square(200,200,SQUARE_SIZE,SQUARE_SIZE,true));
//	objects.push_back(new Square(350, 50,SQUARE_SIZE,SQUARE_SIZE,true,0,0,255));
//	objects.push_back(new Square(350,200,SQUARE_SIZE,SQUARE_SIZE,true,255,0,0));
//	objects.push_back(new Square(500,200,SQUARE_SIZE,SQUARE_SIZE,true,0,255,0));
//}
//
//void gameRun()
//{
//
//}
//
//void gameUpdate(long time)
//{
//	for(int i = 0; i < objects.size(); i++)
//		objects[i]->setVisible(false);
//
//	if(Input::isKeyPressed(SDLK_LEFT))
//		objects[0]->setVisible(true);
//	if(Input::isKeyPressed(SDLK_UP))
//		objects[1]->setVisible(true);
//	if(Input::isKeyPressed(SDLK_DOWN))
//		objects[2]->setVisible(true);
//	if(Input::isKeyPressed(SDLK_RIGHT))
//		objects[3]->setVisible(true);
//
//
//}
//
//void gameDraw(SDL_Surface * screen)
//{
//	for(int i = 0; i < objects.size(); i++)
//			objects[i]->Draw();
//}
//void gameDispose()
//{
//	printf("Dispose game\n");
//	for(int i = 0; i < objects.size(); i++)
//			delete objects[i];
//}
//
//
//
//#endif /* REAL_GAME_H_ */
