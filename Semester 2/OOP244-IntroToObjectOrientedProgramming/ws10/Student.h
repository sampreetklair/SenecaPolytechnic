// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------


#include <iostream>
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H


#include "Displayable.h"
namespace sdds 
{
   class Student : public Displayable
    {
      int m_stno{};
      char m_name[41]{};
      double m_gpa{};
   public:
      Student() = default;
      Student(int stno, const char* name, double gpa);
      std::ostream& display(std::ostream& os)const;
      bool operator==(double gpa)const;
  
  
   };


   
}
#endif

