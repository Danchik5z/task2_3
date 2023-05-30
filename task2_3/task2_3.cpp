#include <iostream>
#include <vector>
#include "taxi.h"
#include "stop.h"
#include "passenger.h"

int main() {
    std::vector<Stop> stops;
    stops.emplace_back(1);
    stops.emplace_back(2);
    stops.emplace_back(3);
    stops.emplace_back(4);

    Taxi taxi(3, 1, 1);

    int choice = 0;
    while (true) {
        std::cout << "1. Add passenger to stop" << std::endl;
        std::cout << "2. Remove passenger from stop" << std::endl;
        std::cout << "3. Move taxi" << std::endl;
        std::cout << "4. Print taxi status" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
                std::string name;
                int destination;
                std::cout << "Enter passenger name: ";
                std::cin >> name;
                std::cout << "Enter passenger destination: ";
                std::cin >> destination;
                Passenger newPassenger(name, destination);
                stops[0].addPassenger(newPassenger);
                break;
        }
        case 2: {
                std::string name;
                std::cout << "Enter passenger name to remove: ";
                std::cin >> name;
                Passenger passenger(name, 0);
                stops[0].removePassenger(passenger);
                break;
        }
        case 3:
            taxi.move(stops);
            break;
        case 4:
            taxi.printStatus();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
        }
    }
}
