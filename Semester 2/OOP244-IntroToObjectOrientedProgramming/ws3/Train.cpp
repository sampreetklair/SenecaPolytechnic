
#include <iostream>
#include <cstring>
#include "Train.h"

namespace sdds {
    Train::Train() {
        name = nullptr;
        numPassengers = -1;
        departureTime = -1;
    }

    Train::~Train() {
        delete[] name;
    }

    void Train::initialize() {
        delete[] name;
        name = nullptr;
        numPassengers = -1;
        departureTime = -1;
    }

    bool Train::validTime(int value) const {
        return (value >= MIN_TIME && value <= MAX_TIME && value % 100 < 60);
    }

    bool Train::validNoOfPassengers(int value) const {
        return (value >= 0 && value <= MAX_NO_OF_PASSENGERS);
    }

    void Train::set(const char* trainName) {
        delete[] name;
        name = nullptr;
        if (trainName != nullptr && trainName[0] != '\0') {
            name = new char[strlen(trainName) + 1];
            strcpy(name, trainName);
        }
    }

    void Train::set(int passengers, int departure) {
        if (validNoOfPassengers(passengers) && validTime(departure)) {
            numPassengers = passengers;
            departureTime = departure;
        }
        else {
            numPassengers = -1;
            departureTime = -1;
        }
    }

    void Train::set(const char* trainName, int passengers, int departure) {
        set(trainName);
        set(passengers, departure);
    }

    void Train::finalize() {
        delete[] name;
        name = nullptr;
    }

    bool Train::isInvalid() const {
        return (name == nullptr || numPassengers == -1 || departureTime == -1);
    }

    int Train::noOfPassengers() const {
        return numPassengers;
    }

    const char* Train::getName() const {
        return name;
    }

    int Train::getDepartureTime() const {
        return departureTime;
    }

    void Train::display() const {
    if (!isInvalid()) {
        std::cout << "NAME OF THE TRAIN:    " << name << std::endl;
        std::cout << "NUMBER OF PASSENGERS: " << numPassengers << std::endl;
        std::cout << "DEPARTURE TIME:       " << departureTime << std::endl;
    }
    else {
        std::cout << "Train in an invalid State!" << std::endl;
    }
}

}
