// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#include "iProduct.h"

namespace sdds 
{
	std::istream& operator>>(std::istream& istr, iProduct& p) {
		return p.read(istr);
	}
	std::ostream& operator<<(std::ostream& ostr, iProduct& p) {
		return p.display(ostr);
	
	
	}


	
}