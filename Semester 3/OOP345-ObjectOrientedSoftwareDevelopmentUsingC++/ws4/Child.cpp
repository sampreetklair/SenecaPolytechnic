

// Header files inclusion
#include <iostream>
#include <cstring>
#include "Child.h"
// namespace inclusion
namespace seneca
{
	Child::Child(std::string name, int age, const Toy* toys[], size_t count) : m_name(name), m_age(age), m_count(count) {
		m_toys = new const Toy * [count];
		for (size_t i = 0; i < count; i++) {
			m_toys[i] = new Toy(*toys[i]);
		}
	}

	Child::Child(const Child& src) : m_name(src.m_name), m_age(src.m_age), m_count(src.m_count) {
		m_toys = new const Toy * [m_count];
		for (size_t i = 0; i < m_count; i++) {
			m_toys[i] = new Toy(*src.m_toys[i]);
		}
	}

	Child& Child::operator=(const Child& src) {
		if (this != &src) {
			for (size_t i = 0; i < m_count; i++) {
				delete m_toys[i];
			}
			delete[] m_toys;
			m_name = src.m_name;
			m_age = src.m_age;
			m_count = src.m_count;
			m_toys = new const Toy * [m_count];
			for (size_t i = 0; i < m_count; i++) {
				m_toys[i] = new Toy(*src.m_toys[i]);
			}
		}
		return *this;
	}

	Child::Child(Child&& src) : m_name(std::move(src.m_name)), m_age(src.m_age), m_toys(src.m_toys), m_count(src.m_count) {
		src.m_age = 0;
		src.m_toys = nullptr;
		src.m_count = 0;
	}

	Child& Child::operator=(Child&& other) {
		if (this != &other) {
			for (size_t i = 0; i < m_count; i++) {
				delete m_toys[i];
			}
			delete[] m_toys;
			m_name = std::move(other.m_name);
			m_age = other.m_age;
			m_count = other.m_count;
			m_toys = other.m_toys;
			other.m_age = 0;
			other.m_toys = nullptr;
			other.m_count = 0;
		}
		return *this;
	}
	
	// destructor
	Child::~Child() {
		for (size_t i = 0; i < m_count; i++) {
			delete m_toys[i];
		}
		delete[] m_toys;
	}

	size_t Child::size() const {
		return m_count;
	}

	std::ostream& operator<<(std::ostream& os, const Child& c) {
		static int cnt = 0;
		os << "--------------------------" << std::endl
			<< "Child " << ++cnt << ": " << c.m_name << " " << c.m_age << " years old:" << std::endl
			<< "--------------------------" << std::endl;

		if (c.m_count == 0) {
			os << "This child has no toys!" << std::endl;
		}
		else {
			for (size_t i = 0; i < c.m_count; i++) {
				os << *c.m_toys[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
