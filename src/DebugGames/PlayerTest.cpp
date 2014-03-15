/*
 * PlayerTest.cpp
 *
 *  Created on: 24/02/2014
 *      Author: jordy
 */

#include "PlayerTest.h"
#include "../GEInput.h"
#include "../GETimer.h"
#include "gameInput.h"


#define PLAYER_GO_DOWN 2
#define PLAYER_GO_UP 14
#define PLAYER_GO_RIGHT 10
#define PLAYER_GO_LEFT 6

const int PLAYER_SIZE = GE_GLOBAL_TILESIZE;
const int STEP_DIST = GE_GLOBAL_TILESIZE /4;
extern float deltaTime;

PlayerTest::PlayerTest()
{
    movingTimeAcc = 0;
    timeAux = 0;
    i = 0;
    k = 2;
    player = new Player();
    ymov = xmov = 0;
    isMoving = false;
    background = new GETileMap(GE_GLOBAL_TILESIZE,-GE_GLOBAL_TILESIZE,GE_GLOBAL_TILE_MAP_FILE,GE_GLOBAL_WORLD_TILEMAP_NAME);
}

PlayerTest::~PlayerTest()
{

}

void PlayerTest::gameInit()
{


}

void PlayerTest::gameRun()
{

}

void PlayerTest::gameUpdate(long currentTime)
{
    int m = gameInput::Update();
    if(m != 0)
        k = m;
    if(m != 0 && !isMoving)
    {
        isMoving = true;
        switch(m)
        {
        case PLAYER_GO_UP:
            ymov = STEP_DIST; break;
        case PLAYER_GO_DOWN:
            ymov = -STEP_DIST; break;
        case PLAYER_GO_RIGHT:
            xmov = -STEP_DIST; break;
        case PLAYER_GO_LEFT:
            xmov = STEP_DIST; break;
        }
    }

    if((currentTime += deltaTime*1000) > 1000 )
    {
        currentTime = 0;
        background->UpdateAnimations();
    }

    //player->Update(k,isMoving);

    if(!isMoving)
        player->Update(k,isMoving);
    else
    {
        background->Update(ymov,xmov);
        if((movingTimeAcc += deltaTime*1000) > deltaTime*1000*2.3)
        {
            player->Update(k,isMoving);
            movingTimeAcc = 0;
        }
        if(++i >= 4)
        {
            ymov = xmov = 0;
            isMoving = false;
            i = 0;
        }
    }

    if(GEInput::isKeyDown(SDLK_SPACE))
    {
        anima.Begin();
    }


}

void PlayerTest::gameDraw()
{
    background->Draw();
    for(int i = 0; i < objects.size(); i++)
        objects[i]->Draw();
    anima.UpAndDown();
    player->Draw();

}

void PlayerTest::gameDispose()
{
    delete background;
}


