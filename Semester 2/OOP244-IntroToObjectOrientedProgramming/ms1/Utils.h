// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#ifndef _SDDS_UTILS_H
#define _SDDS_UTILIS_H
#include <iostream>
#include <cstring>
namespace sdds {
    // Testing date values for application testing and debugging
    // these values must not change at submission time.
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;
    class Utils {
        bool m_testMode = false;
    public:
        // this function will be used to get the current system date or the test date if m_testMode is true
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        // this function will return the number of days in a month based on the year
        // 1<=mon<=12  year: four digit number (example: 2023)
        int daysOfMon(int mon, int year)const;
        // Puts the system date in test mode, where getSystemDate() function will return 2023, 12, 09
        // or whatever the three constant test dates are set to
        void testMode(bool testmode = true);
        //Safely allocates memory in the destination argument and copies the source into it
        void alocpy(char*& destination, const char* source);
        //Prompts the user to enter a valid integer
        int getint(const char* prompt = nullptr);
        //Prompts the user to enter a value that is within the max and minimum range
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);

    };
    extern Utils ut;  // provides global access to the ut instance in the Utils.cpp file
}
#endif
