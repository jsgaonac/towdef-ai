#ifndef _DEFINES_H_
#define _DEFINES_H_

#define MAX_ROUNDS 1
#define BOARD_W 10
#define BOARD_H 10

#define ATTACKERS_ALLOC 40
#define DEFENDERS_ALLOC 100

#define ATTACK_HEALTH 200
#define ATTACK_POWER 25
#define ATTACK_SPEED 1

#define DEFENSE_HEALTH  100
#define DEFENSE_POWER 7
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

#define ADD_DESTROY_POINTS 150 	// Give points for each enemy destroyed.
#define ADD_LIFE_POINTS 3 		// Give points for each life point kept.

#define SUB_NUMBER_OF_TOWERS 50	// Take points for each tower put.
#define SUB_RESPAWN_BLOCK 5000	// Penalize for blocking the respawn point with a tower.
#define SUB_BLOCK_PATH 7000	// Penalize for blocking all the paths from respawn to player's tower.
#define SUB_TOWER_DESTROYED 2500 // Penalize for losing the game.

// This value depends on the previous values.
#define MAX_VALUE 8523
#define MIN_VALUE -12000

#define POPULATION_SIZE 100
#define CHROM_LENGTH 100

#endif //_DEFINES_H_
