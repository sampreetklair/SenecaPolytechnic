

#include <iostream>
#include "Displayable.h"

using namespace std;


namespace sdds 
{
   ostream& operator<<(ostream& os, const Displayable& c) {
      return c.display(os);
  
  
   }


   
}