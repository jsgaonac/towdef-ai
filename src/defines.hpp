#ifndef _DEFINES_H_
#define _DEFINES_H_

#define MAX_ROUNDS 1

#define BOARD_W 10
#define BOARD_H 10

#define ATTACKERS_ALLOC 40
#define DEFENDERS_ALLOC 100

#define ATTACK_HEALTH 200
#define ATTACK_POWER 50
#define ATTACK_SPEED 1

#define DEFENSE_HEALTH  100
#define DEFENSE_POWER 10
#define DEFENSE_SPEED 1

#define PLAYER_HEALTH 1000
#define PLAYER_POWER 1000
#define PLAYER_SPEED 0

// Where the attackers will respawn. This is relative to the board coordinates.
#define RESPAWN_X 0
#define RESPAWN_Y 0

// The player's tower coordinate. The tower NEVER moves.
#define PLAYER_X (BOARD_W - 1)
#define PLAYER_Y (BOARD_H - 1)

#define WINDOW_W 800
#define WINDOW_H 600
#define WINDOW_BPP 32

#define GRID_W ((float)WINDOW_W / BOARD_W)
#define GRID_H ((float)WINDOW_H / BOARD_H)

// Score points.

#define ADD_DESTROY_POINTS 150
#define ADD_LIFE_POINTS 3

#define SUB_LIFE_POINTS 3.5
#define SUB_NUMBER_OF_TOWERS 20
#define SUB_RESPAWN_BLOCK 2000
#define SUB_BLOCK_PATH 15000
#define SUB_TOWER_DESTROYED 5000

// This value depends on the previous values.
#define MAX_VALUE 8600
#define MIN_VALUE -15000

#endif //_DEFINES_H_
