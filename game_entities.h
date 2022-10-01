#ifndef GAME_STRUCTS_H
#define GAME_STRUCTS_H

#include "game_constants.h"

typedef enum EStates
{
    START = 0,
    RUNNING,
    PAUSE,
    LOST,
    EXIT
} TState;

typedef struct SPoint
{
    int x;
    int y;
} TPoint;

typedef struct SSegment
{
    char icon;
    TPoint pos;
} TSegment;

typedef struct SSnake
{
    int length;
    char icon;
    TPoint pos;
    TSegment s_tail[N_PLAY_AREA_SIZE];
    TPoint tail[N_PLAY_AREA_SIZE];
    TPoint dir;
} TSnake;

typedef struct SBoard
{
    char border;
    char whitespace;
} TBoard;

typedef struct SApple
{
    char icon;
    TPoint pos;
} TApple;

typedef struct SGameObjects
{
    TSnake snake;
    TBoard board;
    TApple apple;
} TGameObjects;

#endif 
