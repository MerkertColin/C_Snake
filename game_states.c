#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "drawing.h"
#include "collision.h"
#include "game_entities.h"
#include "entity_modification.h"

TState ExecStart( TGameObjects* go )
{
    TState nextState = RUNNING;

    drawStart();
    printf( "Press any Button to start..." );
    _getch();
    initGameObjects( go );

    return nextState;
}

TState ExecPause( TGameObjects* go )
{
    system( "cls" );
    drawPauseArea( go );
    _getch();
    return RUNNING;
}

TState ExecRunning( TGameObjects* go )
{
    TState nextState = RUNNING;
    drawPlayArea( go );
    nextState = input( go );
    updateSnake( &go->snake );
    detectCollision( go, &nextState );
    return nextState;
}

TState askRetry()
{
    TState nextState = EXIT;
    char sIn[2] = "";
    printf( "Retry?(Y/N): " );
    scanf_s( "%s", sIn, 2 );
    if ( 0 == strcmp( sIn, "y" ) || 0 == strcmp( sIn, "Y" ) )
    {
        nextState = START;
    }
    return nextState;
}

TState ExecLost( void )
{
    drawGameOver();
    return askRetry();
}