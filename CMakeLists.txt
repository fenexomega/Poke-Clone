project("TRABALHO SI RPG")
cmake_minimum_required(VERSION 2.8)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(JsonCpp REQUIRED)
include_directories( ${SDL_INCLUDE_DIR} ${SDL_IMAGE_INCLUDE_DIR} ${JSONCPP_INCLUDE_DIR} )
add_executable( game

	src/Main.cpp
	src/GEPhysics.cpp
	src/GETimer.cpp
	src/GEGraphicsCore.cpp
        src/GEGlobal.h
        src/GEInput.h
        src/GEGame.h
        src/GEParser.cpp
        src/GEFile.cpp

	src/Graphics/GELoadingAnimation.cpp
	src/Graphics/GEBackground.cpp
	src/Graphics/GEColor.cpp
	src/Graphics/GESpriteSheet.cpp
	src/Graphics/GObject.cpp
	src/Graphics/Square.cpp
        src/Graphics/GESpriteSheet.cpp
        src/Graphics/GETileMap.cpp
        src/Graphics/GESpriteAnimation.cpp

	src/DebugGames/CollisionTest.cpp
	src/DebugGames/ScrollingTest.cpp
        src/DebugGames/PlayerTest.cpp
        src/DebugGames/Player.cpp
        src/DebugGames/gameInput.cpp
        src/DebugGames/GlobalSettings.h
        src/DebugGames/BattleTest.cpp
        src/DebugGames/FontTest.cpp
        src/DebugGames/font.cpp
        src/DebugGames/Word.cpp
        src/DebugGames/DialogueTest.cpp
        src/DebugGames/GameObject.cpp

        src/Game/finalGame.cpp

        src/GameFiles/tilemap.map
)
set(FILEPATH src/GameFiles/)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -g")

file(COPY
            ${FILEPATH}playersprites4x.png
            ${FILEPATH}font4x.png
            ${FILEPATH}textbackground4x.png
            ${FILEPATH}tileimage4x.png
            ${FILEPATH}tilemap.map
            ${FILEPATH}pokemon.json

DESTINATION ${CMAKE_BINARY_DIR} )


target_link_libraries(game ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARY} ${JSONCPP_LIBRARIES} )
