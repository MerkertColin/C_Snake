#include "collision.h"
#include "game_constants.h"
#include "entity_modification.h"

int isExactPosition( int* col, int* row, TPoint* p )
{
    return *col == p->x && *row == p->y;
}

int isExactPositionP( TPoint* p1, TPoint* p2 )
{
    return p1->x == p2->x && p1->y == p2->y;
}

int tailHasPos( int* col, int* row, TSnake* s )
{
    int isPos = -1;
    for ( int i = 0; i < s->length; i++ )
    {
        if ( isExactPosition( col, row, &s->tail[i] ) )
        {
            isPos = i;
            break;
        }
    }
    return isPos;
}

int isSnakeCollidingWithTail( TSnake* s )
{
    int nIsCollision = 0;
    for ( int i = 0; i < s->length; i++ )
    {
        nIsCollision = isExactPositionP( &s->pos, &s->tail[i] );
        if ( nIsCollision )
        {
            break;
        }
    }
    return nIsCollision;
}

void detectCollision( TGameObjects* go, TState* state )
{
    TSnake* s = &go->snake;

    int isSnakeCollidingWithBorder = ( s->pos.x > N_PLAY_AREA_WIDTH || s->pos.y > N_PLAY_AREA_HEIGHT ) || ( s->pos.x < 1 || s->pos.y < 1 );
    if ( isExactPositionP( &s->pos, &go->apple.pos ) )
    {
        addTail( &go->snake );
        go->apple.pos = calcApplePos();
    }
    if (  isSnakeCollidingWithBorder || isSnakeCollidingWithTail( s ) )
    {
        *state = LOST;
    }
}