
// Header files inclusion
#include "Toy.h"
#include <iomanip>
// namespace inclusion
using namespace std;
namespace seneca
{
    Toy::Toy() {
        orderId = 0;
        name = "";
        numItems = 0;
        price = 0.0;
    }

    Toy::Toy(const string& toy) {
        string temp = toy;
        int firstColon = temp.find(':');
        orderId = stoi(temp.substr(0, firstColon));
        temp.erase(0, firstColon + 1);

        int secondColon = temp.find(':');
        name = temp.substr(0, secondColon);
        temp.erase(0, secondColon + 1);
        name.erase(0, name.find_first_not_of(" "));
        name.erase(name.find_last_not_of(" ") + 1);

        int thirdColon = temp.find(':');
        numItems = stoi(temp.substr(0, thirdColon));
        temp.erase(0, thirdColon + 1);

        price = stod(temp);
    }

    void Toy::update(int numItems) {
        this->numItems = numItems;
    }

    ostream& operator<<(ostream& os, const Toy& toy) {
        os << "Toy" << right << setw(8) << toy.orderId << ":"
            << right << setw(18) << setfill(' ') << toy.name
            << right << setw(3) << setfill(' ') << toy.numItems << " items"
            << right << setw(8) << setfill(' ') << toy.price << "/item  subtotal:"
            << right << setw(7) << setfill(' ') << fixed << setprecision(2) << toy.price * toy.numItems << " tax:"
            << right << setw(6) << setfill(' ') << fixed << setprecision(2) << toy.price * toy.numItems * toy.HST << " total:"
            << right << setw(7) << setfill(' ') << fixed << setprecision(2) << toy.price * toy.numItems * (1 + toy.HST) << endl;
        return os;
    }
}
