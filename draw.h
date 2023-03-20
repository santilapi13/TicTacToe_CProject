#include <SDL2/SDL.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define SQUARE_SIZE 200

#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2

#define ROW 0
#define COL 1
#define MAIN_DIAG 2
#define SEC_DIAG 3

void draw_x(SDL_Renderer* renderer, int x, int y);

void draw_o(SDL_Renderer* renderer, int x, int y);

void draw_board(SDL_Renderer *renderer, int board[3][3], int winner, int win_pos[2]);