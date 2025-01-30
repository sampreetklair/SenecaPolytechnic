#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{

    char loop_type;
    int number, i;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    printf("\n");

    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loop_type, &number);

        switch (loop_type)
        {
        case 'D':
            if (number >= 3 && number <= 20)
            {
                printf("DO-WHILE: ");
                i = 0;
                do
                {
                    printf("%c", loop_type);
                    i++;
                } while (i < number);
                printf("\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
            break;
        case 'W':
            if (number >= 3 && number <= 20)
            {
                printf("WHILE   : ");
                i = 0;
                while (i < number)
                {
                    printf("%c", loop_type);
                    i++;
                }
                printf("\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }

            break;
        case 'F':
            if (number >= 3 && number <= 20)
            {
                printf("FOR     : ");
                i = 0;
                for (i = 0; i < number; i++)
                {
                    printf("%c", loop_type);
                }
                printf("\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }

            break;
        case 'Q':
        if (number !=0){
            printf("ERROR: To quit, the number of iterations should be 0!\n");
            break;
        }
            break;
        default:
            printf("ERROR: Invalid entered value(s)!\n");
        } printf("\n");
    } while (!(loop_type == 'Q' && number == 0));
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    return 0;
}