/*
 * GETileMap.cpp
 *
 *  Created on: 11/03/2014
 *      Author: jordy
 */

#include "GETileMap.h"
#include <string>
#include "../DebugGames/GlobalSettings.h"


GETileMap::GETileMap(int x,int y,string filename,string tileimage,int type)
{
    animatedAux = 0;
    int pos;
    string line,word;
    // Colocar imagem de spritesheet na surface
    spritesheet = new GESpriteSheet(tileimage,GE_GLOBAL_TILESIZE,type);
    filename = GE_GLOBAL_FILE_PATH + filename;
    file.open((filename).c_str());
    if(file == NULL)
        cout << "ERRO: " << filename << " \n Não pode ser aberto!" << endl;
    matrixX = GE_GLOBAL_MAP_WIDTH_IN_TILES;
    matrixY = GE_GLOBAL_MAP_HEIGHT_IN_TILES;
    std::getline(file,line);
    for(int y = 0; y < matrixY ; y++)
    {
        for(int x = 0; x < matrixX ; x++)
        {
            if((pos = line.find(',')) != std::string::npos)
            {
                word = line.substr(0, pos);
                layer1[x][y] = std::stoi(word);
                line.erase(0, pos + 1);
            }
        }
    }
    std::getline(file,line);
    for(int y = 0; y < matrixY ; ++y)
    {
        for(int x = 0; x < matrixX ; ++x)
        {
            if((pos = line.find(',')) != std::string::npos)
            {
                word = line.substr(0, pos);
                layer2[x][y] = std::stoi(word);
                line.erase(0, pos + 1);
            }
        }
    }
    std::getline(file,line);
    for(int y = 0; y < matrixY ; ++y)
    {
        for(int x = 0; x < matrixX ; ++x)
        {
            if((pos = line.find(',')) != std::string::npos)
            {
                word = line.substr(0, pos);
                animatedTiles[x][y] = std::stoi(word);
                line.erase(0, pos + 1);
            }
        }
    }
    std::getline(file,line);
    while((pos = line.find(',')) != std::string::npos)
    {
        word = line.substr(0, pos);
       unmovableTiles.push_back(std::stoi(word));
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
}

void GETileMap::Draw()
{
    for(int y = 0; y < matrixY ; y++)
    {
        for(int x = 0; x < matrixX ; x++)
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
    int aux[2];
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

    for(int i = 0; i < unmovableTiles.size() ; ++i)
    {
        //GE_LOG(aux[0] << " ," << aux[1] << " : " << layer1[aux[0]][aux[1]]);
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

