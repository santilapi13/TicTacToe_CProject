#include "game.h"

// Empties cells and resets winner and current player 
void reset_game(int board[3][3], int *winner, int *current_player) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;
    *winner = EMPTY;
    *current_player = PLAYER_X;
}

int checkForWinners(int board[3][3], int win_pos[2]) {
    int winner = 0;
    // Check rows for winners 
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == PLAYER_X)
                winner = PLAYER_X;
            else if (board[i][0] == PLAYER_O)
                winner = PLAYER_O;
            win_pos[0] = ROW;
            win_pos[1] = i;
        }
    }
    // Check columns for winners
    for (int i = 0; i < 3; i++) {
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == PLAYER_X)
                winner = PLAYER_X;
            else if (board[0][i] == PLAYER_O)
                winner = PLAYER_O;
            win_pos[0] = COL;
            win_pos[1] = i;
        }
    }
    // Check diagonals for winners
    if (board[1][1] != EMPTY && (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        if (board[1][1] == PLAYER_X)
            winner = PLAYER_X;
        else if (board[1][1] == PLAYER_O)
            winner = PLAYER_O;
        win_pos[0] = (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ? MAIN_DIAG : SEC_DIAG;
    }
    // Check for tie    
    if (winner == EMPTY) {
        int sum = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                sum += board[i][j];
        if (sum == 13)
            winner = TIE;
    }

    return winner;
} 

void handleEvents(int board[3][3], int *current_player, SDL_Window* window, int* running, int *winner, int win_pos[2]) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            // Quits when window closes
            case SDL_WINDOWEVENT_CLOSE: {   
                if (window) {
                    SDL_DestroyWindow(window);
                    window = NULL;
                    *running = 0;
                }
            }
            break;
            case SDL_KEYDOWN: { 
                switch (event.key.keysym.sym) {
                    // Quits when ESC is pressed
                    case SDLK_ESCAPE:  
                        *running = 0;
                    break;
                }
            }
            break;
            case SDL_QUIT:
                *running = 0;
            break;
            // Handles mouse clicks
            case SDL_MOUSEBUTTONDOWN: {
                int x, y;
                SDL_GetMouseState(&x, &y);  // Gets click position

                int row = y / SQUARE_SIZE;  // Gets row
                int col = x / SQUARE_SIZE;  // Gets column

                if (board[row][col] == EMPTY) {
                    // Marks cell, checks for winners and changes turns
                    board[row][col] = *current_player;   
                    *winner = checkForWinners(board, win_pos);
                    if (*current_player == PLAYER_X)
                        *current_player = PLAYER_O;
                    else
                        *current_player = PLAYER_X;
                }
            }
        }
    }
}