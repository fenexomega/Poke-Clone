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
                return PLAYER_GO_DOWN;
            }
            else
            if(GEInput::isKeyPressed(SDLK_UP))
            {
                return PLAYER_GO_UP;
            }
            else
            if(GEInput::isKeyPressed(SDLK_RIGHT))
            {
                return PLAYER_GO_RIGHT;
            }
            else
            if(GEInput::isKeyPressed(SDLK_LEFT))
            {
                return PLAYER_GO_LEFT;
            }
    }
    return 0;
}
