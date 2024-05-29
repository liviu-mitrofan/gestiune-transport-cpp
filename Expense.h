// Expense.h
#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <vector>

using namespace std;

class Expense {
private:
    static int nextId;
    int id;
    string expenseNumber;
    double price;
    string supplier;
    string description;
    int userId;
public:
    Expense(const string& expenseNumber, double price, const string& supplier,
            const string& description, int userId);
    Expense(): id(0), expenseNumber(""), price(0.0), supplier(""), description(""), userId(0) {}
    // Getters
    int getId() const;
    string getExpenseNumber() const;
    double getPrice() const;
    string getSupplier() const;
    string getDescription() const;

    // Setters
    void setExpenseNumber(const string& expenseNumber);
    void setPrice(double price);
    void setSupplier(const string& supplier);
    void setDescription(const string& description);

    // Other methods for expense management
    void displayExpenseInfo() const;
    int getUserId() const;
    void saveToFile(ofstream& outFile) const;
    static Expense loadFromFile(ifstream& inFile);
    static void printExpensesTable(const vector<Expense>& expenses, int userId);
};

#endif // EXPENSE_H
