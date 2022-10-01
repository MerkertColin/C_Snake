#ifndef COLLISION_H
#define COLLISION_H

#include "game_entities.h"

int isExactPosition( int* col, int* row, TPoint* pos );
int isExactPositionP( TPoint* p1, TPoint p2 );
int tailHasPos( int* col, int* row, TSnake* pos );
void detectCollision( TGameObjects* go, TState* state );

#endif
