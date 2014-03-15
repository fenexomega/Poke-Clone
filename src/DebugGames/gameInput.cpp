#include "gameInput.h"

gameInput::gameInput()
{
}

int gameInput::Update()
{
    if(GEInput::isAnyKeyDown())
    {
            if(GEInput::isKeyPressed(SDLK_DOWN))
            {
                return 2;
            }
            else
            if(GEInput::isKeyPressed(SDLK_UP))
            {
                return 14;
            }
            else
            if(GEInput::isKeyPressed(SDLK_RIGHT))
            {
                return 10;
            }
            else
            if(GEInput::isKeyPressed(SDLK_LEFT))
            {
                return 6;
            }
    }
    return 0;
}
