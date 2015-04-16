#ifndef _DEFINES_H_
#define _DEFINES_H_

#define MAX_ROUNDS 7

#define BOARD_W 20
#define BOARD_H 20

#define ATTACK_HEALTH 50
#define ATTACK_POWER 50
#define ATTACK_SPEED 1

#define DEFENSE_HEALTH  100
#define DEFENSE_POWER 15
#define DEFENSE_SPEED 1

#define PLAYER_HEALTH 500
#define PLAYER_POWER 1000
#define PLAYER_SPEED 0

// Where the attackers will respawn. This is relative to the board coordinates.
#define RESPAWN_X 0
#define RESPAWN_Y 0

// The player's tower coordinate. The tower NEVER moves.
#define PLAYER_X (BOARD_W - 1)
#define PLAYER_Y (BOARD_H - 1)

#endif //_DEFINES_H_
