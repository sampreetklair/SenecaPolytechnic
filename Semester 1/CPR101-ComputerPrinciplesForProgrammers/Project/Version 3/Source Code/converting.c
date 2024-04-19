// includes header to point libraries, header file and macro used
#define _CRT_SECURE NO WARNINGS
#define BUFFER_SIZE 80
#include "converting.h"

void converting(void)
{
    /* Version 1 */
    printf("*** Start of Converting Strings to int Demo ***\n");
    char intString[BUFFER_SIZE];                                    // an array named intString is created of char type and of size = BUFFER_SIZE
    int intNumber;                                                  // a variable named intNumber is declared of integer type
    do
    {                                                               // beginning of a do-loop, which executes atleast once till a condition is true
        printf("Type an int numeric string (q - to quit) : \n");
        fgets(intString, BUFFER_SIZE, stdin);                       // gets input for intString, BUFFER_SIZE and stdin
        intString[strlen(intString) - 1] = '\0';                    // declares the last variable of intString equal to null terminator which makes this array a string
        if (strcmp(intString, "q") != 0)                            // executes the next codeblock if input is not "q"
        {                                                  
            intNumber = atoi(intString);                            // use of conversion function
            printf("Converted number is %d\n", intNumber);          // print the converted value
        }
    } while (strcmp(intString, "q") != 0);                          // when given condition is true, code exists the loop
    printf("*** End of Converting Strings to int Demo ***\n\n");

    /* Version 2 */
    printf("*** Start of Converting Strings to double Demo ***\n");
    char doubleString[BUFFER_SIZE];                                 // an array named doubleString is created of char type and of size = BUFFER_SIZE
    double doubleNumber;                                            // a variable named doubleNumber is declared of double type
    
    do
    {                                                               // beginning of a do-loop, which executes atleast once till a condition is true
        printf("Type the double numeric string (q - to quit):\n");
        fgets(doubleString, BUFFER_SIZE, stdin);                    // gets input for doubleString, BUFFER_SIZE and stdin
        doubleString[strlen(doubleString) - 1] = '\0';              // declares the last variable of doubleString equal to null terminator which makes this array a string
        if ((strcmp(doubleString, "q") != 0))                       // executes the next codeblock if input is not "q"
        {             
            doubleNumber = atof(doubleString);                      // use of conversion function
            printf("Converted number is %f\n", doubleNumber);       // print the converted value
        }
        
    } while (strcmp (doubleString, "q") != 0);                      // when given condition is true, code exists the loop
    printf ("*** End of Converting Strings to double Demo ***\n \n");

    /* Version 3 */
    printf ("*** Start of Converting Strings to long Demo ***\n");
    char longString [BUFFER_SIZE];                                 // an array named longString is created of char type and of size = BUFFER_SIZE
    long longNumber;                                               // a variable named longNumber is declared of long type
    do
    {                                                              // beginning of a do-loop, which executes atleast once till a condition is true
        printf ("Type the long numeric string (q - to quit): \n"); 
        fgets (longString, BUFFER_SIZE, stdin);                    // gets input for longString, BUFFER_SIZE and stdin
        longString [strlen (longString) - 1] = '\0';               // declares the last variable of longString equal to null terminator which makes this array a string
        if ((strcmp (longString, "q") != 0))                       // executes the next codeblock if input is not "q" 
        {
            longNumber = atol(longString);                        // use of conversion function
            printf ("Converted number is %ld\n", longNumber);      // print the converted value
        }
    } while (strcmp (longString, "q") != 0);                       // when given condition is true, code exists the loop
    printf ("*** End of Converting Strings to long Demo ***\n\n");
}