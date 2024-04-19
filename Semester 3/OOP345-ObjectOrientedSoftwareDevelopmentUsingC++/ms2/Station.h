// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZBB
// Date: 23rd March, 2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------

#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <iostream>

namespace seneca 
{
	class Station 
    {
        int m_id;
        std::string m_itemName;
        std::string m_description;
        size_t m_nextSerialNumber;
        size_t m_quantity;
        static size_t m_widthField;
        static int id_generator;
    public:
        Station(const std::string& src);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;

	};

}

#endif
