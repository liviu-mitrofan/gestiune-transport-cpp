// Supplier.h
#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <vector>

using namespace std;

class Supplier {
private:
    static int nextId;
    int id;
    string name;
    int userId;
public:
    Supplier(const string& name, int userId);
    Supplier(): id(0), name(""), userId(0) {}
    // Getters
    int getId() const;
    string getName() const;

    // Setters
    void setName(const string& name);

    // Other methods for supplier management
    void displaySupplierInfo() const;
    int getUserId() const;
    void saveToFile(ofstream& outFile) const;
    static Supplier loadFromFile(ifstream& inFile);
    static void printSuppliersTable(const vector<Supplier>& suppliers, int userId);
};

#endif // SUPPLIER_H
