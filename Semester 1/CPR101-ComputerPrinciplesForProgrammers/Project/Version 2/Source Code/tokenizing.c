/*
TOKENIZING MODULE SOURCE
Author - Manav Zadafiya, mazadafiya@myseneca.ca, 3rd August, CPR101ZEE
executable files - tokenizing.c
Purpose:
input - Prompt User to enter multiple words with space
proces - tokenizing each word after space seprately
output - displays all the tokenize word
*/

// includes header files to point libraries, Macrons and structs that are used in this source code 
#include "tokenizing.h"     


void tokenizing(void)      //function defination
{
	/* Version 1 */
	printf("*** Start of Tokenizing Words Demo ***\n");
	char  words[BUFFER_SIZE];                           //declare array of size of 300(BUFFER_SIZE = 300) of character datatype
	char* nextWord = NULL;                              //nextWord will be used for user input and is the argument for tokenizing function
	int   wordsCounter;                                 //wordsCounter for counting numbers of word  

	// Loop to continuously prompt the user to enter a few words until 'q' is entered.
	do {
		printf("Type a few words separated by space (q - to quit) :\n");      // Prompting the user to enter a few words

		// Reading user input (words) and removing the newline character at the end.
		fgets(words, BUFFER_SIZE, stdin);
		words[strlen(words) - 1] = '\0';

		// Checking if the input is not equal to 'q'.
		if (strcmp(words, "q") != 0) {
			nextWord = strtok(words, " ");   // Get the first word using space as a delimiter.
			wordsCounter = 1;

			// Loop through each word in the input string.
			while (nextWord) {
				printf("word #%d is \'%s\'\n", wordsCounter++, nextWord);    // Display the word number and the word itself.
				nextWord = strtok(NULL, " ");                       // Get the next word using space as a delimiter.
			}
		}
	} while (strcmp(words, "q") != 0);                   //exit loop when user enter 'q'

	printf("*** End of Tokenizing Words�Demo�***\n\n");

	/* Version 2 */
	printf("*** Start of Tokenizing Phrases Demo ***\n");
	char    phrases[BUFFER_SIZE];                     //declare character array of size of 300(BUFFER_SIZE = 300) to store user value
	char* nextPhrase = NULL;                        //nextPhrase will be used for user input and is the argument for tokenizing function
	int     phrasesCounter;                           //phrasesCounter for counting numbers of phrases

	// Loop to continuously prompt the user to enter a few words until 'q' is entered.
	do {
		printf("Type a few phrases separated by comma(q - to quit):\n");          // Prompting the user to enter a few phrase

		// Reading user input (phrases) and removing the newline character at the end.
		fgets(phrases, BUFFER_SIZE, stdin);
		phrases[strlen(phrases) - 1] = '\0';

		// Checking if the input is not equal to 'q'.
		if ((strcmp(phrases, "q") != 0)) {
			nextPhrase = strtok(phrases, ",");                                     // Get the first phrase using comma(,) as a delimiter.
			phrasesCounter = 1;

			// Loop through each phrase in the input string.
			while (nextPhrase) {
				printf("Phrase #%d is \'%s\'\n", phrasesCounter++, nextPhrase);    // Display the phrase number and the phrase itself.
				nextPhrase = strtok(NULL, ",");                                    // Get the next phrases using comma(,) as a delimiter.
			}
		}
	} while (strcmp(phrases, "q") != 0);                                           //exit loop when user enter 'q'
	printf("*** End of Tokenizing Phrases Demo ***\n\n");
}
	/* Version 3 */