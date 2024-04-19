// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H
#define MAX_LENGTH 20

struct Customer {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    char address[MAX_LENGTH];
    char city[MAX_LENGTH];
    char province[MAX_LENGTH];
    char postalCode[MAX_LENGTH];
};

void getCustomerInfo(struct Customer* customer);
int checkString(char* str);
int validatePostalCode(char* pos);
int validateString(char* Str);
#endif 
