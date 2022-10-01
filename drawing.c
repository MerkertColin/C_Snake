#include <math.h>
#include <stdio.h>
#include <windows.h>

#include "collision.h"
#include "game_entities.h"
#include "game_constants.h"

void drawStart( void )
{
    system( "cls" );
    printf( " __        __   _                          \n" );
    printf( " \\ \\      / /__| | ___ ___  _ __ ___   ___ \n" );
    printf( "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\\n" );
    printf( "   \\ V  V /  __/ | (_| (_) | | | | | |  __/\n" );
    printf( "    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|\n" );
    printf( "\n\n" );
}

void drawPauseArea( TGameObjects* go )
{
    system( "cls" );
    int pauseI = 0;
    char pauseMsg[] = "PAUSE";
    int test = strlen( pauseMsg ) / 2;
    int pauseX = (int)floor( ( N_BOARD_WIDTH / 2 ) - 3 );
    int pauseY = (int)floor( ( N_BOARD_HEIGHT / 2 ) - 1 );
    for ( int row = 0; row < N_BOARD_HEIGHT; row++ )
    {
        printf( S_BOARD_OFFSET_X );
        for ( int col = 0; col < N_BOARD_WIDTH; col++ )
        {
            if ( row == 0 || row == N_BOARD_HEIGHT - 1
                || col == 0 || col == N_BOARD_WIDTH - 1 )
            {
                printf( "%c", go->board.border );
            }
            else if ( row == pauseY && col >= pauseX && col <= pauseX + strlen( pauseMsg ) - 1 )
            {
                printf( "%c", pauseMsg[pauseI++] );
            }
            else
            {
                printf( "%c", go->board.whitespace );
            }
        }
        printf( "\n" );
    }
}

void drawPlayArea( TGameObjects* go )
{
    TBoard* board = &go->board;
    TSnake* snake = &go->snake;
    TApple* apple = &go->apple;
    int nIsTail;

    system( "cls" );
    for ( int row = 0; row < N_BOARD_HEIGHT; row++ )
    {
        printf( S_BOARD_OFFSET_X );
        for ( int col = 0; col < N_BOARD_WIDTH; col++ )
        {
            nIsTail = tailHasPos( &col, &row, &go->snake );
            if ( isExactPosition( &col, &row, &go->snake.pos ) )
            {
                printf( "%c", go->snake.icon );
            }
            else if ( 0 <= nIsTail )
            {
                printf( "%c", go->snake.s_tail[nIsTail].icon );
            }
            else if ( isExactPosition( &col, &row, &apple->pos ) )
            {
                printf( "%c", apple->icon );
            }
            else if ( row == 0 || row == N_BOARD_HEIGHT - 1 || col == 0 || col == N_BOARD_WIDTH - 1 )
            {
                printf( "%c", board->border );
            }
            else
            {
                printf( "%c", board->whitespace );
            }
        }
        printf( "\n" );
    }
    printf( S_BOARD_OFFSET_X );
    printf( "Press 'Enter' to pause\n%sScore: %d", S_BOARD_OFFSET_X, snake->length );
    Sleep( N_SLOW_DOWN );
}

void drawGameOver( void )
{
    system( "cls" );
    printf( "   _____          __  __ ______    ______      ________ _____  \n" );
    printf( "  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ \n" );
    printf( " | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |\n" );
    printf( " | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / \n" );
    printf( " | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ \n" );
    printf( "  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\\n" );
    printf( "\n" );
}