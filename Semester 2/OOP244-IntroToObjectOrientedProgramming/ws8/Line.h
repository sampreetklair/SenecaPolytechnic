// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds
{
	class Line : public LblShape
	{
	private:
		int m_length;

	public:
		Line();
		Line(const char* cString, const int length);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};

}

#endif // !SDDS_LINE_H