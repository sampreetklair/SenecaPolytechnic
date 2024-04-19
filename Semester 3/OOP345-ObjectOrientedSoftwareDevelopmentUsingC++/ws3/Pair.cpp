// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZBB
// Date: 4th February, 2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------

#include "Pair.h"
#include <iostream>
#include <string>
#include <iomanip>

namespace seneca 
{
	Pair::Pair() 
	{
		m_key = "";
		m_value = "";
	}
	bool Pair::operator==(const Pair& src) 
	{
		return this->getKey() == src.m_key;
	}
	std::ostream& Pair::display(std::ostream& ostr)const 
	{
		ostr << std::right << std::setw(20) << m_key << ": " << std::left << m_value;
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Pair& rhs) 
	{
		return rhs.display(ostr);
	}

}
