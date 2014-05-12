project("TRABALHO SI RPG" CXX C)
cmake_minimum_required(VERSION 2.8)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
#aux_source_directory(src/ SRC_LIST)
#aux_source_directory(src/Graphics SRC_GRAPH)
#aux_source_directory(src/DebugGames SRC_DG)
#aux_source_directory(src/jsoncpp SRC_JSON)
#aux_source_directory(src/GameFiles SRC_GF)
#aux_source_directory(src/Game SRC_GAME)

file(GLOB_RECURSE variable src/*.cpp src/*.h)

add_executable( game ${variable}
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


set(CMAKE_CXX_FLAGS "-Wall")

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
