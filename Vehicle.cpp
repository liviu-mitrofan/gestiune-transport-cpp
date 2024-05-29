#include "Vehicle.h"
#include "ProjectUtils.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

int Vehicle::nextId = 1;

Vehicle::Vehicle(const string& vehicleNumber, int userId)
    : id(randomInt()), vehicleNumber(reduce(vehicleNumber)), userId(userId) {}

int Vehicle::getId() const {
    return id;
}

string Vehicle::getVehicleNumber() const {
    return vehicleNumber;
}

void Vehicle::setVehicleNumber(const string& vehicleNumber) {
    this->vehicleNumber = reduce(vehicleNumber);
}

void Vehicle::displayVehicleInfo() const {
    cout << "Vehicle ID: " << id << endl;
    cout << "Vehicle Number: " << vehicleNumber << endl;
}

int Vehicle::getUserId() const {
    return userId;
}

void Vehicle::saveToFile(ofstream& outFile) const {
    outFile << id << "," << vehicleNumber << "," << userId << endl;
}

Vehicle Vehicle::loadFromFile(ifstream& inFile) {
    string line;
    if (!getline(inFile, line)) {
        throw runtime_error("Failed to read vehicle data from file.");
    }

    stringstream ss(line);
    string idStr, vehicleNumber, userIdStr;

    if (!getline(ss, idStr, ',') || !getline(ss, vehicleNumber, ',') || !getline(ss, userIdStr, ',')) {
        throw runtime_error("Failed to parse vehicle data from file.");
    }

    try {
        Vehicle vehicle(vehicleNumber, stoi(userIdStr));
        vehicle.id = stoi(idStr);
        return vehicle;
    } catch (invalid_argument& e) {
        throw runtime_error("Failed to parse vehicle data from file.");
    }
}

void Vehicle::printVehiclesTable(const vector<Vehicle>& vehicles, int userId) {
    vector<string> headers = {"Id", "Name"};
    vector<function<string(const Vehicle&)>> extractors = {
        [](const Vehicle& vehicle) { return to_string(vehicle.getId()); },
        [](const Vehicle& vehicle) { return vehicle.getVehicleNumber(); }
    };

    printTable(vehicles, userId, headers, extractors);
}
