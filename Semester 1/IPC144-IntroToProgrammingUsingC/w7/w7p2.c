#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAXIMUM_PATH 70
#define MINIMUM_PATH 10
#define MAX_NUM_LIVES 10
#define MIN_NUM_LIVES 1
#define MULTIPLE 5

struct playerInfo
{
	int num_lives;
	char character_symbol;
	int num_treasure;
	int position[MAXIMUM_PATH];
};

struct gameInfo
{
	int max_num_move;
	int path_length;
	int bombs[MAXIMUM_PATH];
	int treasure[MAXIMUM_PATH];

};

int main(void)
{
	int i, j, k;
	int max_moves_remaining, num_lives_remaining, move_position = MAXIMUM_PATH + 1;

	struct playerInfo player;
	struct gameInfo game;


	printf("================================\n");
	printf("         Treasure Hunt!\n");
	printf("================================\n");
	printf("\n");

	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf("%c", &player.character_symbol);

	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &player.num_lives);

		if (player.num_lives < MIN_NUM_LIVES || player.num_lives > MAX_NUM_LIVES)
		{
			printf("     Must be between 1 and 10!\n");
		}
	} while (player.num_lives < MIN_NUM_LIVES || player.num_lives > MAX_NUM_LIVES);

	printf("Player configuration set-up is complete\n");
	printf("\n");

	printf("GAME Configuration\n");
	printf("------------------\n");

	do
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &game.path_length);

		if ((game.path_length < MINIMUM_PATH || game.path_length > MAXIMUM_PATH) || (game.path_length % MULTIPLE != 0))
		{
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}
	} while ((game.path_length < MINIMUM_PATH || game.path_length > MAXIMUM_PATH) || (game.path_length % MULTIPLE != 0));


	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.max_num_move);

		if (game.max_num_move < player.num_lives || game.max_num_move >(int) (0.75 * game.path_length))
		{
			printf("    Value must be between %d and %d\n", player.num_lives, (int)(0.75 * game.path_length));
		}
	} while (game.max_num_move < player.num_lives || game.max_num_move >(int) (0.75 * game.path_length));
	printf("\n");


	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

	for (i = 0; i < game.path_length; i+=5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
	}

	printf("BOMB placement set\n");
	printf("\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

	for (i = 0; i < game.path_length; i+=5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		scanf("%d %d %d %d %d", &game.treasure[i], &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4]);
	}

	printf("TREASURE placement set\n");
	printf("\n");

	printf("GAME configuration set-up is complete...\n");
	printf("\n");


	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");

	printf("Player:\n");
	printf("   Symbol     : %c\n", player.character_symbol);
	printf("   Lives      : %d\n", player.num_lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n");
	printf("\n");

	printf("Game:\n");
	printf("   Path Length: %d\n", game.path_length);
	printf("   Bombs      : ");
	for (j = 0; j < game.path_length; j++)
	{
		printf("%d", game.bombs[j]);
	}
	printf("\n");

	printf("   Treasure   : ");
	for (k = 0; k < game.path_length; k++)
	{
		printf("%d", game.treasure[k]);
	}
	printf("\n\n");

	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");


	max_moves_remaining = game.max_num_move;
	num_lives_remaining = player.num_lives;
	player.num_treasure = 0;
	int count_char = 0;

	char current_position[MAXIMUM_PATH];
	char item[MAXIMUM_PATH];

	for (j = 0; j < game.path_length; j++)
	{
		player.position[j] = 0;
	}

	for (k = 0; k < game.path_length; k++)
	{
		item[k] = '-';
	}

	for (k = 0; k < game.path_length; k++)
	{
		current_position[k] = ' ';
	}

	do {
		
		for (k = 0; k < game.path_length; k++)
		{
			if (current_position[k] == 'V')
			{
				count_char++;
			}
		}
		if (count_char == 0)
		{
			printf("\n");
		}
		else
		{
			printf("  ");
			for (k = 0; k < game.path_length; k++)
			{
				if (current_position[k] == 'V')
				{
					printf("%c\n", current_position[k]);
					break;
				}
				else
				{
					printf("%c", current_position[k]);
				}
			}
		}

		for (k = 0; k < game.path_length; k++)
		{
			current_position[k] = ' ';
		}

		printf("  ");
		for (k = 0; k < game.path_length; k++)
		{
			printf("%c", item[k]);
		}
		printf("\n");

		printf("  ");
		for (i = 1; i <= game.path_length; i++)
		{
			if (i % 10 == 0)
			{
				printf("%d", (int)i / 10);
			}
			else
			{
				printf("|");
			}
		}
		printf("\n");


		printf("  ");
		for (i = 0; i < game.path_length; i += 10)
		{
			printf("1234567890");
		}
		printf("\n");

		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", num_lives_remaining, player.num_treasure, max_moves_remaining);
		printf("+---------------------------------------------------+\n");

		if (num_lives_remaining == 0)
		{
			break;
		}

		if (max_moves_remaining == 0)
		{
			break;
		}


		do {
			printf("Next Move [1-20]: ");
			scanf("%d", &move_position);

			if (move_position < 1 || move_position > game.path_length)
			{
				printf("  Out of Range!!!\n");
			}

		} while (move_position < 1 || move_position > game.path_length);
		printf("\n");

		if (player.position[move_position - 1] == 1)
		{
			printf("===============> Dope! You've been here before!\n\n");
			current_position[move_position - 1] = 'V';
			max_moves_remaining++;
		}

		else if (game.bombs[move_position - 1] == 1 && game.treasure[move_position - 1] == 1)
		{
			printf("===============> [&] !!! BOOOOOM !!! [&]\n");
			printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
			item[move_position - 1] = '&';
			current_position[move_position - 1] = 'V';
			num_lives_remaining--;
			player.num_treasure++;
		}

		else if (game.bombs[move_position - 1] == 1)
		{
			printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
			item[move_position - 1] = '!';
			current_position[move_position - 1] = 'V';
			num_lives_remaining--;
		}

		else if (game.treasure[move_position - 1] == 1)
		{
			printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
			item[move_position - 1] = '$';
			current_position[move_position - 1] = 'V';
			player.num_treasure++;
		}

		else
		{
			printf("===============> [.] ...Nothing found here... [.]\n\n");
			item[move_position - 1] = '.';
			current_position[move_position - 1] = 'V';
		}

		player.position[move_position - 1] = 1;
		max_moves_remaining--;

		if (num_lives_remaining == 0)
		{
			printf("No more LIVES remaining!\n\n");
		}
		if (max_moves_remaining == 0)
		{
			printf("No more MOVES remaining!\n\n");
		}

	} while (max_moves_remaining >= 0 && num_lives_remaining >= 0);

	printf("\n");

	printf("##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n");
	printf("\n");

	printf("You should play again and try to beat your score!\n");
	printf("\n");

	return 0;
}
