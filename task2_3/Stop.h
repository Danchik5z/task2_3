#ifndef STOP_H
#define STOP_H

#include <iostream>
#include <vector>
#include "passenger.h"

class Stop {
private:
    int number;
    std::vector<Passenger> passengers;

public:
    Stop(int number);

    void addPassenger(const Passenger& passenger);
    void removePassenger(const Passenger& passenger);
    const std::vector<Passenger>& getPassengers() const;
};

#endif // STOP_H
