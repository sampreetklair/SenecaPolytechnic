// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include<iostream>
using namespace std;

namespace sdds
{
	class Container
	{
		char Description[50];
		int Capacity;
		int contentVolume;
		bool isContainerValid;
	protected:
		void setEmpty();
		int capacity();
		int volume();
	public:
		Container(const char* Content, int capacity, int volume = 0);
		int operator+=(int);
		int operator-=(int);
		bool validity();
		void clear(int, const char*);
		ostream& print(ostream&);
		istream& read(istream&);
		friend ostream& operator<<(ostream& os, Container& obj)
		{
			return obj.print(os);
		}
		friend istream& operator>>(istream& is, Container& obj)
		{
			return obj.read(is);
		}
	};
}
#endif // !SDDS_CONTAINER_H
