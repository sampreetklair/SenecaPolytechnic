// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#include "iProduct.h"

namespace sdds {

    iProduct::~iProduct() { };

    std::ostream& operator<<(std::ostream& os, const iProduct& product) {

        return product.display(os);
    };

    std::istream& operator>>(std::istream& istr, iProduct& product) {

        return product.read(istr);

    };

}