
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare overloaded read function prototypes
	bool read(int& employeeNum);
	bool read(double& salary);
	bool read(char*& employeeName);
}

#endif // !SDDS_FILE_H_