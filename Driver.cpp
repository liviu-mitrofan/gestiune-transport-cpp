#include "Driver.h"
#include "ProjectUtils.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

Driver::Driver(const string& name, int userId)
    : Person(name), userId(userId) {}

int Driver::getId() const {
    return id;
}

string Driver::getName() const {
    return name;
}

void Driver::setName(const string& name) {
    this->name = reduce(name);
}

void Driver::displayDriverInfo() const {
    cout << "Driver ID: " << id << endl;
    cout << "Name: " << name << endl;
}

int Driver::getUserId() const {
    return userId;
}

void Driver::saveToFile(ofstream& outFile) const {
    outFile << id << "," << name << "," << userId << endl;
}

Driver Driver::loadFromFile(ifstream& inFile) {
    string line;
    if (!getline(inFile, line)) {
        throw runtime_error("Failed to read driver data from file.");
    }

    stringstream ss(line);
    string idStr, name, userIdStr;

    if (!getline(ss, idStr, ',') || !getline(ss, name, ',') || !getline(ss, userIdStr, ',')) {
        throw runtime_error("Failed to parse driver data from file.");
    }

    try {
        Driver driver(name, stoi(userIdStr));
        driver.id = stoi(idStr);
        return driver;
    } catch (invalid_argument& e) {
        throw runtime_error("Failed to parse driver data from file.");
    }
}

void Driver::printDriversTable(const vector<Driver>& drivers, int userId) {
    vector<string> headers = {"Id", "Name"};
    vector<function<string(const Driver&)>> extractors = {
        [](const Driver& driver) { return to_string(driver.getId()); },
        [](const Driver& driver) { return driver.getName(); }
    };

    printTable(drivers, userId, headers, extractors);
}
