// CONVERTING MODULE SOURCE
#define _CRT_SECURE NO WARNINGS 
#define BUFFER_SIZE 80
#include "converting.h"

/* Version 1 */
void converting (void) {
    printf ("*** Start of Converting Strings to int Demo ***\n");
    char intString [BUFFER_SIZE];
    int intNumber;
    do {
        printf ("Type an int numeric string (g - to quit) : \n");
        fgets (intString, BUFFER_SIZE, stdin);
        intString [strlen (intString) - 1] = '\0';
        if (stremp (intString, "q" ) != 0) {
            intNumber = atoi (intString) ;
            printf ("Converted number is Sd\n", intNumber);
        }
    } while (stremp (intString, "q") != 0);
    print ("*** End of Converting Strings to int Demo ***\n\n");
}


/* Version 2 */
// >> insert here


/* Version 3 */
// >> insert here



