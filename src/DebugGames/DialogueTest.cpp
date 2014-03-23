/*
 * DialogueTest.cpp
 *
 *  Created on: 24/02/2014
 *      Author: jordy
 */

#include "DialogueTest.h"
#include "../GEInput.h"
#include "../GETimer.h"
#include "gameInput.h"
#include "GlobalSettings.h"
#include "../GEParser.h"

const int PLAYER_SIZE = GE_GLOBAL_TILESIZE;
const int STEP_DIST = GE_GLOBAL_TILESIZE /4;
extern float deltaTime;

string frasePlaca = "Bem-vindo a lugarnenhum!";
string fraseMercado = "Mercado daora. O slogan do mercadoainda nao foi    implementado!";

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
    objects.push_back(new GameObject(12,7,0,1,frasePlaca) );
    objects.push_back(new GameObject(18,15,0,1,fraseMercado) );
}


void DialogueTest::gameUpdate(long currentTime)
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

    //Checar se o jogador quer falar com algum objeto
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
                    for (int var = 0; var < objects.size(); ++var)
                    {
                        if(player->inFrontOf(objects[var]))
                        {
                            if(objects[var]->isTalkable())
                            {
                                word->Begin(objects[var]->getPhrase());
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

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
        if((movingTimeAcc += deltaTime) > 200)
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
            movingTimeAcc = 200;
        }
    }
}

void DialogueTest::gameDraw()
{
    background->Draw();
    for(int i = 0; i < objects.size(); i++)
        objects[i]->Draw();
    word->Draw();
    anima.UpAndDown();
    player->Draw();

}

void DialogueTest::gameDispose()
{
    for(int i = 0; i < objects.size();++i)
        delete objects[i];
    delete player;
    delete word;
    delete background;
}

DialogueTest::~DialogueTest()
{

}

