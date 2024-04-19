// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_SELECTION_H_
#define SDDS_SELECTION_H_

#include <iostream>
#include <cstring>

namespace sdds 
{
	template <typename arrayType, typename keyType>
	int* select(const arrayType array[], const keyType& key, size_t size)
	{
		int count = 0;
		for (size_t i = 0; i < size; ++i)
		{
			if (array[i] == key)
			{
				++count;
			}
		}

		int* indices = new int[count + 1];
		int index = 0;
		for (size_t i = 0; i < size; ++i)
		{
			if (array[i] == key)
			{
				indices[index++] = static_cast<int>(i);
			}
		}
		indices[index] = -1;

		return indices;
	}

	template <typename arrayType>
	void csvDisplaySelection(const char* title, const arrayType array[], const int* indices)
	{
		std::cout << title << std::endl;

		if (indices && indices[0] != -1)
		{
			for (int i = 0; indices[i] != -1; ++i)
			{
				std::cout << array[indices[i]];
				if (indices[i + 1] != -1)
				{
					std::cout << ", ";
				}
			}
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Empty Selection" << std::endl;
	
		}


	}



}

#endif // !SDDS_SELECTION_H_
