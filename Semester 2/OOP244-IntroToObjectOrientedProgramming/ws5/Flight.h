// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>
#include <string>

namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;
    const int MinFuelPerPassenger = 600;

    class Flight {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char* () const;
        bool operator ~ () const;
        Flight& operator=(Flight& other);
        Flight& operator=(int value);
        Flight& operator=(double value);
        Flight& operator+=(double fuelValue);
        Flight& operator+=(int passengers);
        Flight& operator-=(double fuelValue);
        Flight& operator-=(int passengers);
        Flight& operator<<(Flight& other);
        Flight& operator>>(Flight& other);
        int operator+(const Flight& reference);

    };
    int operator+=(int& ref1, const Flight& ref2);

}
#endif // SDDS_FLIGHT_H