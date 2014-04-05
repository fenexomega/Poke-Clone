project("TRABALHO SI RPG" CXX C)
cmake_minimum_required(VERSION 2.8)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
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
        src/GERandom.cpp

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
        src/DebugGames/BattleTest.cpp
        src/DebugGames/FontTest.cpp
        src/DebugGames/DialogueTest.cpp
        src/DebugGames/RandTest.cpp

        src/Game/finalGame.cpp

        src/GameFiles/tilemap.map
        src/GameFiles/pokemon.json
        src/GameFiles/pokemonList.json        

        src/Game/Game_Classes/Pokemon.cpp
        src/Game/Game_Classes/font.cpp
        src/Game/Game_Classes/Word.cpp
        src/Game/Game_Classes/Player.cpp
        src/Game/Game_Classes/gameInput.cpp
        src/Game/Game_Classes/GlobalSettings.h
        src/Game/Game_Classes/GameObject.cpp
        src/Game/Game_Classes/Move.cpp

#JSONCPP
        src/jsoncpp/json_reader.cpp
        src/jsoncpp/json_value.cpp
        src/jsoncpp/json_writer.cpp
)
set(FILEPATH src/GameFiles/)

file(COPY
            ${FILEPATH}playersprites4x.png
            ${FILEPATH}font4x.png
            ${FILEPATH}textbackground4x.png
            ${FILEPATH}tileimage4x.png
            ${FILEPATH}tilemap.map
            ${FILEPATH}pokemon.json

DESTINATION ${CMAKE_BINARY_DIR}/Content )


set(CMAKE_CXX_FLAGS "-Wall -g")

if(UNIX)
    message("Unix Detected, using shared libraries for Linux")
    include_directories( ${SDL_INCLUDE_DIR} ${SDL_IMAGE_INCLUDE_DIR} )
    set(COMPILER_LIBS ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARY})
else(UNIX)
    message("Windows Detected, using static libraries for Windows")
    set(COMPILER_LIBS  -lmingw32 
    -lSDLmain -lSDL -lwinmm  -mwindows -liconv -lm -luser32 -lgdi32 -lwinmm -ldxguid
    -ltiff -llzma -ljpeg -lpng16 -lz -lSDL_image)
endif(UNIX)

target_link_libraries(game ${COMPILER_LIBS} )
