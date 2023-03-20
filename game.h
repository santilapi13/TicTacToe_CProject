#include <SDL2/SDL.h>

#define SQUARE_SIZE 200

#define TIE -1
#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2

#define ROW 0
#define COL 1
#define MAIN_DIAG 2
#define SEC_DIAG 3

void reset_game(int board[3][3], int *winner, int *current_player);

int checkForWinners(int board[3][3], int win_pos[2]);

void handleEvents(int board[3][3], int *current_player, SDL_Window* window, int* running, int *winner, int win_pos[2]);