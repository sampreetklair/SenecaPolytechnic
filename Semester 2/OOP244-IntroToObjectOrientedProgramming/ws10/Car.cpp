// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;

#include "Car.h"

using namespace std;

namespace sdds 
{
   Car::Car(const char* plate , const char* makeModel ) 
   {
      strncpy(m_plate, plate, 8);
      m_plate[8] = 0;
      strncpy(m_makeModel, makeModel, 40);
      m_makeModel[40] = 0;;
   }
   std::ostream& Car::display(std::ostream& os)const {
      return os << m_plate << " " << m_makeModel;
   }
   bool Car::operator==(const char* mmSubstr)const {
      return strstr(m_makeModel, mmSubstr) != nullptr;
   
   
   }


}