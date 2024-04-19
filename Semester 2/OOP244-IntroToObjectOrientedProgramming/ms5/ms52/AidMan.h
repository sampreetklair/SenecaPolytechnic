// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include"Menu.h"
#include "Date.h"
#include"iProduct.h"
#include "Item.h"
#include<fstream>

namespace sdds 
{
	const int sdds_max_num_items = 100;
	
	class AidMan 
	{
		char* fileName;
		Menu mainMenu;
		Date c_date;
		iProduct* Product[sdds_max_num_items];
		int noOfRecs{};
		unsigned int menu() const;
	public:
		AidMan(const char* file = nullptr);
		AidMan(const AidMan& other) = delete;
		AidMan& operator=(const AidMan& other) = delete;
		~AidMan();

		void addItem();
		void run();
		void save();
		bool load(const char* filename);
		int list(const char* sub_desc = nullptr) const;
		int search(int skuUnit) const;
		bool addItem(Item* newItem);
		operator bool()const { return fileName && noOfRecs; };
		void deallocate();


	};



}
#endif 
