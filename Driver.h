// Driver.h
#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <vector>

#include "Person.h"

using namespace std;

class Driver : public Person{
private:
    int userId;
public:
    Driver(const string& name, int userId);
    Driver(): Person(), userId(0) {}

    // Getters
    int getId() const;
    string getName() const;

    // Setters
    void setName(const string& name);

    // Other methods for driver management
    void displayDriverInfo() const;
    int getUserId() const;
    void saveToFile(ofstream& outFile) const override;
    static Driver loadFromFile(ifstream& inFile);
    static void printDriversTable(const vector<Driver>& drivers, int userId);
};

#endif // DRIVER_H
