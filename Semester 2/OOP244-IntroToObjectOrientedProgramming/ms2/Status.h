// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <ostream>

namespace sdds 
{
    class Status
    {
    public:
        Status();
        Status(const char* desc);
        Status(int c);
        Status(const Status& other);
        Status& operator=(const Status& other);
        Status& operator=(const char* desc);
        Status& operator=(int c);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear();
        friend std::ostream& operator<<(std::ostream& os, const Status& status);
        ~Status();

    private:
        char* description;
        int code;
    };



}





#endif