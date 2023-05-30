#ifndef TAXI_H
#define TAXI_H

#include <iostream>
#include <vector>
#include "stop.h"
#include "passenger.h"

class Taxi {
private:
    int capacity;
    int currentStop;
    int direction;
    std::vector<Passenger> passengers;
    int passengersEntered;
    int passengersExited;

public:
    Taxi(int capacity, int currentStop, int direction);

    void move(std::vector<Stop>& stops);
    void printStatus() const;
};

#endif // TAXI_H
