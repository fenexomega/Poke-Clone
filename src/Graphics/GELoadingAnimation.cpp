/*
 * GELoadingAnimation.cpp
 *
 *  Created on: 19/02/2014
 *      Author: jordy
 */

#include "GELoadingAnimation.h"
#include <iostream>
#include <cmath>

GELoadingAnimation::GELoadingAnimation() {
    // TODO Auto-generated constructor stub
    active = false;
}

GELoadingAnimation::~GELoadingAnimation() {
    // TODO Auto-generated destructor stub
}

void GELoadingAnimation::Left2Right()
{
    
}

void GELoadingAnimation::UpAndDown()
{
     int squares_per_width = (GE_GLOBAL_SCREEN_WIDTH/(GE_GLOBAL_TILESIZE));
     int squares_per_height = GE_GLOBAL_SCREEN_HEIGHT/(GE_GLOBAL_TILESIZE) -1;
     int maxSquaresInScreen = (GE_GLOBAL_SCREEN_HEIGHT * GE_GLOBAL_SCREEN_WIDTH)/((GE_GLOBAL_TILESIZE) * (GE_GLOBAL_TILESIZE));
    if(active == true)
    {
        squares.push_back(new Square( (squares.size() % squares_per_width )* (GE_GLOBAL_TILESIZE),(squares.size()/(squares_per_width))*(GE_GLOBAL_TILESIZE),(GE_GLOBAL_TILESIZE),(GE_GLOBAL_TILESIZE)));
        squares.push_back(new Square((squares_per_width - squares.size()%squares_per_width)* (GE_GLOBAL_TILESIZE),( squares_per_height - squares.size()/squares_per_width)*(GE_GLOBAL_TILESIZE),(GE_GLOBAL_TILESIZE),(GE_GLOBAL_TILESIZE)));
        for(i = 0; i < squares.size(); i++)
            squares[i]->Draw();
        if(squares.size() == maxSquaresInScreen)
            active = !active;
    }
}

void GELoadingAnimation::Spiral()
{
    if(active == true)
    {
        squares.push_back(new Square((squares.size() % 20)* (GE_GLOBAL_TILESIZE),(squares.size()/20)*(GE_GLOBAL_TILESIZE),(GE_GLOBAL_TILESIZE),(GE_GLOBAL_TILESIZE)));
        for(i = 0; i < squares.size(); i++)
            squares[i]->Draw();
        if(squares.size() == ((GE_GLOBAL_SCREEN_HEIGHT/(GE_GLOBAL_TILESIZE)) * (GE_GLOBAL_SCREEN_WIDTH/(GE_GLOBAL_TILESIZE))))
            active = !active;
    }
}

void GELoadingAnimation::Begin()
{
    squares.clear();
    active = true;
}
