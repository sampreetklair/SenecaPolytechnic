// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#include <iostream>
#include <ctime>
#include "Utils.h"
#include<cstring>
#include<limits>

using namespace std;

namespace sdds 
{

    Utils ut;

    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::alocpy(char*& destination, char* source)
    {
        delete[] destination;
        destination = nullptr;
        if (source != nullptr)
        {
            destination = new char[strlen(source) + 1];
            if (destination)
            {
                strcpy(destination, source);
            }
            else {
                cout << "Utils.cpp source was invalid" << endl;
            }
        }

    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    {
        int value;
        bool validInput = false;
        while (!validInput)
        {
            if (prompt != nullptr)
            {
                cout << prompt;
            }
            if (!(std::cin >> value)) {
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (errMes != nullptr) {
                    cout << errMes << ", retry: " << endl;
                }
                else {
                    cout << "Invalid input, retry: " << endl;
                }
            }
            else if (value < min || value > max) {
                cout << "Value out of range [" << min << "<=val<=" << max << "], retry: " << endl;
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                validInput = true;
            }
        }
        return value;
    }
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
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    
    
    }



    
}