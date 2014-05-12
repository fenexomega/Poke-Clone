/*
 ==============================================================
 | Name        : Main.cpp                                     |
 | Author      : Jordy                                        |
 | Version     :                                              |
 | Copyright   : Your copyright notice                        |
 | Description : Hello World in C, Ansi-style                 |
 ==============================================================
 */

#include "Main.h"
#include "Engine.h"
#include "DebugGames/CollisionTest.h"
#include "DebugGames/ScrollingTest.h"
#include "DebugGames/PlayerTest.h"
#include "DebugGames/FontTest.h"
#include "DebugGames/DialogueTest.h"
#include "DebugGames/RandTest.h"

int main(int argc, char **argv) 
{
    if(!Engine::InitSystems())
        return EXIT_FAILURE;
    
    DialogueTest game;
    
    Engine::Run(&game);
	return EXIT_SUCCESS;
}
