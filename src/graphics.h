/*
 * File:   graphics.h
 * Author: gareth
 *
 * Created on 18 January 2014, 18:09
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

SDL_Texture* textureLoad( std::string fileName , SDL_Renderer* &texLoadRenderer);

void textureDraw( SDL_Texture* &drawTex, SDL_Renderer* &drawRenderer, int x, int y );

//static SDL_Texture* drawText( TTF_Font* &drawFont, SDL_Renderer* &drawTextRenderer, std::string inputText );




#endif	/* GRAPHICS_H */
