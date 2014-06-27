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
protected:
  SDL_Texture* texEntity;

public:
  static std::vector<Entity*> entityList;
  SDL_Rect entityBox;

  int entityXVel;
  int entityYVel;

  Entity();
  virtual ~Entity();

  virtual void Load( std::string file, SDL_Renderer* &loadRenderer, int x, int y, int width, int height );
  virtual void Event();
  virtual void Render( SDL_Renderer* &entityRenderer );
  virtual void Cleanup();

};



#endif	/* ENTITY_H */
