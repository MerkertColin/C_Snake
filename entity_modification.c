#include <math.h>
#include <stdlib.h>

#include "entity_modification.h"

void initGameObjects( TGameObjects* objects )
{
    //APPLE
    objects->apple.icon = '+';
    //Apple pos
    objects->apple.pos = calcApplePos();

    //BOARD
    objects->board.border = '#';
    objects->board.whitespace = ' ';

    //SNAKE
    objects->snake.icon = '^';
    objects->snake.length = 0;
    //Snake dir
    objects->snake.dir.x = 0;
    objects->snake.dir.y = -1;
    //Snake pos
    objects->snake.pos.x = (int)ceil( N_PLAY_AREA_WIDTH / 2 );
    objects->snake.pos.y = (int)ceil( N_PLAY_AREA_HEIGHT / 2 );
    for ( int i = 0; i < N_PLAY_AREA_SIZE; i++ )
    {
        objects->snake.s_tail[i].icon = 'o';
        objects->snake.s_tail[i].pos.x = 0;
        objects->snake.s_tail[i].pos.y = 0;
        objects->snake.tail[i].x = 0;
        objects->snake.tail[i].y = 0;
    }
}

void addTail( TSnake* snake )
{
    snake->length++;
}

void setDir( TPoint* dir, int horizontal, int vertical )
{
    dir->x = horizontal;
    dir->y = vertical;
}

TPoint calcApplePos( void )
{
    TPoint newPos = {
        .x = ( rand() % ( N_PLAY_AREA_WIDTH ) ) + 1,
        .y = ( rand() % ( N_PLAY_AREA_HEIGHT ) ) + 1
    };
    return newPos;
}

void updateSnake( TSnake* snake )
{
    char prevIcon = snake->icon;
    TPoint prevPos = {
        .x = snake->pos.x,
        .y = snake->pos.y
    };
    snake->pos.x += snake->dir.x;
    snake->pos.y += snake->dir.y;
    for ( int i = snake->length - 1; i >= 0; i-- )
    {
        if ( i == 0 )
        {
            snake->s_tail[i].icon = prevIcon;
            snake->s_tail[i].pos.x = prevPos.x;
            snake->s_tail[i].pos.y = prevPos.y;
            snake->tail[i].x = prevPos.x;
            snake->tail[i].y = prevPos.y;
        }
        else
        {
            snake->s_tail[i].icon = snake->s_tail[i - 1].icon;
            snake->s_tail[i].pos.x = snake->s_tail[i - 1].pos.x;
            snake->s_tail[i].pos.y = snake->s_tail[i - 1].pos.y;
            snake->tail[i].x = snake->tail[i - 1].x;
            snake->tail[i].x = snake->tail[i - 1].x;
            snake->tail[i].y = snake->tail[i - 1].y;
        }
    }

}