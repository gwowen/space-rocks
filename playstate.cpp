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

    bgSurface = SDL_CreateRGBSurface( 0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
                                      0,
                                      0,
                                      0,
                                      0 );

    bgTexture = SDL_CreateTexture( game->gameRenderer,
                                    SDL_PIXELFORMAT_ARGB8888,
                                    SDL_TEXTUREACCESS_STREAMING,
                                    SCREEN_WIDTH, SCREEN_HEIGHT );

    shipTest = textureLoad( "../assets/firefly.png", game->gameRenderer);
    testShip.Load( "../assets/firefly.png", game->gameRenderer, 200, 200, 25, 14 );
    Entity::entityList.push_back( &testShip );


  resetStarBackground( bgStars );

}

void playState::Cleanup() {

  SDL_DestroyTexture( bgTexture );
  SDL_DestroyTexture( temp );
  for( int i = 0; i < Entity::entityList.size(); ++i ) {
    if( !Entity::entityList[i] ) continue;
    Entity::entityList[i]->Cleanup();
  }

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

        if( event.type == SDL_KEYDOWN && event.key.repeat == 0 ) {
            switch( event.key.keysym.sym ) {
                case SDLK_w: testShip.shipYVel -= SHIP_VEL; break;
                case SDLK_s: testShip.shipYVel += SHIP_VEL; break;
                case SDLK_a: testShip.shipXVel -= SHIP_VEL; break;
                case SDLK_d: testShip.shipXVel += SHIP_VEL; break;
                case SDLK_ESCAPE: game->Quit();
                default:break;
            }
        }
        else if( event.type == SDL_KEYUP && event.key.repeat == 0 ) {
          switch( event.key.keysym.sym ) {
          case SDLK_w: testShip.shipYVel += SHIP_VEL; break;
          case SDLK_s: testShip.shipYVel -= SHIP_VEL; break;
          case SDLK_a: testShip.shipXVel += SHIP_VEL; break;
          case SDLK_d: testShip.shipXVel -= SHIP_VEL; break;
          default: break;
            }
        }
    }
}

void playState::Update( gameEngine* game) {

    doStarBackground( bgStars );
    updateStarBackground( bgSurface, bgStars );
    testShip.Loop();
}

void playState::Draw( gameEngine* game) {

    SDL_UpdateTexture( bgTexture, NULL, bgSurface->pixels, bgSurface->pitch );
    SDL_RenderCopy( game->gameRenderer, bgTexture, NULL, NULL );

    for( int i = 0; i < Entity::entityList.size(); ++i ) {
      if( !Entity::entityList[i] ) continue;
      Entity::entityList[i]->Render( game-> gameRenderer);
    }

    SDL_RenderPresent( game->gameRenderer );

}
