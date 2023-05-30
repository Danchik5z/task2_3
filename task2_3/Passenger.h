#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
private:
    std::string name;
    int destination;

public:
    Passenger(const std::string& name, int destination);

    const std::string& getName() const;
    int getDestination() const;
};

#endif
