// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H
#include "Student.h"

namespace sdds{
    class Graduate : public Student 
    {
        char* m_thesis{ nullptr };
        char* m_supervisor{ nullptr };
        void setEmpty();
    public:
        Graduate();
        Graduate(const char* name, size_t age, const char* thesis, const char* supervisor);
        virtual ~Graduate();
        Graduate(const Graduate& graduate);
        Graduate& operator=(const Graduate& graduate);
        void display() const;
   
   
    };


}
#endif // !SDDS_GRADUATE_H