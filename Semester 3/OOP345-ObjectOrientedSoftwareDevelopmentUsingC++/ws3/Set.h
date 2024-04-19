// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZBB
// Date: 4th February, 2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------

#ifndef SENECA_SET_H
#define SENECA_SET_H

#include "Collection.h"

namespace seneca 
{
	template <typename T>
	class Set : public Collection<T, 100> 
	{
	public:
		bool add(const T& item);
	};

	template<typename T>
	bool Set<T>::add(const T& item) 
	{
		bool check = true;
		size_t size = this->size();
		for (size_t i = 0;i < size;++i)
		{
			if ((*this)[i] == item)
			{
				check = false;
			}
		}
		if (check)
		{
			Collection<T, 100>::add(item);
		}
		return check;
	}

	template<>
	bool Set<double>::add(const double& item) 
	{
		bool check = true;
		size_t size = this->size();
		for (size_t i = 0;i < size;++i)
		{
			if( ((*this)[i] - item <0.01) && (item - (*this)[i]<0.01))
			{
				check = false;
			}
		}
		if (check)
		{
			Collection<double, 100>::add(item);
		}
		return check;
	
	}

}

#endif