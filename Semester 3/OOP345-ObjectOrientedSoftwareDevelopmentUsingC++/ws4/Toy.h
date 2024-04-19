// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZBB
// Date: 11th February, 2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------

#pragma once
#ifndef SENECA_TOY_H
#define SENECA_TOY_H

#include <iostream>
#include <string>

// namespace inclusion
namespace seneca
{
	class Toy
	{
		//private data members
		int orderId;
		std::string name;
		int numItems;
		double price;
		double HST = 0.13;
	// public data members
	public:
		// default constructor
		Toy();
		// parameterized constructor
		Toy(const std::string& toy);
		void update(int numItems);

		friend std::ostream& operator<<(std::ostream& os, const Toy& toy);

	};
}
#endif
