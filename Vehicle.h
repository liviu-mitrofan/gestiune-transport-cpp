// Vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>

using namespace std;

class Vehicle {
private:
    static int nextId;
    int id;
    string vehicleNumber;
    int userId;
public:
    Vehicle(const string& vehicleNumber, int userId);
    Vehicle(): id(0), vehicleNumber(""), userId(0) {}
    // Getters
    int getId() const;
    string getVehicleNumber() const;

    // Setters
    void setVehicleNumber(const string& vehicleNumber);

    // Other methods for vehicle management
    void displayVehicleInfo() const;
    int getUserId() const;
    void saveToFile(ofstream& outFile) const;
    static Vehicle loadFromFile(ifstream& inFile);
    static void printVehiclesTable(const vector<Vehicle>& vehicles, int userId);
};

#endif // VEHICLE_H
