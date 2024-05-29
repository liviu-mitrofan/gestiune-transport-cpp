#include "Order.h"
#include "ProjectUtils.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

int Order::nextId = 1;

Order::Order(const string& orderNumber, double price, const string& supplier,
          const string& vehicle, const string& description, int userId)
    : id(randomInt()), orderNumber(reduce(orderNumber)), price(price), supplier(reduce(supplier)),
      vehicle(reduce(vehicle)), description(reduce(description)), userId(userId) {}

int Order::getId() const {
    return id;
}

string Order::getOrderNumber() const {
    return orderNumber;
}

double Order::getPrice() const {
    return price;
}

string Order::getSupplier() const {
    return supplier;
}

string Order::getVehicle() const {
    return vehicle;
}

string Order::getDescription() const {
    return description;
}

int Order::getUserId() const {
    return userId;
}

void Order::setOrderNumber(const string& orderNumber) {
    this->orderNumber = reduce(orderNumber);
}

void Order::setPrice(double price) {
    this->price = price;
}

void Order::setSupplier(const string& supplier) {
    this->supplier = reduce(supplier);
}

void Order::setVehicle(const string& vehicle) {
    this->vehicle = reduce(vehicle);
}

void Order::setDescription(const string& description) {
    this->description = reduce(description, " ");
}

void Order::displayOrderInfo() const {
    cout << "Order ID: " << id << endl;
    cout << "Order Number: " << orderNumber << endl;
    cout << "Price: $" << price << endl;
    cout << "Supplier: " << supplier << endl;
    cout << "Vehicle: " << vehicle << endl;
    cout << "Description: " << description << endl;
}

void Order::saveToFile(ofstream& outFile) const {
    outFile << id << "," << orderNumber << "," << price << "," << supplier << "," << vehicle << "," << description << "," << userId << endl;
}

Order Order::loadFromFile(ifstream& inFile) {
    string line;
    if (!getline(inFile, line)) {
        throw runtime_error("Failed to read order data from file.");
    }

    stringstream ss(line);
    string idStr, orderNumber, priceStr, supplier, vehicle, description, userIdStr;

    if (!getline(ss, idStr, ',') || !getline(ss, orderNumber, ',') || !getline(ss, priceStr, ',') ||
        !getline(ss, supplier, ',') || !getline(ss, vehicle, ',') || !getline(ss, description, ',') || !getline(ss, userIdStr, ',')) {
        throw runtime_error("Failed to parse order data from file.");
    }

    try {
        Order order(orderNumber, stod(priceStr), supplier, vehicle, description, stoi(userIdStr));
        order.id = stoi(idStr);
        return order;
    } catch (invalid_argument& e) {
        throw runtime_error("Failed to parse order data from file.");
    }
}

void Order::printOrdersTable(const vector<Order>& orders, int userId) {
    vector<string> headers = {"Id", "Order Number", "Price", "Supplier", "Vehicle", "Description"};
    vector<function<string(const Order&)>> extractors = {
        [](const Order& order) { return to_string(order.getId()); },
        [](const Order& order) { return order.getOrderNumber(); },
        [](const Order& order) { return to_string(order.getPrice()); },
        [](const Order& order) { return order.getSupplier(); },
        [](const Order& order) { return order.getVehicle(); },
        [](const Order& order) { return order.getDescription(); }
    };

    printTable(orders, userId, headers, extractors);
}
