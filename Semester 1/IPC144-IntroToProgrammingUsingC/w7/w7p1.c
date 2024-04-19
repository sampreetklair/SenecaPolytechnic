/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Sampreet Klair
Student ID#: 145031225
Email      : sklair2@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAXIMUM_PATH 70
#define MINIMUM_PATH 10
#define MAX_NUM_LIVES 10
#define MIN_NUM_LIVES 1

struct PlayerInfo
{
    int num_lives;
    char character_symbol;
    int num_treasure;
    int position[MAXIMUM_PATH];
};

struct GameInfo
{
    int max_num_move;
    int path_length;
    int bombs[MAXIMUM_PATH];
    int treasure[MAXIMUM_PATH];
};

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game;


    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.character_symbol);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.num_lives);
        if (player.num_lives < MIN_NUM_LIVES || player.num_lives > MAX_NUM_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }
        
    } while (player.num_lives < MIN_NUM_LIVES || player.num_lives > MAX_NUM_LIVES);
    printf("Player configuration set-up is complete\n\n");

    //Game Configuration
    printf("GAME Configuration\n");
    printf("------------------\n");
        
    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.path_length);
        if (game.path_length < MINIMUM_PATH || game.path_length > MAXIMUM_PATH || game.path_length % 5 != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
        
    } while (game.path_length < MINIMUM_PATH || game.path_length > MAXIMUM_PATH || game.path_length % 5 != 0);

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.max_num_move);
        if (game.max_num_move < player.num_lives || game.max_num_move > .75 * game.path_length)
        {
            printf("    Value must be between %d and %d\n", player.num_lives, (int)(.75 * game.path_length));
        }
    
    } while (game.max_num_move < player.num_lives || game.max_num_move > .75 * game.path_length);
    
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    int i;
    for (i = 0; i < game.path_length; i+=5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        int j;
        for (j = i; j < i + 5; j++)
        {
            scanf("%d", &game.bombs[j]);
        }
        
    }

    printf("BOMB placement set\n");
    
    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    for (i = 0; i < game.path_length; i+=5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        int j;
        for (j = i; j < i + 5; j++)
        {
            scanf("%d", &game.treasure[j]);
        }
    }
    
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.character_symbol);
    printf("   Lives      : %d\n", player.num_lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: 35\n");
    printf("   Bombs      : 00001100111011101000101000001010101\n");
    printf("   Treasure   : 00100111011101001000110101010001111\n");
    printf("\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    

    return 0;
}
