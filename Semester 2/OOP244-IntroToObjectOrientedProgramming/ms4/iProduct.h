// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_IPRODUCT_H
#define SDDS_IPRODUCT_H
#include <fstream>
#include <iostream>

using namespace std;

namespace sdds{
    
    class iProduct{

    public:
        virtual ~iProduct();
        virtual int readSku(std::istream& istr);
        virtual int operator-=(int qty);
        virtual int operator+=(int qty);
        virtual operator double() const;
        virtual operator bool() const;
        virtual int qtyNeeded() const;
        virtual int qty() const;
        virtual void linear(bool isLinear);
        virtual ofstream& save(ofstream& ofstr)const;
        virtual ifstream& load(ifstream& ifstr);
        virtual ostream& display(ostream& ostr) const;
        virtual istream& read(istream& istr);
        virtual bool operator==(int sku) const;
        virtual bool operator==(const char* description) const;
  
    };

    istream& operator>>(istream&, iProduct&);
    ostream& operator<<(ostream&, const iProduct&);


}

#endif // !SDDS_IPRODUCT_H

