#include <stdio.h>
#include "game_debug.h"

void printPoint( TPoint* p )
{
    printf( "X:%d\nY:%d", p->x, p->y );
}

void printSnakeParams( TSnake* s )
{
    printf( "------ SNAKE ------" );
    printf( "\n" );
    printf( "Icon: %c", s->icon );
    printf( "\n" );
    printf( "Length: %d", s->length );
    printf( "\n" );
    printPoint( &s->pos );
    printf( "\n\n" );
}

void printBoardParams( TBoard* b )
{
    printf( "------ BOARD------" );
    printf( "\n" );
    printf( "Border: %c", b->border );
    printf( "\n" );
    printf( "Whitespace: \"%c\"", b->whitespace );
    printf( "\n\n" );
}

void printAppleParams( TApple* a )
{
    printf( "------ APPLE ------" );
    printf( "\n" );
    printf( "Icon: %c", a->icon );
    printf( "\n" );
    printPoint( &a->pos );
    printf( "\n\n" );
}

void debugPrint( TGameObjects* go )
{
    printSnakeParams( &go->snake );
    printAppleParams( &go->apple );
    printBoardParams( &go->board );
}