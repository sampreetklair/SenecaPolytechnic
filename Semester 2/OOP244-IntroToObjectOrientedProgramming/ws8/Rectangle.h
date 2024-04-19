// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds 
{
	class Rectangle : public LblShape 
	{
	private:
		int m_width;
		int m_height;

	public:
		Rectangle();
		Rectangle(const char* cString, const int width, const int height);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};


}


#endif // !SDDS_RECTANGLE_H