#include <stdio.h>
#include "fundamentals.h"
#define _CRT_DEFINE_NO_WARNINGS
#define BUFFER_SIZE 80
#define NUM_INPUT_SIZE 10

/* Version 1 */

void fundamentals() {
	printf("*** start of Indexing Strings Demo ***\n");

	char buffer1[BUFFER_SIZE];

	char numInput[NUM_INPUT_SIZE];
	size_t position;
	do {
		//tells the user to enter a non-empty string and type q if they want to exit the program
		printf("Type not empty string (q to quit):\n");
		fgets(buffer1, BUFFER_SIZE, stdin);

		// adds the  null terminator at the end of the string
		buffer1[strlen(buffer1) - 1] = '\0';

		//to check if user wants to exit hte program or not if no then continue
		if (buffer1[0] != 'q') {

			// getting user input to extract the character from string
			printf("Type the character position within the string:\n");
			fgets(numInput, NUM_INPUT_SIZE, stdin);
			numInput[strlen(numInput) - 1] = '\0';
			position = atoi(numInput);

			// checks if the user demanded posistion lies between range or not and prinnts error if no.
			if (position >= strlen(buffer1)) {
				position = strlen(buffer1) - 1;
				printf("Too big... Position reduced to max. available\n");
			}
			//printing output
			printf("The character found at position %zu is \'%c\'\n", position, buffer1[position]);
		}
	} while (buffer1[0] != 'q');

     /* Version 2 */

	printf("*** Start of Measuring Strings Demo ***\n");

	char buffer2[BUFFER_SIZE];

	do {

		printf("Type a string (q - to quit):\n");

		fgets(buffer2, BUFFER_SIZE, stdin);

		buffer2[strlen(buffer2) - 1] = '\0';

		if (strcmp(buffer2, "q") != 0)

			printf("The length of \'%s\' is %d characters\n",

				buffer2, (int)strlen(buffer2));

	} while (strcmp(buffer2, "q") != 0); printf("*** End of Measuring Strings Demo ***\n\n");
}

/* Version 3 */
//>> insert here



