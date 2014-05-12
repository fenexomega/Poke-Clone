/*
 * Graphics.cpp
 *
 *  Created on: 15/02/2014
 *      Author: jordy
 */

#include "GEGraphicsCore.h"

GEGraphicsCore::GEGraphicsCore() {

}

GEGraphicsCore::~GEGraphicsCore() {
}

void GEGraphicsCore::UpdateScreen()
{
    SDL_Flip(screen);
}

void GEGraphicsCore::drawSurface_Rect(SDL_Surface* src, SDL_Surface* dest, SDL_Rect offset) {
    //Colar a surface src na surface Destino
    SDL_BlitSurface(src, NULL, dest, &offset);
}

void GEGraphicsCore::DrawRectangle(int x, int y, int w,int h,Uint32 color)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    offset.h = h;
    offset.w = w;
    SDL_FillRect(screen,&offset,color);
}


void GEGraphicsCore::Grid(Uint32 color ,int size)
{
    for(int x = 0; x < GE_GLOBAL_SCREEN_WIDTH; x += size)
    {
        GEGraphicsCore::DrawRectangle(x,0,1,GE_GLOBAL_SCREEN_HEIGHT,color);
    }
    for(int y = 0; y < GE_GLOBAL_SCREEN_HEIGHT; y += size)
    {
        GEGraphicsCore::DrawRectangle(0,y,GE_GLOBAL_SCREEN_WIDTH,1,color);
    }
}

void GEGraphicsCore::drawSurface_Pos(int x, int y, SDL_Surface* source,
                                     SDL_Surface* destination,SDL_Rect *sourceRect) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    //BLIT Surface
    SDL_BlitSurface(source, sourceRect, destination, &offset);
}

void GEGraphicsCore::clearScreen( char r, char g,  char b) {
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, r, g, b));
}

void GEGraphicsCore::clearScreen(Uint32 color) {
    SDL_FillRect(screen, NULL, color);
}

bool GEGraphicsCore::initGraphics() {
    GE_LOG("Initializing Graphics.");
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        GE_LOG("Graphics cannot be initialized: \n\n" << SDL_GetError());
        return false;
    }

    screen = SDL_SetVideoMode(GE_GLOBAL_SCREEN_WIDTH,
                              GE_GLOBAL_SCREEN_HEIGHT, GE_GLOBAL_SCREEN_BPP, SDL_SWSURFACE);

    if (screen == NULL)
        return false;
    string caption = GE_GLOBAL_SCREEN_NAME;
    caption.append(GE_GLOBAL_ENGINE_VERSION);
    
    SDL_WM_SetCaption(caption.c_str(), NULL);

    return true;
}


SDL_Surface * GEGraphicsCore::loadSprite(string location)
{
    SDL_Surface *loaded_image = NULL;

    SDL_Surface *optimized_image = NULL;

    location = GE_GLOBAL_FILE_PATH + location;

    if((loaded_image = IMG_Load(location.c_str())) == NULL)
        cout << SDL_GetError() << endl;

    if(loaded_image != NULL)
    {
        optimized_image = SDL_DisplayFormat(loaded_image);

        SDL_FreeSurface(loaded_image);

        if(optimized_image != NULL)
        {
            Uint32 colorkey = SDL_MapRGB(optimized_image->format,GE_GLOBAL_COLOR_KEY_FOR_ALPHA);

            //Coloca pra todos os pixels dessa cor serem transparentes no surface.
            SDL_SetColorKey(optimized_image, SDL_SRCCOLORKEY, colorkey);
        }

    }
    return optimized_image;

}

