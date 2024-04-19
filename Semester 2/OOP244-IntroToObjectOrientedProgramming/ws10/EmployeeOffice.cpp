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

#include "EmployeeOffice.h"
namespace sdds 
{

   EmployeeOffice::EmployeeOffice(const char* name, int office) { 
      strcpy(m_name, name);
      m_office = office;
   }
   ostream& EmployeeOffice::display(ostream& os)const {
      return os << m_name << " (Office# " << m_office << ")";
   }
   bool EmployeeOffice::operator==(int office)const {
      return m_office == office;
  
   }


}
