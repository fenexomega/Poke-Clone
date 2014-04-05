/*
 * GETileMap.cpp
 *
 *  Created on: 11/03/2014
 *      Author: jordy
 */

#include "GETileMap.h"
#include <string>
#include "../Game/Game_Classes/GlobalSettings.h"


GETileMap::GETileMap(int x,int y,string filename,string tileimage,int type)
{
    X = x/GE_GLOBAL_TILESIZE;
    Y = y/GE_GLOBAL_TILESIZE;
    animatedAux = 0;
     int pos;
    string line,word;
    // Colocar imagem de spritesheet na surface
    spritesheet = new GESpriteSheet(tileimage,GE_GLOBAL_TILESIZE,type);
    filename = GE_GLOBAL_FILE_PATH + filename;
    file.open((filename).c_str());
    if(file == NULL)
        GE_LOG("ERRO: " << filename << " \n Não pode ser aberto!");
    matrixX = GE_GLOBAL_MAP_WIDTH_IN_TILES;
    matrixY = GE_GLOBAL_MAP_HEIGHT_IN_TILES;

    GEParser::ReadMapData(GE_GLOBAL_MAP_JSON_FILE,"Base","data",layer1);
    GEParser::ReadMapData(GE_GLOBAL_MAP_JSON_FILE,"Objetos","data",layer2);
    GEParser::ReadMapData(GE_GLOBAL_MAP_JSON_FILE,"Animados","data",animatedTiles);


    std::getline(file,line);
    while((pos = line.find(',')) != std::string::npos)
    {
        word = line.substr(0, pos);
        unmovableTiles.push_back(atoi(word.c_str()));
        line.erase(0, pos + 1);
    }
    file.close();

    setX(x);
    setY(y);
}

void GETileMap::UpdateAnimations()
{
    if(animatedAux++ > 2)
    {
        for(int y = 0; y < matrixY ; y++)
        {
            for(int x = 0; x < matrixX ; x++)
            {
                if(animatedTiles[x][y] > 0)
                    animatedTiles[x][y] -= 3;
            }
        }
        animatedAux = 0;
        return;
    }
    for(int y = 0; y < matrixY ; y++)
    {
        for(int x = 0; x < matrixX ; x++)
        {
            if(animatedTiles[x][y] > 0)
                animatedTiles[x][y]++;
        }
    }

}

void GETileMap::Update(int yVel, int xVel)
{
    setX(getX() + xVel);
    setY(getY() + yVel);
    X += xVel/GE_GLOBAL_TILESIZE;
    Y += yVel/GE_GLOBAL_TILESIZE;
}

void GETileMap::Draw()
{
    int x = GE_MAX(0,-(getX()/GE_GLOBAL_TILESIZE));
    int y = GE_MAX(0,-(getY()/GE_GLOBAL_TILESIZE));
    int limitY = GE_MIN(matrixY,((GE_GLOBAL_SCREEN_HEIGHT/GE_GLOBAL_TILESIZE) + y + 1));
    int limitX = GE_MIN(matrixX,((GE_GLOBAL_SCREEN_WIDTH/GE_GLOBAL_TILESIZE) + x + 1));
    for(; y < limitY ; y++)
    {
        for(x = GE_MAX(0,-(getX()/GE_GLOBAL_TILESIZE)); x < limitX ; x++)
        {
            if(layer1[x][y] != 0)
                GEGraphicsCore::drawSurface_Pos((x * GE_GLOBAL_TILESIZE) + getX(),(y * GE_GLOBAL_TILESIZE) + getY(),spritesheet->getSprite(),screen,spritesheet->getRect(layer1[x][y]));
            if(layer2[x][y] != 0)
                GEGraphicsCore::drawSurface_Pos((x * GE_GLOBAL_TILESIZE) + getX(),(y * GE_GLOBAL_TILESIZE) + getY(),spritesheet->getSprite(),screen,spritesheet->getRect(layer2[x][y]));
            if(animatedTiles[x][y] != 0)
                GEGraphicsCore::drawSurface_Pos((x * GE_GLOBAL_TILESIZE) + getX(),(y * GE_GLOBAL_TILESIZE) + getY(),spritesheet->getSprite(),screen,spritesheet->getRect(animatedTiles[x][y]));
        }
    }
}

bool GETileMap::isMovable(int direction,int tileX,int tileY)
{
    int aux[2] = {0,0};
    switch(direction)
    {
    case PLAYER_GO_RIGHT:
        aux[0] = tileX + 1;
        aux[1] = tileY; break;
    case PLAYER_GO_LEFT:
        aux[0] = tileX - 1;
        aux[1] = tileY; break;
    case PLAYER_GO_DOWN:
        aux[0] = tileX;
        aux[1] = tileY + 1; break;
    case PLAYER_GO_UP:
        aux[0] = tileX;
        aux[1] = tileY - 1; break;
    }

    for(unsigned int i = 0; i < unmovableTiles.size() ; ++i)
    {
        if(animatedTiles[aux[0]][aux[1]] != 0 && animatedTiles[aux[0]][aux[1]] == unmovableTiles[i])
        {
            return false;
        }
        if(animatedTiles[aux[0]][aux[1]] == 0 )
        {
            if(layer2[aux[0]][aux[1]] != 0 && layer2[aux[0]][aux[1]] == unmovableTiles[i])
            {
                return false;
            }
            if(layer2[aux[0]][aux[1]] == 0)
            {
                if(layer1[aux[0]][aux[1]] == 0 || layer1[aux[0]][aux[1]] == unmovableTiles[i])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

GETileMap::~GETileMap() {
    // TODO Auto-generated destructor stub
    spritesheet->~GESpriteSheet();
}

