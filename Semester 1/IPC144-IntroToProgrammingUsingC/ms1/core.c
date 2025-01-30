// #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "core.h"

int lowerbound;
int upperbound;

// As demonstringated in the course notes:
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

// Prompting the user to enter inputs.
int inputInt(void){
    char newLine = 'x';
    int value;

    while (newLine != '\n'){
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        
    }
    return value;
}

// Prompting the user to enter input.
int inputIntPositive(){
    int value;

    do
    {
        value = inputInt();
        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
        
    } while (value <= 0);
    
    return value;
}

// Verifying range of input
int inputIntRange(lowerbound, upperbound){
    int value;

    do
    {
        value = inputInt();
        if (value < lowerbound || value > upperbound)
        {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
        
    } while (value < lowerbound || value > upperbound);
    
    return value;
     

}

char inputCharOption(char string[]) {
    int i, count = 0;
    char input;

    do {
        scanf(" %c", &input);

        for (i = 0; string[i] != '\0'; i++) {
            if (input == string[i]) {
                count++;
            }
        }

        if (count == 0) {
            printf("ERROR: Character must be one of [%s]: ", string);
        }
    } while (count == 0);

    clearInputBuffer();
    return input;
}

void inputCString(char* string, int min_char, int max_char) {
    int valid = 1;
    char ch = 'a';

    while (valid) {
        int len = 0;
        while (ch != '\n' && len <= max_char) {
            ch = getchar();
            string[len] = ch;
            len++;
        };

        if (ch == '\n' && len <= (max_char + 1)) {
            len--;
            string[len] = '\0';
        }
        else {
            string[max_char] = '\0';
            clearInputBuffer();
        }

        if (min_char == max_char && len != min_char) {
            printf("ERROR: String length must be exactly %d chars: ", min_char);
            ch = 'a';
        }
        else if (len < min_char || len > max_char) {
            if (len > max_char) {
                printf("ERROR: String length must be no more than %d chars: ", max_char);
                ch = 'a';
            }
            else if (len < min_char) {
                printf("ERROR: String length must be between %d and %d chars: ", min_char, max_char);
                ch = 'a';
            }
        }
        else {
            valid = 0;
        }
    }
}

void displayFormattedPhone(const char* string) {

int i, count=0, digits =0, mobile_num;
if (string == NULL)
{
    printf("(___)___-____");    
}
else{
    while (string[count] != '\0'){
        mobile_num = string[count] - '0';
        if(mobile_num >=0 && mobile_num <=9){
            digits++;
        }
        count++;
    }

    if (digits == 10)
    {
        printf("(");
        for ( i = 0; string[i] != '\0'; i++)
        {
            printf("%c", string[i]);

            if (i == 2)
            {
                printf(")");
            }
            else if (i == 5){
                printf("-");
            }
            
        }
        
    }
    
    else
    printf("(___)___-____");
    
}
}