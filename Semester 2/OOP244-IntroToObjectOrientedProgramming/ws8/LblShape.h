// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_LBL_SHAPE_H
#define SDDS_LBL_SHAPE_H

#include "Shape.h"

namespace sdds 
{
	class LblShape : public Shape 
	{
	private:
		char* m_label = nullptr;

	protected:
		const char* label() const;

	public:
		LblShape();
		LblShape(const char* cString);
		void getSpecs(std::istream& is);
		~LblShape();
	};
	
}
#endif // !SDDS_LBL_SHAPE_H