//playstate.cpp
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "gamestate.h"
#include "gameengine.h"
#include "playstate.h"

playState playState::m_playState;

void playState::Init( gameEngine* game ) {
    
  temp = Texture::textureLoad( "../helloworld.bmp", game->m_Renderer );
    
}

void playState::Cleanup() {

  SDL_DestroyTexture( temp );
    
}

void playState::Pause() {
    
}

void playState::Resume() {
    
}

void playState::handleEvents( gameEngine* game ) {
    SDL_Event event;
    if( SDL_PollEvent( &event ) ) {
        
        if( event.type == SDL_QUIT ) {
            game->Quit();
        }
        
        if( event.type == SDL_KEYDOWN ) {
            switch( event.key.keysym.sym ) {
                case SDLK_ESCAPE: game->Quit();
                default:break;
            }
        }
    }
}

void playState::Update( gameEngine* game) {
    
}

void playState::Draw( gameEngine* game) {
  Texture::textureDraw( temp, game->m_Renderer, 0, 0 );
  SDL_RenderPresent( game->m_Renderer );
    
}
