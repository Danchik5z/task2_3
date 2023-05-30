#include "stop.h"

Stop::Stop(int number) : number(number) {}

void Stop::addPassenger(const Passenger& passenger) {
    passengers.push_back(passenger);
    std::cout << "Passenger " << passenger.getName() << " added to stop " << number << std::endl;
}

void Stop::removePassenger(const Passenger& passenger) {
    for (auto it = passengers.begin(); it != passengers.end(); ++it) {
        if (it->getName() == passenger.getName()) {
            passengers.erase(it);
            std::cout << "Passenger " << passenger.getName() << " removed from stop " << number << std::endl;
            break;
        }
    }
}

const std::vector<Passenger>& Stop::getPassengers() const {
    return passengers;
}
