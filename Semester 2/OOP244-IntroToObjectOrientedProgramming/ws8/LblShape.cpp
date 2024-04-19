// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#include <iostream>
#include <string.h>
#include "LblShape.h"
#include "Shape.h"
using namespace std;


namespace sdds
{
	LblShape::LblShape() 
	{
		if (this->m_label != nullptr) 
		{
			m_label = nullptr;
		}
	};

	LblShape::LblShape(const char* cString) 
	{

		delete[] this->m_label;
		this->m_label = new char[strlen(cString) + 1];
		strcpy(this->m_label, cString);
	};

	const char* LblShape::label() const 
	{
		return m_label;
	};

	void LblShape::getSpecs(std::istream& is) 
	{
		char cString[100];

		is.get(cString, 100, ',');
		is.ignore();

		delete[] this->m_label;
		m_label = new char[strlen(cString) + 1];
		strcpy(m_label, cString);
	};

	LblShape::~LblShape() 
	{
		delete[] m_label;
	};

}