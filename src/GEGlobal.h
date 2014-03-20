﻿/*
 * Global.h
 *
 *  Created on: 12/02/2014
 *      Author: jordy
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#define GE_GLOBAL_SCREEN_NAME "Pokemon Clone by Jordy"
#define GE_GLOBAL_SCREEN_HEIGHT 576
#define GE_GLOBAL_SCREEN_WIDTH 640
#define GE_GLOBAL_SCREEN_BPP 32
#define GE_GLOBAL_FPS 20
#define GE_GLOBAL_FILE_PATH  "./"
#define GE_GLOBAL_WORLD_TILEMAP_NAME "tileimage4x.png"
#define GE_GLOBAL_TILE_MAP_FILE "tilemap.map"
#define GE_GLOBAL_PLAYER_TILEMAP "playersprites4x.png"
#define GE_GLOBAL_FONT_IMAGE "font4x.png"
#define GE_GLOBAL_TILESIZE (16*4)
#define GE_GLOBAL_COLOR_KEY_FOR_ALPHA 255,0,0
#define GE_GLOBAL_MAP_HEIGHT_IN_TILES 20
#define GE_GLOBAL_MAP_WIDTH_IN_TILES 20


#define GE_LOG(STRING) cout << STRING << endl
#define GE_MAX(A,B) (A) > (B) ? (A) : (B)
#define GE_ABS(N) N < 0 ? -(N) : (N)
#define GE_MIN(A,B) (A) < (B) ? (A) : (B)

#endif /* GLOBAL_H_ */
