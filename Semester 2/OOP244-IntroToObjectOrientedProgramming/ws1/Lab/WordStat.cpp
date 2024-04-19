// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Date: 14th September, 2023
// Section: ZDD
// -----------------------------------------------------------

#include <iostream>
#include "Word.h"
#include "Word.h"
using namespace sdds;
using namespace std;

// Main function starting the execution of program
int main() {
   char filename[256];
   cout << "Enter the following file name" << endl
      << "> FoxInSocks.txt" << endl << "---------------------" << endl;
   programTitle();
   cout << "Enter filename: ";
   cin >> filename;
   wordStats(filename);
   return 0;
}