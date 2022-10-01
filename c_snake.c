#include <math.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#include "game_states.h"
#include "game_entities.h"
#include "entity_modification.h"

TState input( TGameObjects* go )
{
    TPoint* dir = &go->snake.dir;
    char cUpHead = '^';
    char cDownHead = 'v';
    char cLeftHead = '<';
    char cRightHead = '>';
    TState nextState = RUNNING;
    if ( _kbhit() )
    {
        switch ( _getch() )
        {
            case 'a':
                if ( dir->x > 0 ) break;
                go->snake.icon = cLeftHead;
                setDir( dir, -1, 0 );
                break;
            case 'd':
                if ( dir->x < 0 ) break;
                go->snake.icon = cRightHead;
                setDir( dir, 1, 0 );
                break;
            case 'w':
                if ( dir->y > 0 ) break;
                go->snake.icon = cUpHead;
                setDir( dir, 0, -1 );
                break;
            case 's':
                if ( dir->y < 0 ) break;
                go->snake.icon = cDownHead;
                setDir( dir, 0, 1 );
                break;
            case ENTER:
                nextState = PAUSE;
                break;
            case ESC:
                nextState = EXIT;
        }
    }
    return nextState;
}

int main()
{
    TGameObjects gameObjects;
    initGameObjects( &gameObjects );
    TState currState = START;
    srand( time( NULL ) );
    do
    {
        switch ( currState )
        {
            case START:
                currState = ExecStart( &gameObjects );
                break;
            case RUNNING:
                currState = ExecRunning( &gameObjects );
                break;
            case PAUSE:
                currState = ExecPause( &gameObjects );
                break;
            case LOST:
                currState = ExecLost();
                break;
            default:
                break;
        }
    } while ( EXIT != currState );
}