// Invoice.h
#ifndef INVOICE_H
#define INVOICE_H

#include <string>
#include <vector>

using namespace std;

class Invoice {
private:
    static int nextId;
    int id;
    string invoiceNumber;
    double price;
    string supplier;
    string description;
    int userId;
public:
    Invoice(const string& invoiceNumber, double price, const string& supplier,
            const string& description, int userId);
    Invoice(): id(0), invoiceNumber(""), price(0.0), supplier(""), description(""), userId(0) {}
    // Getters
    int getId() const;
    string getInvoiceNumber() const;
    double getPrice() const;
    string getSupplier() const;
    string getDescription() const;

    // Setters
    void setInvoiceNumber(const string& invoiceNumber);
    void setPrice(double price);
    void setSupplier(const string& supplier);
    void setDescription(const string& description);

    // Other methods for invoice management
    void displayInvoiceInfo() const;
    int getUserId() const;
    void saveToFile(ofstream& outFile) const;
    static Invoice loadFromFile(ifstream& inFile);
    static void printInvoicesTable(const vector<Invoice>& invoices, int userId);
};

#endif // INVOICE_H
