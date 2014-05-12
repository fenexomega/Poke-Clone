#ifndef ENGINE_H
#define ENGINE_H

#include "GEGame.h"
#include "GETimer.h"
#include "GERandom.h"
#include "GEInput.h"
extern SDL_Surface * screen;
extern SDL_Event event;

extern float deltaTime;
extern float totalTime;

class Engine
{
public:
    Engine();
    static bool InitSystems();
    static bool DisposeSystems();
    static void Run(GEGame *game);
};

#endif // ENGINE_H
