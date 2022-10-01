#ifndef GAME_STATES_H
#define GAME_STATES_H

#include "game_entities.h"

TState ExecStart( TGameObjects* go );
TState ExecRunning( TGameObjects* go );
TState ExecPause( TGameObjects* go );
TState ExecLost(void);


#endif
