// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Status.h"
#include"Utils.h"
using namespace std;
namespace sdds
{
	//Default constructor
	Status::Status()
	{
		description = nullptr;
		code = 0;
	}
	//Parameterised constructor with description that is to be copied
	Status::Status(const char* refDescription)
	{
		code = 0;
		if (refDescription != nullptr) 
		{
			ut.alocpy(description, refDescription);
		}
		else
		{
			description = nullptr;
		}

	}
	//copy Constructor 
	Status::Status(const Status& obj)
	{
		if (obj.description != nullptr)
		{
			ut.alocpy(description, obj.description);
			code = obj.code;
		}
		else
		{
			delete[] description;
			description = nullptr;
			code = 0;
		}

	}
	//Deallocates description and sets the code to 0
	Status& Status::clear()
	{
		if (description != nullptr)
		{
			delete[] description;
			description = nullptr;
			code = 0;
		}

		return *this;
	}
	//Overloaded assignment operator to copy the description
	Status& Status::operator = (const char* refDescription)
	{
		if (refDescription != nullptr)
		{
			ut.alocpy(description, refDescription);

		}
		return*this;
	}
	//Overloaded assignment operator to copy the code
	Status& Status::operator=(const int refCode)
	{
		code = refCode;
		return *this;

	}
	//casting the status object to an integer
	Status::operator int() const
	{
		return code;
	}
	//casting the status object to a character pointer
	Status::operator const char* () const
	{
		return description;
	}
	//casting the status object to a boolean value
	Status::operator bool() const
	{
		return(description == nullptr);
	}
	
	//operator to print the status of the object passed
	std::ostream& Status::printStatus(std::ostream& obj) const
	{
		if (code != 0)
		{
			obj << "ERR#" << code << ": ";
			obj << description;
		}
		else
		{
			obj << description;

		}
		return obj;
	}
	//Destructor to deallocate the dynamically allocated memory
	Status::~Status()
	{
		if (description != nullptr)
		{
			delete[] description;
			description = nullptr;
		}

	}
	//Overloaded insertion operator to print the status about the object passed as an argument
	std::ostream& operator<<(std::ostream& os, const Status& obj)
	{
		if (!obj)
		{
			obj.printStatus(os);
		}
		return os;
	}


}