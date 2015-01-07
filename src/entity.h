/*
 * File:   entity.h
 * Author: gareth
 *
 * Created on 27 June 2014, 21:46
 */

#ifndef ENTITY_H
#define	ENTITY_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <cstdio>
#include "graphics.h"

class Entity {

public:

  bool isActive;
  int speed;
  int x, y, w, h;
  SDL_Texture* sprite;
  int currentFrame, animID, frameTimer;
  Entity();
  virtual ~Entity();
  virtual void Load( std::string file, SDL_Renderer* &loadRenderer, int x, int y, int width, int height );
  virtual void Update();
  virtual void Render( SDL_Renderer* &entityRenderer );
  virtual void Cleanup();

};



#endif	/* ENTITY_H */
