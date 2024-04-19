// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZBB
// Date: 11th February, 2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------

// Header files inclusion
#include "ConfirmOrder.h"
#include <iostream>
// namespace inclusion
namespace seneca
{
	ConfirmOrder::ConfirmOrder() : toys(nullptr), size(0), current(0) {}

	ConfirmOrder::ConfirmOrder(const ConfirmOrder& other) {
		current = other.current;
		size = other.size;
		toys = new const Toy * [current];
		for (int i = 0; i < current; i++) {
			toys[i] = other.toys[i];
		}
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& other) {
		if (this != &other) {
			delete[] toys;
			current = other.current;
			size = other.size;
			toys = new const Toy * [current];
			for (int i = 0; i < current; i++) {
				toys[i] = other.toys[i];
			}
		}
		return *this;
	}

	ConfirmOrder::ConfirmOrder(ConfirmOrder&& other) {
		toys = other.toys;
		current = other.current;
		size = other.size;
		other.toys = nullptr;
		other.current = 0;
		other.size = 0;
	}

	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& other) {
		if (this != &other) {
			delete[] toys;
			toys = other.toys;
			current = other.current;
			size = other.size;
			other.toys = nullptr;
			other.current = 0;
			other.size = 0;
		}
		return *this;
	}

	ConfirmOrder::~ConfirmOrder() {
		delete[] toys;
	}
	bool ConfirmOrder::isInArray(const Toy& toy) const {
		for (int i = 0; i < current; i++) {
			if (toys[i] == &toy) {
				return true;
			}
		}
		return false;
	}
	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
		if (!isInArray(toy)) {
			const Toy** temp = new const Toy * [current + 1];
			for (int i = 0; i < current; i++) {
				temp[i] = toys[i];
			}
			temp[current++] = &toy;
			delete[] toys;
			toys = temp;
		}
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
		for (int i = 0; i < current; i++) {
			if (toys[i] == &toy) {
				for (int j = i; j < current - 1; j++) {
					toys[j] = toys[j + 1];
				}
				current--;
				break;
			}
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order) {
		os << "--------------------------\nConfirmations to Send\n--------------------------\n";
		if (order.current == 0) {
			os << "There are no confirmations to send!" << std::endl;;
		}
		else {
			for (int i = 0; i < order.current; i++) {
				os << *order.toys[i];
			}
		}
		os << "--------------------------\n";
		return os;
	}
}
