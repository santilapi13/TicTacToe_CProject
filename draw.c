#include "draw.h"
#include "math.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define DEG2RAD 360.0/M_PI/2.0

// Draws an X in board cell
void draw_x(SDL_Renderer* renderer, int x, int y) {
    SDL_SetRenderDrawColor(renderer, 234, 45, 45, 255);
    SDL_RenderDrawLine(renderer, x, y, x + SQUARE_SIZE, y + SQUARE_SIZE);
    SDL_RenderDrawLine(renderer, x, y + SQUARE_SIZE, x + SQUARE_SIZE, y);
}

// Draws an O in board cell
void draw_o(SDL_Renderer* renderer, int x, int y) {
    SDL_SetRenderDrawColor(renderer, 45, 151, 234, 255);
    for (int i = 0; i < 1080; i++) {
        float degInRad = i * DEG2RAD;
        SDL_RenderDrawPoint(renderer, x + SQUARE_SIZE / 2 + cos(degInRad) * SQUARE_SIZE / 2, y + SQUARE_SIZE / 2 + sin(degInRad) * SQUARE_SIZE / 2);
    }
}

// Draws the board
void draw_board(SDL_Renderer *renderer, int board[3][3], int winner, int win_pos[2]) {	
    SDL_SetRenderDrawColor(renderer, 205, 244, 245, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 60, 68, 66, 255);

    // Draws the grid
    for (int i = 0; i < 3; i++) {
        SDL_RenderDrawLine(renderer, 0, i * SQUARE_SIZE, SCREEN_WIDTH, i * SQUARE_SIZE);
        SDL_RenderDrawLine(renderer, i * SQUARE_SIZE, 0, i * SQUARE_SIZE, SCREEN_HEIGHT);
    }
    // Calls the draw functions for each cell
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == PLAYER_X)
                draw_x(renderer, j * SQUARE_SIZE, i * SQUARE_SIZE);
            else if (board[i][j] == PLAYER_O)
                draw_o(renderer, j * SQUARE_SIZE, i * SQUARE_SIZE);
        }
    }
    // Draws the winning line (if there should be one)
    if (winner > 0) {
        SDL_SetRenderDrawColor(renderer, 214, 16, 208, 255);

        if (win_pos[0] == ROW) 
            SDL_RenderDrawLine(renderer, 0, win_pos[1] * SQUARE_SIZE + SQUARE_SIZE / 2, SCREEN_WIDTH, win_pos[1] * SQUARE_SIZE + SQUARE_SIZE / 2);
        else if (win_pos[0] == COL) 
            SDL_RenderDrawLine(renderer, win_pos[1] * SQUARE_SIZE + SQUARE_SIZE / 2, 0, win_pos[1] * SQUARE_SIZE + SQUARE_SIZE / 2, SCREEN_HEIGHT);
        else if (win_pos[0]  == MAIN_DIAG) 
            SDL_RenderDrawLine(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        else if (win_pos[0] == SEC_DIAG) 
            SDL_RenderDrawLine(renderer, SCREEN_WIDTH, 0, 0, SCREEN_HEIGHT);
    }
    
    SDL_RenderPresent(renderer); 
}