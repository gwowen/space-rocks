//appwindow.cpp -  a basic SDL window
#include "gameengine.h"
#include "playstate.h"

int main( int argc, char* argv[] ) {
    gameEngine game;
    
    if( !game.Init("Test") ) {
        printf( "Game failed to initialize\n");
    }
    
    game.changeState( playState::Instance() );
    
    while( game.Running() ) {
       game.handleEvents();
       game.Update();
       game.Draw();
    }
    
    game.Cleanup();
    
    return 0;
}
