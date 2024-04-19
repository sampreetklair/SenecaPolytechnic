// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#define MAX_POSTAL_CODE_LEN 3
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	int noOfRecords(const char* postalCodePrefix);
	bool read(char*& postalCode);
	bool read(int& population);
	bool read(char*& postalCode, const char* partial_postal_code_prefix);

}
#endif // !SDDS_FILE_H_
