// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"
using namespace sdds;

namespace sdds
{
	class Pack : public Container
	{
	private:
		int unitSize;
		int Size;
		int numUnits;
	public:
		Pack(const char* content, int size, int unit_Size = 330, int no_of_units = 0);
		int operator+=(int);
		int operator-=(int);
		int unit();
		int noOfUnits();
		int size();
		void clear(int, int, const char*);
		ostream& print(ostream&);
		istream& read(istream&);
		friend ostream& operator << (ostream& os, Pack& obj)
		{
			return obj.print(os);
		}
		friend istream& operator >> (istream& is, Pack& obj)
		{
			return obj.read(is);
		}

	};
}
#endif // !SDDS_CONTAINER_H
