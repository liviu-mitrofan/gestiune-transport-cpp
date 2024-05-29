// Order.h
#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

using namespace std;

class Order {
private:
    static int nextId;
    int id;
    string orderNumber;
    double price;
    string supplier;
    string vehicle;
    string description;
    int userId;
public:
    Order(const string& orderNumber, double price, const string& supplier,
          const string& vehicle, const string& description, int userId);
    Order() : id(0) {}

    // Getters
    int getId() const;
    string getOrderNumber() const;
    double getPrice() const;
    string getSupplier() const;
    string getVehicle() const;
    string getDescription() const;
    int getUserId() const;

    // Setters
    void setOrderNumber(const string& orderNumber);
    void setPrice(double price);
    void setSupplier(const string& supplier);
    void setVehicle(const string& vehicle);
    void setDescription(const string& description);

    // Other methods for order management
    void displayOrderInfo() const;
    void saveToFile(ofstream& outFile) const;
    static Order loadFromFile(ifstream& inFile);
    static void printOrdersTable(const vector<Order>& orders, int userId);
};

#endif // ORDER_H
