// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------


#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds
 {
   class Displayable
    {
   public:
      virtual std::ostream& display(std::ostream& os)const = 0;
  
  
   };
 
   std::ostream& operator<<(std::ostream& os, const Displayable& c);
   
}
#endif 
