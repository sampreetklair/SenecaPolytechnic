// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#ifndef TRAIN_H
#define TRAIN_H
const int MIN_TIME=700;
const int MAX_TIME = 2300;
const int MAX_NO_OF_PASSENGERS = 1000;
namespace sdds
{
	class Train
	{
		char* trainName;
		int passengerNum;
		int departureTime;
	public:
		void initialize();
		bool validTime(int value)const;
		bool validNoOfPassengers(int value)const;
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		void finalize();
		bool isInvalid()const;
		int noOfPassengers() const;
		const char* getName() const;
		int getDepartureTime() const;
		void display() const;
		int sumOfPassengers(int);
		bool load(int& value);
		bool updateDepartureTime();
		bool transfer(const Train&);
	};

}

	
#endif // !TRAIN_H




