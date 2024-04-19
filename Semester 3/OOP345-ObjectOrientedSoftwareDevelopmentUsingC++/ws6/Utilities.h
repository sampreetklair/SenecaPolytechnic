// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZBB
// Date: 10th March, 2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------

#ifndef SENECA_UTILITES_H
#define SENECA_UTITLITIES_H
#include "Person.h"

namespace seneca 
{
	Person* buildInstance(std::istream& in);
	bool isDigit(std::string& src);
	std::string& trim( std::string& src);
	
}

#endif