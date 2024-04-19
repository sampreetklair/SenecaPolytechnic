// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZBB
// Date: 24th March, 2024
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------

#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (unsigned int i = 0; i < desc.size(); i++) {
            for (unsigned int j = 0; j < price.size(); j++) {
                if (desc[i].code == price[j].code) {
                    Product *product = new Product(desc[i].desc, price[j].price);
                    if (!(desc[i].code)) {
                        delete product;
                    }
                    else {
                        try 
						{
                            product->validate();
                        }
                        catch (std::string err)
                        {
                            delete product;
                            throw std::string(err);
                        }
                    }
                    priceList += product;
                    delete product;
                }
            }
        }

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (auto i = 0u; i < desc.size(); ++i) {
			for (auto j = 0u; j < price.size(); ++j) {
				if (desc[i].code == price[j].code) {
					unique_ptr<Product> temp(new Product(desc[i].desc, price[j].price));
					temp->validate();
					priceList += temp;
				}
			}
		}


		return priceList;
	}
}