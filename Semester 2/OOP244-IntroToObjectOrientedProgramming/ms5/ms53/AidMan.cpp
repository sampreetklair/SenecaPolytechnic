// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#include "AidMan.h"
#include "Perishable.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<limits>
#include<iomanip>
#include <algorithm>



using namespace std;



namespace sdds 
{

	unsigned int AidMan::menu() const
	{


		cout << "Aid Management System" << endl;
		cout << "Date: " << c_date << endl;

		cout << "Data file: " << ((fileName) ? fileName : "No file")
			<< "\n"
			<< "---------------------------------" << endl;


		return mainMenu.run();
	}
	AidMan::AidMan(const char* file) :
		fileName(nullptr),
		mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"),
		c_date(Date())
	{

	}

	void AidMan::run() {
		unsigned int choice{};
		ifstream ifstr;

		
		do {
			choice = menu();
			if ( (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6) && (fileName == nullptr)) {
				choice = 7; 
			}
			switch (choice) { 
			case 1:

				std::cout << "\n****List Items****\n";
				list();
				break;
			case 2:
				std::cout << "\n****Add Item****\n";
				addItem();
				break;
			case 3:
				std::cout << "\n****Remove Item****\n";
				removeItem();
				break;

			case 4:
				std::cout << "\n****Update Quantity****\n";
				updateQuantity();
				break;
			case 5:
				std::cout << "\n****Sort****\n"; 
				sortItems();
				break;
			case 6:
				std::cout << "\n****Ship Items****\n";
				shipItems();
				break;
			case 7:
				std::cout << "\n****New/Open Aid Database****\n";
				load("data.dat");
				break;
			case 0:
				std::cout << "Exiting Program!\n"; 
				break;
			default:
				std::cout << "Invalid option!\n\n"; 
				break;
			}

		} while (choice != 0);
		ifstr.close();
		
	}
	void AidMan::save()
	{
		if (fileName)
		{
			ofstream outfile(fileName);


			if (outfile.is_open())
			{
				for (int i = 0; i < noOfRecs; i++)
				{
					Product[i]->save(outfile);
					outfile << '\n';
				}

				

				outfile.close();
			}
			else
			{
				cout << "Failed to open " << fileName << " for writing!" << endl;
			}
		}
	}


	bool AidMan::load(const char* filename)
	{
		if (fileName)
		{
			delete[] fileName;
			fileName = nullptr;
		}
		if (filename != nullptr && filename[0] != '\0') {
			fileName = new char[strlen(filename) + 1];
			strcpy(fileName, filename);
		}
		ifstream ifstr(filename);
		if (!ifstr.is_open())
		{
			cout << "Failed to open" << filename << "for reading!" << endl;
			cout << "Would you like to create a new data file?" << endl;
			cout << "1- Yes!" << endl;
			cout << "0- Exit" << endl;
			int choice = 0;
			cin >> choice;
			if (choice == 1)
			{
				ofstream outfile(fileName);
				if (!outfile.is_open())
				{
					cout << "Failed to create new data file!" << endl;
					return false;
				}
				outfile.close();
			}
			return false;
		}

		noOfRecs = 0;

		while (!ifstr.eof() && noOfRecs < sdds_max_num_items)
		{
			if (ifstr.peek() >= '1' && ifstr.peek() <= '3')
			{
				Product[noOfRecs] = new Perishable;
			}
			else if (ifstr.peek() >= '4' && ifstr.peek() <= '9')
			{
				Product[noOfRecs] = new Item;
			}
			else
			{
				ifstr.clear();
				ifstr.ignore(1000, '\n');
				continue;
			}

			Product[noOfRecs]->load(ifstr);

			if (*Product[noOfRecs])
			{
				noOfRecs++;
			}
		}
		if (*this)
		{
			cout << "Enter file name: " << fileName << endl;
			cout << noOfRecs << " records loaded!\n" << endl;

		}
		save();
		return (noOfRecs > 0);
	}


