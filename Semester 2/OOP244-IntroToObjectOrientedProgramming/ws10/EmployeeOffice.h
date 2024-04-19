// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------


#include <iostream>
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "Displayable.h"


namespace sdds 
{
   class EmployeeOffice : public Displayable 
   {
      int m_office{};
      char m_name[41]{};
   public:
      EmployeeOffice() = default;
      EmployeeOffice(const char* name, int office);
      std::ostream& display(std::ostream& os)const;
      bool operator==(int office)const;
  
  
   };


}
#endif