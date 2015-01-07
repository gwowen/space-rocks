#ifndef SHIP_H
#define SHIP_H

#include "entity.h"
#include "defs.h"

class Ship: public Entity {
public:
  int shipXVel;
  int shipYVel;

  Ship();
  void Load( std::string file, SDL_Renderer* &shipLoadRenderer, int x, int y, int width, int height );
  void Render( SDL_Renderer* &shipDrawRenderer );
  void Cleanup();
  void Loop();
};

#endif
