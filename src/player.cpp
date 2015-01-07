#include "ship.h"

Ship::Ship() {
  shipXVel = 0;
  shipYVel = 0;
}

void Ship::Load( std::string file, SDL_Renderer* &shipLoadRenderer, int x, int y, int width, int height ) {
  Entity::Load( file, shipLoadRenderer, x, y, width, height );
}

void Ship::Render( SDL_Renderer* &shipLoadRenderer ) {
  Entity::Render( shipLoadRenderer );
}

void Ship::Loop() {

  entityBox.x += shipXVel;
  entityBox.y += shipYVel;

  if( entityBox.x < 0 ) {
    entityBox.x = 0;
  }
  else if( entityBox.x + entityBox.w > SCREEN_WIDTH ) {
    entityBox.x = entityBox.x - entityBox.w;
  }

  if( entityBox.y <= 0) {
    entityBox.y = 0;
  }
  else if( entityBox.y + entityBox.h > SCREEN_HEIGHT ) {
    entityBox.y = SCREEN_HEIGHT - entityBox.h;
  }

}

void Ship::Cleanup() {
  Entity::Cleanup();
}
