// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include "File.h"
#include "Population.h"

using namespace std;
namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    int noOfRecords(const char* postalCodePrefix) {
        int noOfRecs = 0;
        char postalCode[MAX_POSTAL_CODE_LEN + 1];
        int population;
        while (fscanf(fptr, "%3s,%d\n", postalCode, &population) == 2) {
            if (startsWith(postalCode, postalCodePrefix)) {
                noOfRecs++;
            }
        }
        rewind(fptr);
        return noOfRecs;
    }

    bool read(char*& postalCode)
    {
        char temp[MAX_POSTAL_CODE_LEN + 1];
        bool success = fscanf(fptr, "%3s,", temp) == 1;
        if (success)
        {
            postalCode = new char[strlen(temp) + 1];
            strcpy(postalCode, temp);
        }
        return success;
    }

    bool read(int& population)
    {
        return fscanf(fptr, "%d\n", &population) == 1;
    }

    bool read(char*& postalCode, const char* partial_postal_code_prefix)
    {
        char temp[MAX_POSTAL_CODE_LEN + 1];
        bool success = fscanf(fptr, "%3s,", temp) == 1;
        if (success)
        {
            if (startsWith(temp, partial_postal_code_prefix))
            {
                postalCode = new char[strlen(temp) + 1];
                strcpy(postalCode, temp);
            }
            else
            {
                success = false;
            }
        }
        return success;
    }
}