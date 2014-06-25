/* 
 * File:   background.h
 * Author: gareth
 *
 * Created on 25 June 2014, 19:22
 */

#ifndef BACKGROUND_H
#define	BACKGROUND_H
#include <SDL2/SDL.h>
#include "defs.h"

typedef struct Star {
    int x, y, speed;
} Star;

void resetStarBackground( Star stars[NUM_STARS] );
void doStarBackground( Star stars[NUM_STARS] );
void updateStarBackground( SDL_Surface* &updateSurface, Star stars[NUM_STARS] );
int  getStarColor( int, SDL_Surface* &colorSurface );


#endif	/* BACKGROUND_H */

