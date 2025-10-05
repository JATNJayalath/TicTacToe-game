#include "tictactoe.h"

int main() {
	int n;
	int game_mode;

	printf("*** Tic Tac Toe Game ***\n");

	printf("Enter board size, n (3 <= n <= 10): ");
	scanf("%d", &n);
	if(n < 3 || n > 10) {
		printf("Invalid board size. Please enter a value between 3 and 10.\n");
		return 1;
	}

	printf("\n* Game Modes *");
	printf("\n1. Two Players (User VS User)");
	printf("\n2. User VS Computer");
	printf("\n3. Multiplayer ");
	printf("\nSelect game mode: ");
	scanf("%d", &game_mode);

	switch(game_mode) {
		case 1: Two_player_game(n);
			break;
		case 2: User_VS_Computer_game(n);
			break;
		case 3: Multiplayer_game(n);
			break;
		default:
			printf("Invalid Game Mode. Please try again");
	}
	return 0;
}


//Create Game Modes

//1. Two Player Mode

void Two_player_game(int n) {
	char** board = initialize_board(n);
    	FILE* logFile = fopen("game.txt", "w");
	if(!logFile) {
		printf("Couldn't open game.txt file\n");
		return;
	}

    	char symbol[2] = {'X', 'O'};
    	int turn = 0; 
    	int row, column;
    	int game_over = 0;

    	while(!game_over) {
        	display_board(board, n);
        	printf("Player %c,", symbol[turn]);
        	get_user_input(&row, &column, n);

        	if(!is_valid_move(board, n, row, column)) {
            		printf("Invalid move! Try again.\n");
            		continue;
        	}
        	board[row][column] = symbol[turn];
        	log_file(logFile, board, n);

        	if(check_win(board, n, symbol[turn])) {
            		display_board(board, n);
            		printf("Player %c wins\n", symbol[turn]);
            		game_over = 1;
        	}
        	else if(check_draw(board, n)) {
            		display_board(board, n);
            		printf("It's a draw\n");
            		game_over = 1;
        	}
        	else {
            		turn = 1-turn;
        	}
    	}

    	fclose(logFile);
    	for(int i=0; i<n; i++) {        
        	free(board[i]);
    	}
    	free(board);
}

//2. User VS Computer Mode

void User_VS_Computer_game(int n) {
	char** board = initialize_board(n);
	FILE* logFile = fopen("game.txt", "w");
	if(!logFile) {
		printf("Couldn't open game.txt file\n");
		return;
	}

	char symbol[2] = {'X', 'O'};
	int turn = 0;
	int row, column;
	int game_over = 0;

	while(!game_over) {
		display_board(board, n);

		if(turn == 0) {
			printf("Your turn:\n");
			get_user_input(&row, &column, n);

			if(!is_valid_move(board, n, row, column)) {
				printf("Invalid move! Try again.\n");
				continue;
			}
		}
		else {
			computer_move(board, n, &row, &column);
			printf("Computer plays at(row column): %d %d\n", row, column);
		}

		board[row][column] = symbol[turn];
		log_file(logFile, board, n);

		if(check_win(board, n, symbol[turn])) {
			display_board(board, n);
			if(turn == 0) {
				printf("You win\n");
			}
			else {
				printf("Computer wins\n");
			}
			game_over = 1;
		}
		else if(check_draw(board, n)) {
			display_board(board, n);
			printf("It's a draw\n");
			game_over = 1;
		}
		else {
			turn = 1 - turn;
		}
	}fclose(logFile);
	for(int i=0; i<n; i++) {
		free(board[i]);
	}
	free(board);

}

//3. Multiplayer Mode

void Multiplayer_game(int n) {
	char** board = initialize_board(n);
	FILE* logFile = fopen("game.txt", "w");
	if(!logFile) {
		printf("Couldn't open game.txt file\n");
		return;
	}

	char symbol[3] = {'X', 'O', 'Z'};
	int human_or_computer[3] = {0, 0, 0};      //0-human, 1-computer
	int turn = 0;
	int row, column;
	int game_over = 0;

	//Player 1 must be human and Ask for player 2 and 3 whether they are human or computer moves
	human_or_computer[0] = 0;

	printf("Is player 2 a human or computer (0-human, 1-computer): ");
    	scanf("%d", &human_or_computer[1]);
    	printf("Is player 3 a human or computer (0-human, 1-computer): ");
    	scanf("%d", &human_or_computer[2]);

	while(!game_over) {
		display_board(board, n);

		//human move
		if(human_or_computer[turn] == 0) {
			printf("Player %c,", symbol[turn]);
			get_user_input(&row, &column, n);

			if(!is_valid_move(board, n, row, column)) {
				printf("Invalid move! Try again.\n");
				continue;
			}
		}
		//Computer move
		else {
			computer_move(board, n, &row, &column);
			printf("Computer %c playes at (row column): %d %d\n", symbol[turn], row, column);
		}
		board[row][column] = symbol[turn];
		log_file(logFile, board, n);

		if(check_win(board, n, symbol[turn])) {
			display_board(board, n);
			printf("Player %c wins\n", symbol[turn]);
			game_over = 1;
		}
		else if(check_draw(board, n)){
			display_board(board, n);
			printf("It's a draw\n");
			game_over = 1;
		}
		else {
			turn = (turn+1)%3;
		}
	}
	fclose(logFile);
	for(int i=0; i<n; i++) {
		free(board[i]);
	}
	free(board);
		
}


