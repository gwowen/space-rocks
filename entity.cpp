#include "entity.h"

std::vector<Entity*> Entity::entityList;

Entity::Entity() {
  texEntity = NULL;
}

Entity::~Entity() {

}

void Entity::Load( std::string file, SDL_Renderer* &loadRenderer, int x, int y, int width, int height ) {
  texEntity = textureLoad( file.c_str(), loadRenderer );
  entityBox.x = x;
  entityBox.y = y;
  entityBox.h = height;
  entityBox.w = width;
  printf( "File %s loaded successfully!\n", file.c_str() );
}

void Entity::Event() {

}

void Entity::Render( SDL_Renderer* &entityRenderer ) {
  textureDraw( texEntity, entityRenderer, entityBox.x, entityBox.y );
}

void Entity::Cleanup() {
  SDL_DestroyTexture( texEntity );
  texEntity = NULL;
}
