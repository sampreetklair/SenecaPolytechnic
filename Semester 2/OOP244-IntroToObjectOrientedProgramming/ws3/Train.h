
#ifndef TRAIN_H
#define TRAIN_H

namespace sdds {
    const int MIN_TIME = 700;
    const int MAX_TIME = 2300;
    const int MAX_NO_OF_PASSENGERS = 1000;

    class Train {
        char* name;
        int numPassengers;
        int departureTime;

    public:
        Train();
        ~Train();
        void initialize();
        bool validTime(int value) const;
        bool validNoOfPassengers(int value) const;
        void set(const char* name);
        void set(int noOfPassengers, int departure);
        void set(const char* name, int noOfPassengers, int departure);
        void finalize();
        bool isInvalid() const;
        int noOfPassengers() const;
        const char* getName() const;
        int getDepartureTime() const;
        void display() const;
    };
}

#endif // TRAIN_H
