#ifndef _DEFINES_H_
#define _DEFINES_H_

#define MAX_ROUNDS 1

#define BOARD_W 10
#define BOARD_H 10

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

#endif //_DEFINES_H_
