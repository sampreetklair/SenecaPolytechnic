// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstring>
#include "Pack.h"
using namespace std;
namespace sdds
{
	Pack::Pack(const char* content, int size, int unit_Size, int no_of_units)
		:Container(content, (size* unit_Size), (unit_Size* no_of_units))
	{
		this->Size = size;
		this->unitSize = unit_Size;
		this->numUnits = no_of_units;

	}
	int Pack::operator+=(int value)
	{
		int totalUnits = value * unitSize;
		int result = Container::operator+=(totalUnits) / unitSize;
		this->numUnits += result;
		return result;

	}
	int Pack::operator-=(int value)
	{
		int totalUnits = value * unitSize;
		int result = Container::operator-=(totalUnits) / unitSize;
		this->numUnits -= result;
		return result;
	}
	int Pack::unit()
	{
		return unitSize;
	}
	int Pack::noOfUnits()
	{
		return numUnits;
	}
	int Pack::size()
	{
		return Size;
	}
	void Pack::clear(int packSize, int unit_Size, const char* content)
	{
		if (unit_Size > 0)
		{
			Size = packSize;
			Container::clear(packSize * unit_Size, content);
			unitSize = unit_Size;
			numUnits = 0;
		}

	}
	ostream& Pack::print(ostream& os)
	{
		Container::print(os);
		if (validity())
		{
			os << ", " << numUnits << " in a pack of " << Size;

		}
		return os;
	}
	istream& Pack::read(istream& is)
	{
		int inputUnits;
		if (!validity())
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			is.ignore();
		}
		else
		{
			int quitLoop = 0;
			int missingUnits = Size - numUnits;
			if (numUnits < Size)
			{
				cout << "Add to ";
				print(cout);
				cout << endl << "> ";
				is >> inputUnits;
				while (quitLoop == 0)
				{

					if (is.fail())
					{
						cout << "Invalid Integer, retry: ";
						cout << endl << "> ";
						is >> inputUnits;

					}
					else if (inputUnits < 1 || inputUnits > missingUnits)
					{
						cout << "Value out of range [1<=val<=" << missingUnits << "]: ";
						is >> inputUnits;
					}
					else
					{
						quitLoop = 1;
					}

				}
			}
			else
			{
				is.ignore();
				cout << "Pack is full!, press <ENTER> to continue...";

			}
			inputUnits = (*this += inputUnits);
			cout << "Added " << inputUnits << endl;
		}

		return is;
	}
}

