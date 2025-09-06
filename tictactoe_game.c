#include <stdio.h>
#include <stdlib.h>

//Game Modes
void Two_player_game(int n);
void User_VS_Computer_game(int n);
void Multiplayer_game(int n);

int main() {
	int n;
	int game_mode;

	printf("*** Tic Tac Toe Game ***\n");

	printf("Enter board size, n (3 <= n <= 10): ");
	scanf("%d", &n);
	if(n < 3 || n > 10) {
		printf("Invalid board size. Please enter a valid value.\n");
		return 0;
	}




	printf("\n* Game Modes *");
	printf("\n1. Two Players (User VS User)");
	printf("\n2. User VS Computer");
	printf("\n3. Multiplayer ");
	printf("\nSelect fame mode: ");
	scanf("%d", &game_mode);

	switch(game_mode) {
		case 1: Two_player_game(n);
			break;
		case 2: User_VS_Computer_game(n);
			break;
		case 3: Multiplayer_game(n);
			break;
		default:
			printf("Invalid Mode. Please try again");
	}
}

	void Two_player_game(int n) {
	}

	void User_VS_Computer_game(int n) {
	}

	void Multiplayer_game(int n) {
	}


