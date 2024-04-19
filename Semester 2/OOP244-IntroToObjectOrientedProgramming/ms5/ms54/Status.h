// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>

namespace sdds 
{
	class Status
	{
		char* description{};
		int statusCode{};
	public:
		Status() {}
		Status(char* desc, int status);
		~Status();
		Status(const Status& other);
		void setStatus(int status);
		void setStatus(const char* status);
		int getStatus() const;
		const char* getDescription()const;
		operator int() const;
		operator const char* () const;
		operator bool() const;
		Status& operator=(const char* newDesc);
		Status& operator=(const int newStatus);
		Status& clear();



	};


	std::ostream& operator <<(std::ostream& ostr, const Status& status);

	
}
#endif // !STATUS_H