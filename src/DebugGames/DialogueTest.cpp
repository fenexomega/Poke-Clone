/*
 * DialogueTest.cpp
 *
 *  Created on: 24/02/2014
 *      Author: jordy
 */

#include "DialogueTest.h"
#include "../GEInput.h"
#include "../GETimer.h"
#include "../Game/Game_Classes/gameInput.h"
#include "../Game/Game_Classes/GlobalSettings.h"
#include "../GEParser.h"

const int PLAYER_SIZE = GE_GLOBAL_TILESIZE;
const int STEP_DIST = GE_GLOBAL_TILESIZE /4;
extern float deltaTime;

DialogueTest::DialogueTest()
{
    word = new Word(TEXT_POSITION_X,TEXT_POSITION_Y,TEXT_LIMIT);
    movingTimeAcc = 1000;
    timeAux = 0;
    i = 0;
    stepTimeAux = 0;
    k = 2;
    ymov = xmov = 0;
    isMoving = false;
    background = new GETileMap(-GE_GLOBAL_TILESIZE*2,-GE_GLOBAL_TILESIZE*4,GE_GLOBAL_TILE_MAP_FILE,GE_GLOBAL_WORLD_TILEMAP_NAME,0);
    player = new Player(background->getX(),background->getY());
    objects = GEParser::ReadObjectData(GE_GLOBAL_MAP_JSON_FILE);
    debug = false;
}


void DialogueTest::gameUpdate(long currentTime)
{
    if(GEInput::isKeyDown(GEInput::F6))
        debug = !debug;
    
    //Check player input for moving the background
    UpdatePlayerInputForMoving();
    
    
    //Checar se o jogador quer falar com algum objeto
    SeeIfUserWannaTalk();
    
    if((timeAux += deltaTime) > 400 )
    {
        timeAux = 0;
        background->UpdateAnimations();
    }
    
    if(!isMoving)
    {
        player->Update(k,isMoving);
    }
    else
    {
        if(i == 0)
        {
            player->Update(k,isMoving);
            movingTimeAcc = 0;
        }
        background->Update(ymov,xmov);
        if(++i > 3)
        {
            player->UpdatePos(background->getX(),background->getY());
            ymov = xmov = 0;
            isMoving = false;
            
            //Limpar os objetos visiveis e atualizar a lista.
            viewbleObjects.clear();
            for(int z = 0; z < objects.size(); ++z)
                if(objects[z]->isViewable(background->getX(),background->getY()))
                    viewbleObjects.push_back(objects[z]);
        }
    }
}

void DialogueTest::gameDraw()
{
    background->Draw();
    for(unsigned int i = 0; i < objects.size(); ++i)
        objects[i]->Draw();
    word->Draw();
    anima.UpAndDown();
    player->Draw();
    if(debug)
        DrawDebugInfo();
    
}

void DialogueTest::gameDispose()
{
    for(unsigned int i = 0; i < objects.size();++i)
        delete objects[i];
    delete player;
    delete word;
    delete background;
}

void DialogueTest::SeeIfUserWannaTalk()
{
    if(!isMoving)
    {
        if(GEInput::isKeyDown(GEInput::z) || GEInput::isKeyDown(GEInput::x))
        {
            if(word->isActive())
                word->Continue();
            else
            {
                if(GEInput::isKeyDown(GEInput::z))
                {
                    for (unsigned int var = 0; var < viewbleObjects.size(); ++var)
                    {       
                        if(player->inFrontOf(viewbleObjects[var]))
                        {
                            if(viewbleObjects[var]->isTalkable())
                            {
                                word->Begin(viewbleObjects[var]->getPhrase());
                                break;
                            }
                        }
                        
                    }
                }
            }
        }
    }
}

void DialogueTest::UpdatePlayerInputForMoving()
{
    int m = gameInput::Update();
    if(m != 0 && !isMoving && !word->isActive())
    {
        k = m;
        if(background->isMovable(m,player->X,player->Y))
        {
            i = 0;
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
    }
}
void DialogueTest::DrawDebugInfo()
{
    GEGraphicsCore::Grid(GEColor::Red(),16 * 4);
    GE_LOG("DeltaTime = " << deltaTime);
    //TODO Player info, elements info
}

DialogueTest::~DialogueTest()
{

	//	delete viewbleObjects;
}

