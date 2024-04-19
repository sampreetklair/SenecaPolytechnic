// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Date.h"
#include"Utils.h"
using namespace std;
namespace sdds
{
	//Function that validates the date entered and returns the result accordingly
	bool Date::validate()
	{
		int currentYear;
		ut.getSystemDate(&currentYear);
		if (year < currentYear || year > MAXIMUM_YEAR)
		{
			status = "Invalid year in date";
			status = 1;
			return false;
		}
		if (month < 1 || month>12)
		{
			status = "Invalid month in date";
			status = 2;
			return false;
		}
		if (day<1 || day>ut.daysOfMon(month, year))
		{
			status = "Invalid day in date";
			status = 3;
			return false;
		}
		if (cin.fail()) //checks if the date entered is an invalid integer
		{
			status = "Invalid date value";
			status = 0;
			return false;
		}
		status.clear();
		return true;
	}
	//Returns a unique date value
	int Date::uniqueValue() const
	{
		return (year * 372 + month * 31 + day);
	}
	//Default constructor to set the format to true and get the system date
	Date::Date()
	{
		format = true;
		ut.getSystemDate(&year, &month, &day);

	}
	//Parameterised constructor
	Date::Date(int inputYear, int inputMonth, int inputDay)
	{
		format = true;
		year = inputYear;
		month = inputMonth;
		day = inputDay;
		validate();
	}
	

	//assignment operator check if the unique date value of the passed object is equal to the current object
	bool Date::operator==(const Date& refObject)const
	{
		return (this->uniqueValue() == refObject.uniqueValue());
	}
	//Operator checks if the unique Date value of the current object is unequal to that of the passed object
	bool Date::operator !=(const Date& refObject) const
	{
		return (this->uniqueValue() != refObject.uniqueValue());
	}
	//Operator checks if the unique Date value of the current object is less than that of the passed object
	bool Date::operator<(const Date& refObject) const
	{
		return (this->uniqueValue() < refObject.uniqueValue());
	}
	//Operator checks if the unique Date value of the current object is greater than that of the passed object
	bool Date::operator>(const Date& refObject) const
	{
		return (this->uniqueValue() > refObject.uniqueValue());
	}
	//Operator checks if the unique Date value of the current object is less than or equal to that of the passed object
	bool Date::operator<=(const Date& refObject) const
	{
		return (this->uniqueValue() <= refObject.uniqueValue());
	}
	//Operator checks if the unique Date value of the current object is greater than or equal to that of the passed object
	bool Date::operator>=(const Date& refObject) const
	{
		return(this->uniqueValue() >= refObject.uniqueValue());
	}
	//Returns the reference to the State of the date
	const Status& Date::state()
	{
		return status;
	}
	//Formatted modifier to set the formatted flag of the Date
	Date& Date::formatted(bool isDateFormatted)
	{
		if (isDateFormatted == false)
		{
			format = false;
		}
		return *this;
	}
	//Casting Date object to a boolean value
	Date::operator bool() const
	{
		return status;

	}

	//function that is used to print the formatted or unformatted date to the screen 
	std::ostream& Date::write(std::ostream& os) const
	{
		if (format)
		{
			os << year << "/";
			os.width(2);
			os.fill('0');
			os << month << "/";
			os.width(2);
			os << day;
			os.fill(' ');


		}
		else
		{
			int formatYear = year - 2000;
			os << formatYear;
			os.width(2);
			os.fill('0');
			os << month;
			os.width(2);
			os << day;
			os.fill(' ');
		}
		return os;
	}
	//Function that is used to retrieve the date month and year from the integer value entered
	std::istream& Date::read(std::istream& is)
	{
		int value;
		int dayDigit1, dayDigit2, monthDigit1, monthDigit2, yearDigit2, yearDigit1;
		is >> value;
		if (is)
		{
			if (value <= 9999)
			{
				dayDigit2 = value % 10;
				dayDigit1 = (value / 10) % 10;
				monthDigit2 = (value / 100) % 10;
				monthDigit1 = (value / 1000) % 10;
				if (monthDigit1 == 0)
				{
					month = monthDigit2;
				}
				else
				{
					month = (monthDigit1 * 10) + monthDigit2;
				}
				if (dayDigit1 == 0)
				{
					day = dayDigit2;
				}
				else
				{
					day = (dayDigit1 * 10) + dayDigit2;
				}
				ut.getSystemDate(&year);
			}
			else if (value >= 100000 && value <= 999999)
			{
				dayDigit2 = value % 10;
				dayDigit1 = (value / 10) % 10;
				monthDigit2 = (value / 100) % 10;
				monthDigit1 = (value / 1000) % 10;
				yearDigit2 = (value / 10000) % 10;
				yearDigit1 = (value / 100000) % 10;
				if (yearDigit1 == 0)
				{
					year = 2000 + yearDigit2;

				}
				else
				{
					year = 2000 + ((yearDigit1 * 10) + yearDigit2);
				}
				if (monthDigit1 == 0)
				{
					month = monthDigit2;
				}
				else
				{
					month = (monthDigit1 * 10) + monthDigit2;

				}
				if (dayDigit1 == 0)
				{
					day = dayDigit2;
				}
				else
				{
					day = (dayDigit1 * 10) + dayDigit2;
				}


			}

		}
		if (!validate())
		{
			is.setstate(ios::badbit);
		}
		return is;

	}
	//Helper insertion operator to write the object through ostream
	std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		return date.write(os);

	}
	//Helper extraction operator to read the date object through istream
	std::istream& operator>>(std::istream& is, Date& date)
	{
		return date.read(is);

	}
	


}