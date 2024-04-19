// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds
{
	class Label {
		char frameString[9];
		char* m_content;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		std::istream& readLabel();
		std::ostream& printLabel()const;
		void clear();
		Label& text(const char* content);
	};
}
#endif