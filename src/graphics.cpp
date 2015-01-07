//graphics.cpp
#include "graphics.h"

SDL_Texture* textureLoad(std::string fileName, SDL_Renderer* &texLoadRenderer) {

    SDL_Texture * newTexture = NULL;

    SDL_Surface* tempSurface = IMG_Load( fileName.c_str() );

    if( tempSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image error:%s\n", fileName.c_str(), IMG_GetError() );
    } else {
        SDL_SetColorKey( tempSurface, SDL_TRUE, SDL_MapRGB( tempSurface->format, 0, 0xFF, 0xFF) );
        newTexture = SDL_CreateTextureFromSurface( texLoadRenderer, tempSurface );

        if( newTexture == NULL ) {
            printf( "Unable to create texture from %s! SDL Error: %s", fileName.c_str(), SDL_GetError() );
        }
        printf( "%s loaded successfully!\n", fileName.c_str() );
        SDL_FreeSurface( tempSurface );
        }
    return newTexture;
}

/*SDL_Texture* Texture::drawText(TTF_Font* &drawFont, SDL_Renderer* &drawTextRenderer, std::string inputText) {

    SDL_Color textColor = { 0, 0, 0 };
    SDL_Texture* textTexture = NULL;

    SDL_Surface* tempTextSurface = TTF_RenderText_Solid( drawFont, inputText.c_str(), textColor );

    textTexture = SDL_CreateTextureFromSurface( drawTextRenderer, tempTextSurface );
    SDL_FreeSurface( tempTextSurface );
    return textTexture;
}*/

void textureDraw(SDL_Texture* &drawTex, SDL_Renderer*& drawRenderer, int x, int y )
{

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;

    SDL_QueryTexture( drawTex, NULL, NULL, &dest.w, &dest.h );

    SDL_RenderCopy( drawRenderer, drawTex, NULL, &dest );
}
