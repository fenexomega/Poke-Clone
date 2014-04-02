project("TRABALHO SI RPG" CXX C)
cmake_minimum_required(VERSION 2.8)
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
        src/DebugGames/Pokemon.cpp

        src/Game/finalGame.cpp

        src/GameFiles/tilemap.map
        src/GameFiles/pokemon.json
        src/GameFiles/pokemonList.json

        src/jsoncpp/json/json.h
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

DESTINATION ${CMAKE_BINARY_DIR} )

if(UNIX)
    message("Unix Detected, using libraries for Linux")
    include_directories( ${SDL_INCLUDE_DIR} ${SDL_IMAGE_INCLUDE_DIR} )
    set(CMAKE_CXX_FLAGS "-Wall -g")
    target_link_libraries(game ${SDL_LIBRARY} ${SDL_IMAGE_LIBRARY} )
else(UNIX)
    message("Windows Detected, using libraries for windows")
    set(CMAKE_CXX_FLAGS "-Wall" )
    set(LINKER_WIN_LIBS  -lmingw32 
    -lSDLmain -lSDL -lwinmm  -mwindows -liconv -lm -luser32 -lgdi32 -lwinmm -ldxguid
    -ltiff -llzma -ljpeg -lpng16 -lz -lSDL_image)
    target_link_libraries(game ${LINKER_WIN_LIBS})
endif(UNIX)

