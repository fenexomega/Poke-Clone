/*
 * GETileMap.cpp
 *
 *  Created on: 11/03/2014
 *      Author: jordy
 */

#include "GETileMap.h"
#include <string>

GETileMap::GETileMap(int x,int y,string filename,string tileimage)
{
    animatedAux = 0;
    int i = 0;
    int pos;
    string line,word;
    // Colocar imagem de spritesheet na surface
    spritesheet = new GESpriteSheet(tileimage,GE_GLOBAL_TILESIZE);
    filename = GE_GLOBAL_FILE_PATH + filename;
    file.open((filename).c_str());
    if(file == NULL)
        cout << "ERRO: " << filename << " \n Não pode ser aberto!" << endl;
    std::getline(file,line);
    while((pos = line.find(',')) != std::string::npos)
    {
        word = line.substr(0, pos);
        layer1.push_back(std::stoi(word));
        line.erase(0, pos + 1);
    }
    std::getline(file,line);
    while((pos = line.find(',')) != std::string::npos)
    {
        word = line.substr(0, pos);
        layer2.push_back(std::stoi(word));
        line.erase(0, pos + 1);
    }
    std::getline(file,line);
    while((pos = line.find(',')) != std::string::npos)
    {
        word = line.substr(0, pos);
        animatedTiles.push_back(std::stoi(word));
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
        for(int i = 0; i < animatedTiles.size(); i++)
        {
            if(animatedTiles[i] > 0)
                animatedTiles[i] -= 3;
        }
        animatedAux = 0;
        return;
    }
    for(int i = 0; i < animatedTiles.size(); i++)
        if(animatedTiles[i] > 0)
            animatedTiles[i]++;
}

void GETileMap::Update(int yVel, int xVel)
{
    setX(getX() + xVel);
    setY(getY() + yVel);
}

void GETileMap::Draw()
{
    int i = 0;
    int y = 0;
    while(i < layer1.size())
    {
        for(int x = 0; x < 20 * GE_GLOBAL_TILESIZE; x += GE_GLOBAL_TILESIZE,i++)
        {
            if(layer1[i] != 0)
                GEGraphicsCore::drawSurface_Pos(x  + getX(),y + getY(),spritesheet->getSprite(),screen,spritesheet->getRect(layer1[i]));
            if(layer2[i] != 0)
                GEGraphicsCore::drawSurface_Pos(x  + getX(),y + getY(),spritesheet->getSprite(),screen,spritesheet->getRect(layer2[i]));
            if(animatedTiles[i] != 0)
                GEGraphicsCore::drawSurface_Pos(x  + getX(),y + getY(),spritesheet->getSprite(),screen,spritesheet->getRect(animatedTiles[i]));

        }
        y += GE_GLOBAL_TILESIZE;
    }
}

GETileMap::~GETileMap() {
    // TODO Auto-generated destructor stub
    spritesheet->~GESpriteSheet();
}

