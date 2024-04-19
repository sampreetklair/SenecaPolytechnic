// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"
using namespace std;
namespace sdds {
    // The ut object of type Utils that is accessible to any file including "Utils.h" to call the Utils
    // methods
    Utils ut;
    // Puts the system date in test mode, where getSystemDate() function will return 2023, 12, 09
    // or whatever the three constant test dates are set to
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    // this function will be used to get the current system date or the test date if m_testMode is true
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    // this function will return the number of days in a month based on the year
    // 1<=mon<=12  year: four digit number (example: 2023)
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    //Safely allocates memory in the destination argument and copies the source into it
    void Utils::alocpy(char*& destination, const char* source)
    {
        delete[] destination;
        destination = nullptr;
        if (source != nullptr)
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }
    //Prompts the user to enter a valid integer
    int Utils::getint(const char* prompt)
    {
        int promptValue{};
        if (prompt != nullptr)
        {
            cout << prompt;
            bool validity = true;
            while (validity)
            {
                cin >> promptValue;
                if (cin.fail())
                {
                    validity = false;
                    cout << "Invalid Integer, retry: ";
                }

            }

        }
        return promptValue;
    }
    //Prompts the user to enter a value that is within the max and minimum range
    int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    {
        int inputValue;
        if (prompt != NULL)
        {
            bool validity = true;
            cout << prompt;
            while (validity)
            {
                cin >> inputValue;
                if (cin.fail() || inputValue<min || inputValue>max)
                {
                    if (errMes != nullptr)
                    {
                        cout << errMes << ", retry: ";
                    }
                    else
                    {
                        cout << "Value out of range [" << min << "<= val <= " << max << "]: ";
                    }


                }

            }
        }
        return inputValue;

    }
}