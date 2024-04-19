/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Sampreet Klair
Student ID#: 145031225
Email      : sklair2@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatoes, cabbages;
    int num_apples, num_oranges, num_pears, num_tomatoes, num_cabbages;
    int count = 0;
    int shopping_done;

    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        do
        {
            printf("How many APPLES do you need? : ");
            scanf(" %d", &apples);
            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apples < 0);
        printf("\n");

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf(" %d", &oranges);
            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (oranges < 0);
        printf("\n");

        do
        {
            printf("How many PEARS do you need? : ");
            scanf(" %d", &pears);
            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pears < 0);
        printf("\n");

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf(" %d", &tomatoes);
            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatoes < 0);
        printf("\n");

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf(" %d", &cabbages);
            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbages < 0);

        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");

        if (apples > 0)
        {
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf(" %d", &num_apples);

                if (num_apples <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (num_apples > apples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples - count);
                }

                else if (num_apples > 0 && num_apples <= apples)
                {
                    count += num_apples;
                    if (count != apples)
                    {
                        printf("Looks like we still need some APPLES...\n");
                    }
                    else if (count == apples)
                    {
                        printf("Great, that's the apples done!\n");
                    }
                }
            }

            while (count != apples);
            printf("\n");
        }
            
        count = 0;

        if (oranges > 0)
        {
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf(" %d", &num_oranges);

                if (num_oranges <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (num_oranges > oranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges - count);
                }

                else if (num_oranges > 0 && num_oranges <= oranges)
                {
                    count += num_oranges;
                    if (count != oranges)
                    {
                        printf("Looks like we still need some ORANGES...\n");
                    }
                    else if (count == oranges)
                    {
                        printf("Great, that's the oranges done!\n");
                    }
                }

            } while (count != oranges);
            printf("\n");
        }

        count = 0;

        if (pears > 0)
        {
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf(" %d", &num_pears);

                if (num_pears <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (num_pears > pears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears - count);
                }

                else if (num_pears > 0 && num_pears <= pears)
                {
                    count += num_pears;
                    if (count != pears)
                    {
                        printf("Looks like we still need some PEARS...\n");
                    }
                    else if (count == pears)
                    {
                        printf("Great, that's the pears done!\n");
                    }
                }

            } while (count != pears);
            printf("\n");
        }
            
            count = 0;

        if (tomatoes > 0)
        {

            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf(" %d", &num_tomatoes);

                if (num_tomatoes <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (num_tomatoes > tomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes - count);
                }

                else if (num_tomatoes > 0 && num_tomatoes <= tomatoes)
                {
                    count += num_tomatoes;
                    if (count != tomatoes)
                    {
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                    else if (count == tomatoes)
                    {
                        printf("Great, that's the tomatoes done!\n");
                    }
                }

            } while (count != tomatoes);
            printf("\n");
        }

        count = 0;

        if (cabbages > 0)
        {
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf(" %d", &num_cabbages);

                if (num_cabbages <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (num_cabbages > cabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages - count);
                }

                else if (num_cabbages > 0 && num_cabbages <= cabbages)
                {
                    count += num_cabbages;
                    if (count != cabbages)
                    {
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                    else if (count == cabbages)
                    {
                        printf("Great, that's the cabbages done!\n");
                    }
                }

            } while (count != cabbages);
            printf("\n");
        }    
    count = 0;
    printf("All the items are picked!\n");
    printf("\n");
    printf("Do another shopping? (0=NO): ");
    scanf(" %d", &shopping_done);
    printf("\n");
    if (shopping_done == 0){
        printf("Your tasks are done for today - enjoy your free time!\n\n");
        break;
    }
    }
    while (1);

    return 0;
}