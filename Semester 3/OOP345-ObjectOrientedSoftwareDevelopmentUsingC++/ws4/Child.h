

#pragma once
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H
#include <string>
#include "Toy.h"

// namespace inclusion
namespace seneca
{
	class Child
	{
	//private data members
	private:
		std::string m_name;
		int m_age;
		const Toy** m_toys;
		size_t m_count;

	// public data members
	public:
		// parameterized constructor
		Child(std::string name, int age, const Toy* toys[], size_t count);
		// parameterized constructor
		Child(const Child& src);
		// parameterized constructor
		Child(Child&& src);
		// parameterized copy constructor operator
		Child& operator=(const Child& src);
		// parameterized copy constructor operator
		Child& operator=(Child&& other);
		// destructor
		~Child();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Child& c);
	};
}

#endif