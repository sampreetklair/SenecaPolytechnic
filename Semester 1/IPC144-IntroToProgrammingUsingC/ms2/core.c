/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Sampreet Klair
Student ID#: 145031225
Email      : skalir2@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <string.h>

#include "core.h"

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// Prompts the user until a whole value entered, returns the valid entered value
int inputInt(void)
{
    char newline = 'x';
    int value;

    while (newline != '\n')
    {
        scanf("%d%c", &value, &newline);
        if (newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }

    return value;
}

// Prompts the user until a positive value entered, returns valid entered value
int inputIntPositive(void)
{
    int value = 0;

    while (value <= 0)
    {
        scanf("%d", &value);
        if (value <= 0)
        {
            clearInputBuffer();
            printf("ERROR! Value must be > 0: ");
        }
    }

    return value;
}

// Receives a minimum and maximum value, and prompts the user until value within that range received, returns valid entered value
int inputIntRange(int min, int max)
{
    char newline = 'x';
    int value = 0;

    while (!(value >= min && value <= max) || newline != '\n')
    {
        scanf("%d%c", &value, &newline);
        if (!(value >= min && value <= max))
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
        }
        else if (newline != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }

    return value;
}

// Receives a string, prompts the user for a character until the entered character is equals to any member of the received string, returns the valid entered character
char inputCharOption(const char validChars[])
{
    char result;
    int i, length, keepgoing = 0;
    length = strlen(validChars);
    //for (length = 0; validChars[length] != '\0'; ++length);

    while (keepgoing == 0)
    {
        scanf(" %c", &result);

        for (i = 0; i < length; i++)
        {
            if (result == validChars[i])
            {
                keepgoing = 1;
            }
        }
        if (keepgoing == 0)
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", validChars);
        }
    }
    return result;
}

// Receives a string and minimum and maximum value, prompts the user for a string until entered string length is within that range received, returns the valid entered string by copying to the parameter
void inputCString(char* receivedStr, int min, int max)
{
    int length = 0, keepgoing1 = 0;
    char string[100] = { '\0' };

    while (keepgoing1 == 0)
    {

        scanf("%[^\n]", string);

        length = strlen(string);

        if (min == max)
        {
            if (length != max)
            {
                printf("ERROR: String length must be exactly %d chars: ", max);
            }
            else
            {
                keepgoing1 = 1;
            }

        }
        else if (length > max)
        {
            printf("ERROR: String length must be no more than %d chars: ", max);
        }
        else if (length < min)
        {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
        }
        else
        {
            keepgoing1 = 1;
        }
        clearInputBuffer();
    }
    strcpy(receivedStr, string);
}

// Receives a string, displays it if the string length is equals to 10 and made out of numbers or displays the empty format if the conditions doesn't met
void displayFormattedPhone(const char* str)
{
    int i, length, achar = 0;
    if (str != NULL)
    {
        //for (length = 0; str[length] != '\0'; ++length);
        length = strlen(str);

        for (i = 0; i < length; i++)
        {
            if (str[i] != '\0')
            {
                if ((str[i] != '0') && (str[i] != '1') && (str[i] != '2') && (str[i] != '3') && (str[i] != '4') &&
                    (str[i] != '5') && (str[i] != '6') && (str[i] != '7') && (str[i] != '8') && (str[i] != '9'))
                {
                    achar = 1;
                }
            }
        }

        if ((length != 10) || (achar == 1))
        {
            printf("(___)___-____");
        }
        else
        {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", str[0], str[1], str[2], str[3], str[4], str[5],
                str[6], str[7], str[8], str[9]);
        }
    }
    else
    {
        printf("(___)___-____");
    }
}
