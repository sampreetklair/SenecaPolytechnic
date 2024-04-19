/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3
#define MIN_RATE 0.0
#define MAX_RATE 5.0

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int year, month, valid, i;
    double mRate, eRate, countmRate, counteRate, total_avg;

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
    
    switch (month)
    {
    case 1:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-JAN-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);

        }
        break;

    case 2:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-FEB-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }
                

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate +=eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);
            
        }
        break;

    case 3:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-MAR-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);
        }
        break;

    case 4:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-APR-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);
        }
        break;

    case 5:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-MAY-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);
        }
        break;

    case 6:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-JUN-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);
        }
        break;

    case 7:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-JUL-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);
        }
        break;

    case 8:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-AUG-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);
        }
        break;

    case 9:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-SEP-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);
        }
        break;

    case 10:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-OCT-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);
        }
        break;

    case 11:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-NOV-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }


            } while (eRate < MIN_RATE || eRate > MAX_RATE);
        }
        break;

    case 12:
        for (i = 1; i <= LOG_DAYS; i++)
        {
            printf("\n%d-DEC-%02d\n", year, i);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &mRate);
                if (mRate < MIN_RATE || mRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    countmRate += mRate;
                }

            } while (mRate < MIN_RATE || mRate > MAX_RATE);
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eRate);
                if (eRate < MIN_RATE || eRate > MAX_RATE)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
                else{
                    counteRate += eRate;
                }

            } while (eRate < MIN_RATE || eRate > MAX_RATE);
        }
        break;

    default:
        break;
    }
    printf("\n");
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", countmRate);
    printf("Evening total rating:  %.3lf\n", counteRate);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", countmRate + counteRate);
    printf("\n");
    printf("Average morning rating:  %.1lf\n", countmRate/LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", counteRate/LOG_DAYS);
    printf("----------------------------\n");
    total_avg = (countmRate/LOG_DAYS+counteRate/LOG_DAYS)/2 + 0.05;
    printf("Average overall rating:  %.1lf\n\n", total_avg);

    return 0;
}