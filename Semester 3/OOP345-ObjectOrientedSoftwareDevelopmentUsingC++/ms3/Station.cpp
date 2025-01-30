

#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"

namespace seneca 
{
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;
    Station::Station(const std::string& record)
    {
        Utilities utilities;
        size_t next_pos = 0;
        bool more = true;
        id = ++id_generator;
        name = utilities.extractToken(record, next_pos, more);
        nextSerialNo = stoi(utilities.extractToken(record, next_pos, more));
        noItems = stoi(utilities.extractToken(record, next_pos, more));
        m_widthField = m_widthField > utilities.getFieldWidth() ? m_widthField : utilities.getFieldWidth();
        desc = utilities.extractToken(record, next_pos, more);
    }
    const std::string& Station::getItemName() const
    {
        return name;
    }
    size_t Station::getNextSerialNumber()
    {
        return nextSerialNo++;
    }
    size_t Station::getQuantity() const
    {
        return noItems;
    }
    void Station::updateQuantity()
    {
        if (noItems > 0)
        {
            noItems--;
        }
    }
    void Station::display(std::ostream& os, bool full) const
    {
        os << std::right;
        os << std::setw(3) << std::setfill('0') << id << " | ";
        os << std::left << std::setfill(' ') << std::setw(m_widthField + 1) << name << "| ";
        os << std::right << std::setw(6) << std::setfill('0') << nextSerialNo << " | ";
        if (full)
        {
            os << std::setfill(' ');
            os << std::right;
            os << std::setw(4) << noItems << " | " << desc;
        }
        os << std::endl;
   
    }

}