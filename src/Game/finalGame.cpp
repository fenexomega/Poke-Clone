#include "finalGame.h"

#include "../GEInput.h"
#include "../Graphics/Square.h"
#include "../GETimer.h"

const int PLAYER_SIZE = 64;
const int STEP_DIST = 16;
extern float deltaTime;

FinalGame::FinalGame() {
    // TODO Auto-generated constructor stub
    ymov = xmov = 0;
    isMoving = false;
    background = new GETileMap(0,0,GE_GLOBAL_TILE_MAP_FILE,GE_GLOBAL_WORLD_TILEMAP_NAME);
}

FinalGame::~FinalGame() {
    // TODO Auto-generated destructor stub
}

void FinalGame::gameInit()
{


}

void FinalGame::gameRun()
{

}

void FinalGame::gameUpdate(long currentTime)
{


    if(GEInput::isAnyKeyDown())
    {
        if(!isMoving)
        {
            if(GEInput::isKeyPressed(SDLK_DOWN))
            {
                ymov = -STEP_DIST;
            }
            else
            if(GEInput::isKeyPressed(SDLK_UP))
            {
                ymov = +STEP_DIST;
            }
            else
            if(GEInput::isKeyPressed(SDLK_RIGHT))
            {
                xmov = -STEP_DIST;
            }
            else
            if(GEInput::isKeyPressed(SDLK_LEFT))
            {
                xmov = +STEP_DIST;
            }
            isMoving = true;
            i = 0;
        }
    }

    if(isMoving)
    {
        background->Update(ymov,xmov);
        if(++i == 4)
        {
            ymov = xmov = 0;
            isMoving = false;
        }
    }
    if(GEInput::isKeyDown(SDLK_SPACE))
    {
        anima.Begin();
    }

}

void FinalGame::gameDraw()
{
    background->Draw();
    for(int i = 0; i < objects.size(); i++)
        objects[i]->Draw();
    anima.Left2Right();

}

void FinalGame::gameDispose()
{
    delete background;
}


