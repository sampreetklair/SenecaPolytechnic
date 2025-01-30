#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int year, month, valid;

    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        valid = 1;
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf(" %d %d", &year, &month);
        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            valid = 0;
        }
        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
            valid = 0;
        }

    } while (!valid);

            printf("\n");
            printf("*** Log date set! ***\n");
            printf("\n");

            switch (month)
            {
            case 1:
                printf("Log starting date: %d-JAN-%02d\n", year, 1);
                break;

            case 2:
                printf("Log starting date: %d-FEB-%02d\n", year, 1);
                break;

            case 3:
                printf("Log starting date: %d-MAR-%02d\n", year, 1);
                break;

            case 4:
                printf("Log starting date: %d-APR-%02d\n", year, 1);
                break;

            case 5:
                printf("Log starting date: %d-MAY-%02d\n", year, 1);
                break;

            case 6:
                printf("Log starting date: %d-JUN-%02d\n", year, 1);
                break;

            case 7:
                printf("Log starting date: %d-JUL-%02d\n", year, 1);
                break;

            case 8:
                printf("Log starting date: %d-AUG-%02d\n", year, 1);
                break;

            case 9:
                printf("Log starting date: %d-SEP-%02d\n", year, 1);
                break;

            case 10:
                printf("Log starting date: %d-OCT-%02d\n", year, 1);
                break;

            case 11:
                printf("Log starting date: %d-NOV-%02d\n", year, 1);
                break;

            case 12:
                printf("Log starting date: %d-DEC-%02d\n", year, 1);
                break;

            default:
                break;
            }    

    return 0;
}