

#include "iProduct.h"



namespace sdds 
{
	std::istream& operator>>(std::istream& istr, iProduct& p) 
	{
		return p.read(istr);
	}
	std::ostream& operator<<(std::ostream& ostr, iProduct& p) 
	{
		return p.display(ostr);
	}
}
	