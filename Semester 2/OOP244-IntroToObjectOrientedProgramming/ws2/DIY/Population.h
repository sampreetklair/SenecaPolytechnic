// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    struct Population {
        char* postalCode;
        int population;
    };

    void sort();
    int totalPopulation();
    bool getPostalCode(char* postal_code_prefix);
    bool load(Population& record);
    bool load(const char* filename);
    bool load(const char* filename, const char* partial_postal_code_prefix);
    bool startsWith(const char* cString, const char* subString);
    void display(const int count, const Population& record);
    void display();
    void deallocateMemory();

}
#endif // SDDS_POPULATION_H_