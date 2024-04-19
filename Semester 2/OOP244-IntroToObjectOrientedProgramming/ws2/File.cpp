// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
	FILE* fptr;
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	void closeFile() {
		if (fptr) fclose(fptr);
	}
	//TODO: read functions go here
	bool read(int& employeeNum) {
		if (fscanf(fptr, "%d,", &employeeNum) == 1) {
			return true;
		}
		return false;
	}
	bool read(double& salary) {
		if (fscanf(fptr, "%lf,", &salary) == 1) {
			return true;
		}
		return false;
	}
	bool read(char*& employeeName) {
		char name[128];
		if (fscanf(fptr, "%127[^,\n]\n", name) == 1) {
			employeeName = new char[strlen(name) + 1];
			strcpy(employeeName, name);
			return true;
		}
		return false;
	}

}