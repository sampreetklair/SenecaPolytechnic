// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------


#include <iostream>
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "Displayable.h"

namespace sdds
 {
   class Car : public Displayable {
      char m_plate[9]{};
      char m_makeModel[41]{};
   public:
      Car() = default;
      Car(const char* plate , const char* makeModel);
      std::ostream& display(std::ostream& os)const;
      bool operator==(const char* mmSubstr)const;
   
   
   
   
   };


}
#endif // !SDDS_CAR_H_
