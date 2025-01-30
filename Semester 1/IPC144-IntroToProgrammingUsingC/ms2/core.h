// SAFE-GUARD:
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
// Copy your work done from Milestone #1 (core.h) into this file
//
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Prompts the user until a whole value entered, returns the valid entered value
int inputInt(void);

// Prompts the user until a positive value entered, returns valid entered value
int inputIntPositive(void);

// Receives a minimum and maximum value, and prompts the user until value within that range received, returns valid entered value
int inputIntRange(int min, int max);

// Receives a string, prompts the user for a character until the entered character is equals to any member of the received string, returns the valid entered character
char inputCharOption(const char validChars[]);

// Receives a string and minimum and maximum value, prompts the user for a string until entered string length is within that range received, returns the valid entered string by copying to the parameter
void inputCString(char* receivedStr, int min, int max);

// Receives a string, displays it if the string length is equals to 10 and made out of numbers or displays the empty format if the conditions doesn't met
void displayFormattedPhone(const char* str);


// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
