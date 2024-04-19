// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Train.h"
using namespace std;
using namespace sdds;

void Train::initialize()
{
	trainName = nullptr;
	passengerNum = -1;
	departureTime = -1;

}

bool Train::validTime(int value) const
{
	if (value <= MAX_TIME && value >= MIN_TIME)
	{
		int minutes = value % 100; 
		if (minutes <= 59)
		{
			return true;

		}

	}
	return false;
}


bool Train::validNoOfPassengers(int value) const
{
	if (value > 0 && value < MAX_NO_OF_PASSENGERS)
	{
		return true;
	}
	else
	{
		return false;


	}
}

void Train::set(const char* name)
{
	finalize(); 
	if (name != nullptr && name[0] != '\0')
	{
		trainName = new char[strlen(name) + 1];

		strcpy(trainName, name);
	}

}
void Train::set(int noOfPassengers, int departure)
{
	if (validTime(departure) && validNoOfPassengers(noOfPassengers)) 
	{
		departureTime = departure;
		passengerNum = noOfPassengers;


	}
	else
	{
		departureTime = -1;
		passengerNum = -1;
	}


}

void Train::set(const char* name, int noOfPassengers, int departure)
{
	set(name); 
	set(noOfPassengers, departure); 
}


void Train::finalize()
{
	if (trainName != nullptr)
	{
		delete[] trainName;
		trainName = nullptr;

	}

}

bool Train::isInvalid() const
{
	if (trainName == nullptr || passengerNum == -1 || departureTime == -1)
	{
		return true;
	}
	else
	{
		return false;
	}


}

int Train::noOfPassengers() const
{
	return passengerNum;

}

const char* Train::getName() const
{
	return trainName;
}

int Train::getDepartureTime() const
{
	return departureTime;
}

void Train::display() const
{
	if (!isInvalid()) 
	{
		cout << "NAME OF THE TRAIN:    " << trainName << endl;
		cout << "NUMBER OF PASSENGERS: " << passengerNum << endl;
		cout << "DEPARTURE TIME:       " << departureTime << endl;
	}
	else
	{
		cout << "Train in an invalid State!" << endl;
	}

}

int Train::sumOfPassengers(int passengerValue)
{

	int totalPassengers;
	totalPassengers = passengerNum + passengerValue;
	return totalPassengers;
}

bool Train::load(int& leftPassengers)
{
	int totalPassengers;
	int noOfPassengers;
	cout << "Enter number of passengers boarding:" << endl;
	cout << "> ";
	cin >> noOfPassengers;
	totalPassengers = sumOfPassengers(noOfPassengers); 
	if (totalPassengers > MAX_NO_OF_PASSENGERS)
	{
		leftPassengers = (totalPassengers - MAX_NO_OF_PASSENGERS);
		passengerNum = MAX_NO_OF_PASSENGERS;
		
	}
	else
	{
		leftPassengers = 0;
		passengerNum = totalPassengers;
	}
	return leftPassengers == 0; 
}

bool Train::updateDepartureTime()
{
	int newDepartureTime;
	cout << "Enter new departure time:" << endl;
	cout << "> ";
	cin >> newDepartureTime; 
	if (validTime(newDepartureTime))
	{
		departureTime = newDepartureTime; 
		return true;

	}
	else
	{
		departureTime = -1;
		return false;
	}
}
bool Train::transfer(const Train& secondTrain)
{
	if (!isInvalid() && !secondTrain.isInvalid()) 
	{
		int totalPassengers, passengersLeft;
		char* combinedName = new char[strlen(trainName) + strlen(secondTrain.trainName) + 3]; 
		strcpy(combinedName, trainName); 
		strcat(combinedName, ", ");
		strcat(combinedName, secondTrain.trainName);

		delete[] trainName;
		trainName = combinedName;
		totalPassengers = sumOfPassengers(secondTrain.passengerNum);
		if (totalPassengers > MAX_NO_OF_PASSENGERS)
		{
			passengersLeft = totalPassengers - MAX_NO_OF_PASSENGERS;
			cout << "Train is full; " << passengersLeft << " passengers of " << secondTrain.trainName << " could not be boarded!" << endl;
			passengerNum = MAX_NO_OF_PASSENGERS;


		}
		else
		{
			passengerNum = totalPassengers;
			
		}
		
		return true;
		
	}
	return false;

}






	

