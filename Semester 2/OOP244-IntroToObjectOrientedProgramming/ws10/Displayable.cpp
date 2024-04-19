// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------



#include <iostream>
#include "Displayable.h"

using namespace std;


namespace sdds 
{
   ostream& operator<<(ostream& os, const Displayable& c) {
      return c.display(os);
  
  
   }


   
}