/* 
 * File:   playstate.h
 * Author: gareth
 *
 * Created on 16 January 2014, 20:17
 */

#ifndef PLAYSTATE_H
#define	PLAYSTATE_H
#include <SDL2/SDL.h>
#include "gamestate.h"
#include "graphics.h"

class playState: public gameState {
    
    public:
        void Init( gameEngine* game );
        void Cleanup();
        
        void Pause();
        void Resume();
        
        void handleEvents( gameEngine* game );
        void Update( gameEngine* game );
        void Draw( gameEngine* game );
        
        static playState* Instance() {
          return &m_playState;  
        }
        
        protected:
            playState() {}
            
        private:
            static playState m_playState;
            
            SDL_Texture* temp;
            
    
};



#endif	/* PLAYSTATE_H */