	int AidMan::list(const char* sub_desc) const
	{
		int rowNum = 0;
		int number = 0;
		bool validInput = true;
		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
		for (int i = 0; i < noOfRecs; i++)
		{

			if (sub_desc == nullptr || (sub_desc&&sub_desc[0]!='\0' && strstr(sub_desc,Product[i]->getItemDesc())))
			{
				Product[i]->linear(true);
				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
			else if (sub_desc) {

				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
		}
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;  
		do {
			cout << "Enter row number to display details or <ENTER> to continue:" << endl;
			cout << "> ";
			cin.ignore();
			if (cin.peek() == '\n') {

				cout << "\n";
				break;
			}
			cin >> number;
			if (number >= 1 && number <= rowNum) {
				Product[number - 1]->linear(false);
				Product[number - 1]->display(cout);
				cout << '\n' << '\n';
				/*validInput;*/

			}
			else {
				cout << "Invalid input. Please enter a valid row number." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			cin.get(); 

		} while (!validInput);


		return rowNum;

	}
	void AidMan::addItem() {
		if (noOfRecs >= sdds_max_num_items) {
			std::cout << "Database full!\n";
			return;
		}

		std::cout << "1- Perishable\n2- Non-Perishable\n-----------------\n0- Exit\n> ";

		int addItemChoice;
		std::cin >> addItemChoice;

		switch (addItemChoice) {
		case 1: {
			Perishable* perishableItem = new Perishable();
			if (!addItem(perishableItem)) {
				delete perishableItem;
			}
			break;
		}
		case 2: {
			Item* nonPerishableItem = new Item();
			if (!addItem(nonPerishableItem)) {
				delete nonPerishableItem;
			}
			break;
		}
		case 0:
			std::cout << "Aborted\n";
			break;
		default:
			std::cout << "Invalid choice!\n";
		}
	}
	bool AidMan::addItem(Item* newItem) {
		int sku;
		std::cout << "SKU: ";
		std::cin >> sku;
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		int foundIndex = search(sku,nullptr);

		if (foundIndex != -1) {
			std::cout << "Sku: " << sku << " is already in the system, try updating quantity instead." << endl;
			cin.clear();
			cin.ignore();
			return false;
		}

		newItem->setSku(sku);
		newItem->read(std::cin);

		if (*newItem) {

			Product[noOfRecs] = newItem;
			noOfRecs++;	
			save();
		}
		else {
			newItem->display(std::cout);
			std::cout << "Item not added!\n";
		}

		return true;
	}
	void AidMan::remove(int skuUnit) {
		int foundIndex = search(skuUnit,nullptr);
		cout << "Following item will be removed: " << endl;

		if (foundIndex != -1) {
			Product[foundIndex]->linear(false);
			Product[foundIndex]->display(cout);

			cout << "\nAre you sure?\n1- Yes!\n0- Exit\n> ";

			int confirmChoice;
			cin >> confirmChoice;

			if (confirmChoice == 1) {
				delete Product[foundIndex];
				for (int i = foundIndex; i < noOfRecs - 1; ++i) {
					Product[i] = Product[i + 1];
				}
				noOfRecs--;

				cout << "Item removed!\n\n";
				save();  // Save changes to the file
			}
			else {
				cout << "Aborted!\n";
			}
		}
		else {
			cout << "SKU not found!\n";
		}
	}

	void AidMan::removeItem() {

		char desc[1000];
		int rowNum = 0;
		cout << "Item description: ";
		cin.ignore();
		cin.getline(desc, 1000);


		int foundItems = search(-1,desc);
		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		for (int i = 0; i < noOfRecs; i++)
		{
			if (desc == nullptr || (desc[0] != '\0' && strstr(Product[i]->getItemDesc(), desc)))
			{
				Product[i]->linear(true);
				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
		}

		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;


		if (foundItems >= 0) {
			int skuToRemove;
			cout << "Enter SKU: ";
			cin >> skuToRemove;

			remove(skuToRemove);
		}
		else {
			cout << "No items found with the given description.\n";
		}
	}
	
	void AidMan::sortItems() {

		std::sort(Product, Product + noOfRecs, [](const iProduct* a, const iProduct* b) {
			return (a->qtyNeeded() - a->qty()) > (b->qtyNeeded() - b->qty());

			});

		cout << "Sort completed!\n\n";
		save();
	}
	void AidMan::shipItems()
	{
		ofstream shippingFile("shippingOrder.txt");
		if (!shippingFile.is_open()) {
			cout << "Failed to open shipping-order-file for writing!" << endl;
			return;
		}

		Date currentDate;
		shippingFile << "Shipping Order, Date: " << currentDate << endl;
		shippingFile << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		shippingFile << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		int shippedItems = 0;
		int i = 0;
		while (i < noOfRecs) {
			if (Product[i]->qty() == Product[i]->qtyNeeded()) {
				Product[i]->linear(true);
				shippingFile << "   " << shippedItems + 1 << " | ";
				Product[i]->display(shippingFile);
				shippingFile << endl;

				delete Product[i];
				for (int j = i; j < noOfRecs - 1; ++j) {
					Product[j] = Product[j + 1];
				}
				noOfRecs--;

				shippedItems++;
			}
			else {
				i++;
			}
		}

		shippingFile << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		cout << "Shipping Order for " << shippedItems << " times saved!" << endl;
		cout << endl;

		save();


	}
	void AidMan::updateQuantity() {
		int rowNum = 0;
		char sub_desc[1000];
		cout << "Item description: ";
		cin.ignore();
		cin.getline(sub_desc, 1000);

		int foundItems = search(-1, sub_desc);
		cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		for (int i = 0; i < noOfRecs; i++)
		{
			if (sub_desc == nullptr || (sub_desc[0] != '\0' && strstr(Product[i]->getItemDesc(), sub_desc)))
			{
				Product[i]->linear(true);
				cout << "   " << i + 1 << " | ";
				Product[i]->display(cout);
				rowNum++;
				cout << endl;
			}
		}

		cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;



		if (foundItems >= 0) {
			int skuToUpdate;
	
			cout << "Enter SKU: ";
			cin >> skuToUpdate;

			int foundIndex = search(skuToUpdate, nullptr);

			if (foundIndex != -1) {
				int updateChoice;
				do {
					cout << "1- Add\n2- Reduce\n0- Exit\n> ";
					cin >> updateChoice;

					switch (updateChoice) {
					case 1: {
					if (Product[foundIndex]->qty() == Product[foundIndex]->qtyNeeded()) {
						cout << "Quantity Needed already fulfilled!\n\n";
						updateChoice=0;
						break;
					}
		
						int quantityToAdd;
						int quitLoop = 0;
						cout << "Quantity to add: ";
						cin >> quantityToAdd;
						do
						{
							if (quantityToAdd < 1 || quantityToAdd >(Product[foundIndex]->qtyNeeded() - Product[foundIndex]->qty())) {
								cout << "Value out of range [1<=val<=" << (Product[foundIndex]->qtyNeeded() - Product[foundIndex]->qty()) << "]: ";
								cin >> quantityToAdd;
							}
							else {
								Product[foundIndex]->setQuantity(Product[foundIndex]->qty() + quantityToAdd);
								cout << quantityToAdd << " items added!\n" << endl;
								quitLoop = 1;
								updateChoice = 0;
								save();
							}

						} while (quitLoop == 0);
						
						break;
					}
					case 2: {
						int quantityToReduce;
						int quitLoop=0;
						cout << "Quantity to reduce: ";
						cin >> quantityToReduce;
						do
						{
							if (quantityToReduce < 1 || quantityToReduce > Product[foundIndex]->qty()) {
								cout << "Value out of range [1<=val<=" << Product[foundIndex]->qty() << "]: ";
								cin >> quantityToReduce;
							}
							else {
								Product[foundIndex]->setQuantity(Product[foundIndex]->qty() - quantityToReduce);
								cout << quantityToReduce << " items removed!\n" << endl;
								quitLoop = 1;
								updateChoice = 0;

							}

						} while (quitLoop == 0);
						break;
						
					}
					case 0:
						cout << "Aborted!\n" << endl;
						break;
					default:
						cout << "Invalid choice!" << endl;
						break;
					}

				} while (updateChoice != 0);
			}
			else {
				cout << "SKU not found!" << endl;
			}
		}
		else {
			cout << "No matches found!" << endl;
		}
	}

	int AidMan::search(int stockUnit, const char* description) const {
		for (int i = 0; i < noOfRecs; i++) {
			if (stockUnit != -1 && *Product[i] == stockUnit) {
				return i;  
			}
			else if (description != nullptr && strstr(Product[i]->getItemDesc(), description)) {
				return i;  
			}
		}
		return -1;  
	}


	void AidMan::deallocate()
	{
		for (size_t i = noOfRecs; i > 0;)
		{
			--i;
			delete Product[i];
			Product[i] = nullptr;
		}
		noOfRecs = 0;
	}


	AidMan::~AidMan()
	{
		delete[] fileName;
		fileName = nullptr;
		deallocate();




	}





}
