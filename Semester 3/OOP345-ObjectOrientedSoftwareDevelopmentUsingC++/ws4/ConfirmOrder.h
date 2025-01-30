
#pragma once
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H
#include <iostream>
#include "Toy.h"

// namespace inclusion
namespace seneca
{
	class ConfirmOrder {
	//private data members
		const Toy** toys;
		int size;
		int current;
		bool isInArray(const Toy& toy) const;
	// public data members
	public:
		// default constructor
		ConfirmOrder();
		// parameterized constructor
		ConfirmOrder(const ConfirmOrder& other);
		// parameterized copy constructor operator
		ConfirmOrder& operator=(const ConfirmOrder& other);
		// parameterized constructor
		ConfirmOrder(ConfirmOrder&& other);
		// parameterized copy constructor operator
		ConfirmOrder& operator=(ConfirmOrder&& other);
		// destructor
		~ConfirmOrder();
		// operator overloading
		ConfirmOrder& operator+=(const Toy& toy);
		// operator overloading
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order);
	};
}

#endif
