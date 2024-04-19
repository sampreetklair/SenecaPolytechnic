// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#ifndef _SDDS_STATUS_H
#define _SDDS_STATUS_H
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	class Status
	{
		char* description{};
		int code;
	public:
		//Default constructor
		Status();
		//Parameterised constructor with description that is to be copied
		Status(const char* refDescription);
		//copy Constructor
		Status(const Status& obj);
		//Deallocates description and sets the code to 0
		Status& clear();
		//Overloaded assignment operator to copy the description
		Status& operator=(const char* description);
		//Overloaded assignment operator to copy the code
		Status& operator=(int code);
		//casting the status object to an integer
		operator int() const;
		//casting the status object to a boolean value
		operator bool() const;
		//casting the status object to a character pointer
		operator const char* () const;
		//Helper operator to print the status of the object passed
		std::ostream& printStatus(std::ostream& obj) const;
		//Destructor to deallocate the dynamically allocated memory
		~Status();

	};
	//Overloaded insertion operator to print the status about the object passed as an argument
	std::ostream& operator << (std::ostream& os, const Status& obj);
}
#endif