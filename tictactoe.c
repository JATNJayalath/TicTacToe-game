#include "tictactoe.h"

//Initialize the board
char** initialize_board(int n) {
	int i,j;
	char** board = (char**)malloc(n * sizeof(char*));
	for(i=0; i<n; i++) {
		board[i] = (char*)malloc(n * sizeof(char));
		for(j=0; j<n; j++) {
			board[i][j] = ' ';
		}
	}
	return board;
}

//Display the board
void display_board(char** board, int n) {
	int column, row;
	printf("   ");
    	for(column=0; column<n; column++){
        	printf("  %d ", column);
    	}
    	printf("\n");
    	for(row=0; row<n; row++) {
        	printf(" %d ", row);
        	for(column=0; column<n; column++){
            		if(board[row][column] == ' '){
                		printf("|---");
            		}
            		else{
                		printf("| %c ",board[row][column]);
            		}
        	}
        	printf("|\n");
   	 }
    	printf("\n");
}

//Get User Input
void get_user_input(int *row, int *column, int n) {
	while(1) {
		printf("Enter your move(row column): ");
		if(scanf("%d %d", row, column) == 2 && *row>=0 && *row<n && *column>=0 && *column<n) {
			while(getchar() != '\n');
			break;
		}
		printf("Invalid Input. Please enter numbers between 0 and %d\n", n-1);
		while(getchar() != '\n');
	}

}

//Checking  validate moves
int is_valid_move(char** board, int n, int row, int column) {
	if(row<0 || row>=n || column<0 || column>=n) {
		return 0;
	}
	if(board[row][column] != ' ') {
		return 0;
	}
	return 1;
}

//Checking win conditions
int check_win(char** board, int n, char symbol) {
	int i, j, win;
	//Check rows
	for(i=0; i<n; i++) {
		win = 1;
		for(j=0; j<n; j++) {
			if(board[i][j] != symbol) {
				win = 0;
				break;
			}
		}
		if(win) return 1;
	}
	//Check columns
	for(j=0; j<n; j++) {
                win = 1;
                for(i=0; i<n; i++) {
                        if(board[i][j] != symbol) {
                                win = 0;
                                break;
                        }
                }
                if(win) return 1;
        }
	//Chech diagonal - top right to bottom left
	win=1;
	for(i=0; i<n; i++) {
		if(board[i][n-1-i] != symbol) {
			win = 0;
			break;
		}
	}
	if(win) return 1;
	//Check diagonal - top left to bottom right
	win = 1;
	for(i=0; i<n; i++) {
		if(board[i][i] != symbol) {
			win = 0;
			break;
		}
	}
	return win;
}

//Checking draw condition
int check_draw(char** board, int n) {
	int i, j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

//Log game state to file
void log_file(FILE* logFile, char** board, int n) {
	int i, j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			fprintf(logFile, "%c ", board[i][j]);
		}
		fprintf(logFile, "\n");
	}
	fprintf(logFile, "----------\n");
}

//Generate Computer moves
void computer_move(char** board, int n, int *row, int *column) {
	do {
		*row = rand() % n;
		*column = rand() % n;
	}while(!is_valid_move(board, n, *row, *column));
}

