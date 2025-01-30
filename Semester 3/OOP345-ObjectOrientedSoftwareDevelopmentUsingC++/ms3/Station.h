
#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iostream>
#include <string>

namespace seneca 
{
	class Station
	{
		int id;
		std::string name;
		std::string desc;
		unsigned int nextSerialNo;
		unsigned int noItems;
		static size_t m_widthField;
		static int id_generator;

	public:
		Station(const std::string& record);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	
	};

};

#endif