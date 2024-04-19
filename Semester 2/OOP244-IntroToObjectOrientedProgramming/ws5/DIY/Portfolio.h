// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);
        void dispPortfolio() const;
        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const;
        Portfolio& operator +=(double value);
        Portfolio& operator -=(double value);
        double getvalue() const;
        Portfolio& operator <<(Portfolio& right);
        Portfolio& operator >>(Portfolio& right);
        bool istrueportfolio() const;
        void  emptyPortfolio();
        std::ostream& display() const;
    };
    bool operator ~(const Portfolio& port);
    double operator +(const Portfolio& p1, Portfolio& p2);
    double operator +=(double& value, const Portfolio& p1);
}
#endif // SDDS_Portfolio_H_