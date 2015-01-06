#include "background.h"

//resetStarBackground - randomly places stars on screen with a random speed
// @param star - the array of stars we use as the background

void resetStarBackground( Star stars[NUM_STARS] ) {
    for( int i = 0; i < NUM_STARS; ++i ) {
        stars[i].x = rand() % SCREEN_WIDTH;
        stars[i].y = rand() % SCREEN_HEIGHT;
        stars[i].speed = 1 + ( rand() % 12 );
    }

}

//doStarBackground - loops through the stars and moves them backwards
//by subtracting the speed from the star's current position
//@param stars - the array of stars we use as the background

void doStarBackground( Star stars[NUM_STARS] ) {
    for( int i = 0; i < NUM_STARS; ++i ) {
        stars[i].x -= stars[i].speed;

        if( stars[i].x < 0) {
            stars[i].x = SCREEN_WIDTH + rand() % 20;
            stars[i].y = rand() % SCREEN_HEIGHT;
            stars[i].speed = 1 + ( rand() % 12 );
        }
    }

}

//updateStarBackground - updates the background
//@param - updateSurface - the SDL Surface we blit to
//@param - stars - the array of stars we use as the background

void updateStarBackground( SDL_Surface* &updateSurface, Star stars[NUM_STARS] ) {
    SDL_Rect rect;

    SDL_FillRect( updateSurface, NULL, 0 );
    for( int i = 0; i < NUM_STARS; ++i ) {
        if( stars[i].x < SCREEN_WIDTH ) {
            rect.x = stars[i].x;
            rect.y = stars[i].y;
            rect.w = 1;
            rect.h = 1;

            SDL_FillRect( updateSurface, &rect, getStarColor( stars[i].speed, updateSurface ) );
        }
    }

}

//getStarColor - assigns a color based on the speed of the star
//@param - speed - the speed of the star assigned
//@param - colorSurface - the SDL Surface being passed to set the RGB values on
//@return MapRGB - we map the RGB value and then return it

int  getStarColor( int speed, SDL_Surface* &colorSurface ) {
    SDL_Color color;

    switch( speed ) {

    case 1:
    case 2:
    case 3:
        color.r = 159;
        color.g = 159;
        color.b = 159;
        break;
    case 4:
    case 5:
    case 6:
        color.r = 191;
        color.g = 191;
        color.b = 191;
        break;
    default:
        color.r = 255;
        color.g = 255;
        color.b = 255;
        break;
    }
    return SDL_MapRGB( colorSurface->format, color.r, color.g, color.b );
}
