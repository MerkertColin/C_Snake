#ifndef ENTITY_MODIFICATION_H
#define ENTITY_MODIFICATION_H

#include "game_entities.h"

void initGameObjects( TGameObjects* gameObjects );
void addTail( TSnake* snake );
void setDir( TPoint* dir, int horizontal, int vertical );
TPoint calcApplePos( void );
void updateSnake( TSnake* snake );

#endif