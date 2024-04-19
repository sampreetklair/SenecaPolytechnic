#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 80 
#include "manipulating.h"

void manipulating(void)
{
	/*
   Input: Get two sting inputs from the user
   Process: Concatenates the two string without any whitespaces in between
   Output: Displays the concatenated string to user.
*/
    /* Version 1 */
	printf("*** start of Concatenating Strings Demo ***\n");
	// Declaring two string variables
	char string1[BUFFER_SIZE];
	char string2[BUFFER_SIZE];
	/*
input loop:
take two string inputs from the user until he enters 'q' to quit the input cycle.
    */
	do
	{
		string2[BUFFER_SIZE];
		printf("Type the 1st string (q - to quit) :\n");// input for first string
		fgets(string1, BUFFER_SIZE, stdin);   // stores the user input to string1
		string1[strlen(string1) - 1] = '\0';    // sets null terminator
		/*
	if condition to check if the user does not wants to exit,
	then proceed with concatenation
	*/

		if ((strcmp(string1, "q") != 0))
		{
			printf("Type the 2nd string:\n"); // input for second string
			fgets(string2, BUFFER_SIZE, stdin);  // stores the user input to string2
			string2[strlen(string2) - 1] = '\0';  // sets null terminator
			strcat(string1, string2);   // concatenating string1 and string2 using strcat
			printf("Concatenated string is \'%s\' \n", string1);  // displaying output as concatenated string
		}
	} while (strcmp(string1, "q") != 0);  // iterating until user enter 'q' to quit input cycle
	printf("*** End of Concatenating strings Demo ***\n\n");   // output after entering q

	/* Version 2 */
	/* V2 */ 
	/*
	Function to compare strings.
	Input: Get two string inputs from the user.
	Process: Compares the two strings and displays the result.
	Output: Displays the comparison result to the user.
	*/
	printf("*** start of Comparing strings Demo ***\n");
	char compare1[BUFFER_SIZE];  // Declare variables for string comparison
	char compare2[BUFFER_SIZE];
	int result;
	// Loop to compare strings until user enters 'q'
	do
	{
		printf("Type the 1st string to compare (q - to quit) : \n");
		fgets(compare1, BUFFER_SIZE, stdin);
		compare1[strlen(compare1) - 1] = '\0'; // Remove newline character
		if (strcmp(compare1, "q") != 0)
		{
			printf("Type the 2nd string to compare: \n");
			fgets(compare2, BUFFER_SIZE, stdin);
			compare2[strlen(compare2) - 1] = '\0'; // Remove newline character
			// Compare the two strings
			result = strcmp(compare1, compare2);
			// Display the comparison result
			if (result < 0)
				printf("\'%s\' string is less than \'%s\'\n", compare1, compare2);
			else if (result == 0)
				printf("\'%s\' string is equal to \'%s\'\n", compare1, compare2);
			else printf("\'%s\' string is greater than \'%s\'\n", compare1, compare2);

		}
	} while (strcmp(compare1, "q") != 0);
	// End of Comparing Strings Demo
			printf("** End of Comparing Strings Demo **\n\n");
}
