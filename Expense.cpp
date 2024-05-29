#include "Expense.h"
#include "ProjectUtils.h"


#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>


using namespace std;

int Expense::nextId = 1;

Expense::Expense(const string& expenseNumber, double price, const string& supplier,
            const string& description, int userId)
    : id(randomInt()), expenseNumber(reduce(expenseNumber)), price(price), supplier(reduce(supplier)),
      description(reduce(description)), userId(userId) {}

int Expense::getId() const {
    return id;
}

string Expense::getExpenseNumber() const {
    return expenseNumber;
}

double Expense::getPrice() const {
    return price;
}

string Expense::getSupplier() const {
    return supplier;
}

string Expense::getDescription() const {
    return description;
}

void Expense::setExpenseNumber(const string& expenseNumber) {
    this->expenseNumber = reduce(expenseNumber);
}

void Expense::setPrice(double price) {
    this->price = price;
}

void Expense::setSupplier(const string& supplier) {
    this->supplier = reduce(supplier);
}

void Expense::setDescription(const string& description) {
    this->description = reduce(description, " ");
}

void Expense::displayExpenseInfo() const {
    cout << "Expense ID: " << id << endl;
    cout << "Expense Number: " << expenseNumber << endl;
    cout << "Price: $" << price << endl;
    cout << "Supplier: " << supplier << endl;
    cout << "Description: " << description << endl;
}

int Expense::getUserId() const {
    return userId;
}

void Expense::saveToFile(ofstream& outFile) const
{
    outFile << id << "," << expenseNumber << "," << price << "," << supplier << "," << description << "," << userId << endl;
}

Expense Expense::loadFromFile(ifstream& inFile)
{
    string line;
    if (!getline(inFile, line)) {
        throw runtime_error("Failed to read expense data from file.");
    }

    stringstream ss(line);
    string idStr, expenseNumber, priceStr, supplier, description, userIdStr;

    if (!getline(ss, idStr, ',') || !getline(ss, expenseNumber, ',') || !getline(ss, priceStr, ',') ||
        !getline(ss, supplier, ',') || !getline(ss, description, ',') || !getline(ss, userIdStr, ',')) {
        throw runtime_error("Failed to parse expense data from file.");
    }

    try {
        Expense expense(expenseNumber, stod(priceStr), supplier, description, stoi(userIdStr));
        expense.id = stoi(idStr);
        return expense;
    } catch (invalid_argument& e) {
        throw runtime_error("Failed to parse expense data from file.");
    }
}

void Expense::printExpensesTable(const vector<Expense>& expenses, const int userId)
{
    vector<string> headers = {"Id", "Expense Number", "Price", "Supplier", "Description"};
    vector<function<string(const Expense&)>> extractors = {
        [](const Expense& expense) { return to_string(expense.getId()); },
        [](const Expense& expense) { return expense.getExpenseNumber(); },
        [](const Expense& expense) { return to_string(expense.getPrice()); },
        [](const Expense& expense) { return expense.getSupplier(); },
        [](const Expense& expense) { return expense.getDescription(); }
    };

    printTable(expenses, userId, headers, extractors);
}
