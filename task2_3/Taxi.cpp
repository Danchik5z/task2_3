#include "taxi.h"

Taxi::Taxi(int capacity, int currentStop, int direction)
    : capacity(capacity), currentStop(currentStop), direction(direction), passengersEntered(0), passengersExited(0) {}

void Taxi::move(std::vector<Stop>& stops) {
    if (currentStop == 1)
        direction = 1;
    else if (currentStop == stops.size())
        direction = -1;

    currentStop += direction;

    std::cout << "Taxi moved to stop: " << currentStop << std::endl;

    Stop& currentStopObj = stops[currentStop - 1];

    // Unload passengers at the current stop
    for (auto it = passengers.begin(); it != passengers.end();) {
        if (it->getDestination() == currentStop) {
            std::cout << "Passenger " << it->getName() << " arrived at destination." << std::endl;
            it = passengers.erase(it);
            passengersExited++;
        } else {
            ++it;
        }
    }

    while (!currentStopObj.getPassengers().empty() && passengers.size() < capacity) {
        Passenger& passenger = const_cast<Passenger&>(currentStopObj.getPassengers()[0]);
        passengers.push_back(passenger);
        std::cout << "Passenger " << passenger.getName() << " boarded the taxi." << std::endl;
        currentStopObj.removePassenger(passenger);
        passengersEntered++;
    }
}

void Taxi::printStatus() const {
    std::cout << "Taxi Status:" << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Current Stop: " << currentStop << std::endl;
    std::cout << "Direction: " << direction << std::endl;
    std::cout << "Passengers Entered: " << passengersEntered << std::endl;
    std::cout << "Passengers Exited: " << passengersExited << std::endl;
    std::cout << "Passengers: ";
    for (const auto& passenger : passengers) {
        std::cout << passenger.getName() << " ";
    }
    std::cout << std::endl;
}
