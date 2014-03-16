project(TRABALHOSI)
cmake_minimum_required(VERSION 2.8)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)

include_directories( ${SDL_INCLUDE_DIR} ${SDL_IMAGE_INCLUDE_DIR} ${SDL_TTF_INCLUDE_DIR} )
add_executable( game
	src/Main.cpp
	src/GEPhysics.cpp
	src/GETimer.cpp
	src/GEGraphicsCore.cpp
        src/GEGlobal.h
        src/GEInput.h
        src/GEGame.h

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
        src/DebugGames/tilemap.map
        src/DebugGames/Player.cpp
        src/DebugGames/gameInput.cpp
        src/DebugGames/GlobalSettings.h

        src/Game/finalGame.cpp
)
set(CMAKE_CXX_FLAGS "-std=c++11 -g")
#file(COPY
target_link_libraries(game ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARY} ${SDL_TTF_LIBRARY} )
