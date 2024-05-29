#include "Invoice.h"
#include "ProjectUtils.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

int Invoice::nextId = 1;

Invoice::Invoice(const string& invoiceNumber, double price, const string& supplier,
            const string& description, int userId)
    : id(randomInt()), invoiceNumber(invoiceNumber), price(price), supplier(supplier),
      description(description), userId(userId) {}

int Invoice::getId() const {
    return id;
}

string Invoice::getInvoiceNumber() const {
    return invoiceNumber;
}

double Invoice::getPrice() const {
    return price;;
}

string Invoice::getSupplier() const {
    return supplier;
}

string Invoice::getDescription() const {
    return description;
}

void Invoice::setInvoiceNumber(const string& invoiceNumber) {
    this->invoiceNumber = reduce(invoiceNumber);
}

void Invoice::setPrice(double price) {
    this->price = price;
}

void Invoice::setSupplier(const string& supplier) {
    this->supplier = reduce(supplier);
}

void Invoice::setDescription(const string& description) {
    this->description = reduce(description, " ");
}

void Invoice::displayInvoiceInfo() const {
    cout << "Invoice ID: " << id << endl;
    cout << "Invoice Number: " << invoiceNumber << endl;
    cout << "Price: $" << price << endl;
    cout << "Supplier: " << supplier << endl;
    cout << "Description: " << description << endl;
}

int Invoice::getUserId() const {
    return userId;
}



void Invoice::saveToFile(ofstream& outFile) const
{
    outFile << id << "," << invoiceNumber << "," << price << "," << supplier << "," << description << "," << userId << endl;
}

Invoice Invoice::loadFromFile(ifstream& inFile)
{
    string line;
    if (!getline(inFile, line)) {
        throw runtime_error("Failed to read invoice data from file.");
    }

    stringstream ss(line);
    string idStr, invoiceNumber, priceStr, supplier, description, userIdStr;

    if (!getline(ss, idStr, ',') || !getline(ss, invoiceNumber, ',') || !getline(ss, priceStr, ',') ||
        !getline(ss, supplier, ',') || !getline(ss, description, ',') || !getline(ss, userIdStr, ',')) {
        throw runtime_error("Failed to parse invoice data from file.");
    }

    try {
        Invoice invoice(invoiceNumber, stod(priceStr), supplier, description, stoi(userIdStr));
        invoice.id = stoi(idStr);
        return invoice;
    } catch (invalid_argument& e) {
        throw runtime_error("Failed to parse invoice data from file.");
    }
}

void Invoice::printInvoicesTable(const vector<Invoice>& invoices, int userId)
{
    vector<string> headers = {"Id", "Invoice Number", "Price", "Supplier", "Description"};
    vector<function<string(const Invoice&)>> extractors = {
        [](const Invoice& invoice) { return to_string(invoice.getId()); },
        [](const Invoice& invoice) { return invoice.getInvoiceNumber(); },
        [](const Invoice& invoice) { return to_string(invoice.getPrice()); },
        [](const Invoice& invoice) { return invoice.getSupplier(); },
        [](const Invoice& invoice) { return invoice.getDescription(); }
    };

    printTable(invoices, userId, headers, extractors);
}
