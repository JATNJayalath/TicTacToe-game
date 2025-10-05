#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>

//Functions

char** initialize_board(int n);
void display_board(char** board, int n);
void get_user_input(int *row, int *column, int n);
int is_valid_move(char** board, int n, int row, int column);
int check_win(char** board, int n, char symbol);
int check_draw(char** board, int n);
void log_file(FILE* logFile, char** board, int n);
void computer_move(char** board, int n, int *row, int *column);

//Game Modes

void Two_player_game(int n);
void User_VS_Computer_game(int n);
void Multiplayer_game(int n);

#endif

