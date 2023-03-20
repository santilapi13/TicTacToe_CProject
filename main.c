#include <SDL2/SDL.h>
#include "draw.h"
#include "draw.c"
#include "game.h"
#include "game.c"

int main(int argc, char *argv[]) {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Tic-Tac-Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int current_player, winner, board[3][3], win_pos[2];
    reset_game(board, &winner, &current_player);

    // GAME LOOP
    int running = 1;
    while (running) {
        // Handle user events
        handleEvents(board, &current_player, window, &running, &winner, win_pos);
        draw_board(renderer, board, winner, win_pos);

        // Reset if someone won or tied
        if (winner != EMPTY) {
            SDL_Delay(2000);
            reset_game(board, &winner, &current_player);
        }

        SDL_Delay(100);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;

}