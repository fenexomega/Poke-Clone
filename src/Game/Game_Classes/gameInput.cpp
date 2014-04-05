#include "gameInput.h"

gameInput::gameInput()
{
}

int gameInput::Update()
{
    if(GEInput::isAnyKeyDown())
    {
            if(GEInput::isKeyPressed(GEInput::DOWN))
            {
                return PLAYER_GO_DOWN;
            }
            else
            if(GEInput::isKeyPressed(GEInput::UP))
            {
                return PLAYER_GO_UP;
            }
            else
            if(GEInput::isKeyPressed(GEInput::RIGHT))
            {
                return PLAYER_GO_RIGHT;
            }
            else
            if(GEInput::isKeyPressed(GEInput::LEFT))
            {
                return PLAYER_GO_LEFT;
            }
    }
    return 0;
}
