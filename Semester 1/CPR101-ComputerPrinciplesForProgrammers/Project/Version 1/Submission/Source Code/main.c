// includes header to point libraries and header files used
#define CRT SECURE NO WARNINGS
#include "fundamentals.h"
#include "manipulating.h"
#include "converting.h"
#include "tokenizing.h"
int main (void)
{
    char buff [10];      // declaration and initialization of an array named buff containing char.
    do                  // beginning of a do-loop, which executes atleast once till a condition is true
    {
        printf("1 - Fundamentals \n");
        printf("2 - Manipulation\n");
        printf("3 - Converting\n");
        printf("4 - Tokenizing\n");
        printf("0 - Exit\n");
        printf ("Which module to run? \n"); 
        fgets (buff, 10, stdin);       // gets input for buff, size and stdin
        switch (buff [0])              // switch statement lets user choose from given options
        {
        case '1': fundamentals () ;    // call to function through fundamentals.h header file
            break;
        case '2': manipulating () ;    // call to function through manipulating.h header file
            break;
        case '3': converting ();      // call to function through converting.h header file
            break;
        case '4': tokenizing () ;     // call to function through tokenizing.h header file
            break;
        }
    } while (buff [0] != '0');      // when given condition is true, code exists the loop
    return 0;
}