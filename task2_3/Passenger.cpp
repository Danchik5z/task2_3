#include "passenger.h"

Passenger::Passenger(const std::string& name, int destination)
    : name(name), destination(destination) {}

const std::string& Passenger::getName() const {
    return name;
}

int Passenger::getDestination() const {
    return destination;
}



