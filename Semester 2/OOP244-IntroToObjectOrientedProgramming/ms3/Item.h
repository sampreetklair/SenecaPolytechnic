// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#include <fstream>
#include "iProduct.h"
#include "Status.h"
namespace sdds 
{
    class Item : public iProduct 
    {
        double Price;
        int Quantity;
        int Quantity_Needed;
        char* Description;
        bool Linear;
    protected:
        Status state;
        int SKU{};
        bool linear()const;
    public:
        Item();
        Item(const Item& I);
        Item& operator=(const Item& I);
        ~Item();
        int qtyNeeded()const;
        int qty()const;
        operator double()const;
        operator bool() const;
        int operator-=(int qty);
        int operator+=(int qty);
        void linear(bool isLinear);
        void clear();
        bool operator==(int sku)const;
        bool operator==(const char* description) const;
        std::ofstream& save(std::ofstream& ofstr)const;
        std::ifstream& load(std::ifstream& ifstr);
        std::ostream& display(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
        int readSku(std::istream& istr);

    
    };

}

#endif // !SDDS_ITEM_H_