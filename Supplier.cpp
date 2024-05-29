#include "Supplier.h"
#include "ProjectUtils.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

int Supplier::nextId = 1;

Supplier::Supplier(const string& name, int userId)
    : id(randomInt()), name(reduce(name)), userId(userId) {}

int Supplier::getId() const {
    return id;
}

string Supplier::getName() const {
    return name;
}

void Supplier::setName(const string& name) {
    this->name = reduce(name);
}

void Supplier::displaySupplierInfo() const {
    cout << "Supplier ID: " << id << endl;
    cout << "Name: " << name << endl;
}

int Supplier::getUserId() const {
    return userId;
}

void Supplier::saveToFile(ofstream& outFile) const {
    outFile << id << "," << name << "," << userId << endl;
}

Supplier Supplier::loadFromFile(ifstream& inFile) {
    string line;
    if (!getline(inFile, line)) {
        throw runtime_error("Failed to read supplier data from file.");
    }

    stringstream ss(line);
    string idStr, name, userIdStr;

    if (!getline(ss, idStr, ',') || !getline(ss, name, ',') || !getline(ss, userIdStr, ',')) {
        throw runtime_error("Failed to parse supplier data from file.");
    }

    try {
        Supplier supplier(name, stoi(userIdStr));
        supplier.id = stoi(idStr);
        return supplier;
    } catch (invalid_argument& e) {
        throw runtime_error("Failed to parse supplier data from file.");
    }
}

void Supplier::printSuppliersTable(const vector<Supplier>& suppliers, int userId) {
    vector<string> headers = {"Id", "Name"};
    vector<function<string(const Supplier&)>> extractors = {
        [](const Supplier& supplier) { return to_string(supplier.getId()); },
        [](const Supplier& supplier) { return supplier.getName(); }
    };

    printTable(suppliers, userId, headers, extractors);
}
