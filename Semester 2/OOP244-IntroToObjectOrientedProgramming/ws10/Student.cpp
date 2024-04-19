// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------


#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "Student.h"

namespace sdds
 {

   Student::Student(int stno, const char* name, double gpa) 
   {
      m_stno = stno;
      strcpy(m_name, name);
      m_gpa = gpa;
   }
   ostream& Student::display(ostream& os)const {
      return os << m_name << " (" << m_stno << ") GPA: " << fixed << setprecision(1) << m_gpa;
   }
   
   bool Student::operator==(double gpa)const {
      return m_gpa > (gpa - 0.001) && m_gpa < (gpa + 0.001);
 
 
   }


   
}