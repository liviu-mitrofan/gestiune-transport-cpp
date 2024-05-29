#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <conio.h>
#include <limits>

#include "ProjectUtils.h"
#include "User.h"
#include "Order.h"
#include "Driver.h"
#include "Expense.h"
#include "Invoice.h"
#include "Supplier.h"
#include "Vehicle.h"

using namespace std;

const string FILENAME = "users.txt";
const string ORDERSFILE = "orders.txt";
const string INVOICESFILE = "invoices.txt";
const string EXPENSESFILE = "expenses.txt";
const string SUPPLIERSFILE = "suppliers.txt";
const string VEHICLESFILE = "vehicles.txt";
const string DRIVERSFILE = "drivers.txt";

vector<User> users;
vector<Order> orders;
vector<Invoice> invoices;
vector<Expense> expenses;
vector<Supplier> suppliers;
vector<Vehicle> vehicles;
vector<Driver> drivers;

// store current loggedin user
User loggedInUser;

fstream ordersFile("orders.txt", ios::in | ios::out | ios::app);
fstream usersFile("users.txt", ios::in | ios::out | ios::app);
fstream invoicesFile("invoices.txt", ios::in | ios::out | ios::app);
fstream expensesFile("expenses.txt", ios::in | ios::out | ios::app);
fstream suppliersFile("suppliers.txt", ios::in | ios::out | ios::app);
fstream vehiclesFile("vehicles.txt", ios::in | ios::out | ios::app);
fstream driversFile("drivers.txt", ios::in | ios::out | ios::app);


bool emailExists(const string& email) {
    for (const auto& user : users) {
        if (user.getEmail() == email) {
            return true;
        }
    }
    return false;
}


void loadUsersFromFile() {
    if (isFileEmpty(FILENAME)) {
        return;
    }

    ifstream inFile(FILENAME);
    if (!inFile.is_open()) {
        cerr << "Failed to open user file." << endl;
        return;
    }

    try {
        while (inFile.peek() != EOF) {
            User user = User::loadFromFile(inFile);
            users.push_back(user);
        }
    } catch (const runtime_error& e) {
        cerr << "Error loading users: " << e.what() << endl;
    }

    inFile.close();
}

void loadOrdersFromFile() {
    if (isFileEmpty(ORDERSFILE)) {
        return;
    }

    ifstream inFile(ORDERSFILE);
    if (!inFile.is_open()) {
        cerr << "Failed to open orders file." << endl;
        return;
    }

    try {
        while (inFile.peek() != EOF) {
            Order order = Order::loadFromFile(inFile);
            orders.push_back(order);
        }
    } catch (const runtime_error& e) {
        cerr << "Error loading orders: " << e.what() << endl;
    }

    inFile.close();
}

void loadInvoicesFromFile() {
    if (isFileEmpty(INVOICESFILE)) {
        return;
    }

    ifstream inFile(INVOICESFILE);
    if (!inFile.is_open()) {
        cerr << "Failed to open invoices file." << endl;
        return;
    }

    try {
        while (inFile.peek() != EOF) {
            Invoice invoice = Invoice::loadFromFile(inFile);
            invoices.push_back(invoice);
        }
    } catch (const runtime_error& e) {
        cerr << "Error loading invoices: " << e.what() << endl;
    }

    inFile.close();
}

void loadExpensesFromFile() {
    if (isFileEmpty(EXPENSESFILE)) {
        return;
    }

    ifstream inFile(EXPENSESFILE);
    if (!inFile.is_open()) {
        cerr << "Failed to open expenses file." << endl;
        return;
    }

    try {
        while (inFile.peek() != EOF) {
            Expense expense = Expense::loadFromFile(inFile);
            expenses.push_back(expense);
        }
    } catch (const runtime_error& e) {
        cerr << "Error loading expenses: " << e.what() << endl;
    }

    inFile.close();
}

void loadSuppliersFromFile() {
    if (isFileEmpty(SUPPLIERSFILE)) {
        return;
    }

    ifstream inFile(SUPPLIERSFILE);
    if (!inFile.is_open()) {
        cerr << "Failed to open suppliers file." << endl;
        return;
    }

    try {
        while (inFile.peek() != EOF) {
            Supplier supplier = Supplier::loadFromFile(inFile);
            suppliers.push_back(supplier);
        }
    } catch (const runtime_error& e) {
        cerr << "Error loading suppliers: " << e.what() << endl;
    }

    inFile.close();
}

void loadVehiclesFromFile() {
    if (isFileEmpty(VEHICLESFILE)) {
        return;
    }

    ifstream inFile(VEHICLESFILE);
    if (!inFile.is_open()) {
        cerr << "Failed to open vehicles file." << endl;
        return;
    }

    try {
        while (inFile.peek() != EOF) {
            Vehicle vehicle = Vehicle::loadFromFile(inFile);
            vehicles.push_back(vehicle);
        }
    } catch (const runtime_error& e) {
        cerr << "Error loading vehicles: " << e.what() << endl;
    }

    inFile.close();
}

void loadDriversFromFile() {
    if (isFileEmpty(DRIVERSFILE)) {
        return;
    }

    ifstream inFile(DRIVERSFILE);
    if (!inFile.is_open()) {
        cerr << "Failed to open drivers file." << endl;
        return;
    }

    try {
        while (inFile.peek() != EOF) {
            Driver driver = Driver::loadFromFile(inFile);
            drivers.push_back(driver);
        }
    } catch (const runtime_error& e) {
        cerr << "Error loading drivers: " << e.what() << endl;
    }

    inFile.close();
}



void saveUsersToFile() {
    ofstream outFile(FILENAME);
    for (const auto& user : users) {
        user.saveToFile(outFile);
    }
    outFile.close();
}

void saveOrdersToFile() {
    ofstream outFile(ORDERSFILE);
    for (const auto& order : orders) {
        order.saveToFile(outFile);
    }
    outFile.close();
}

void saveInvoicesToFile() {
    ofstream outFile(INVOICESFILE);
    for (const auto& invoice : invoices) {
        invoice.saveToFile(outFile);
    }
    outFile.close();
}

void saveExpensesToFile() {
    ofstream outFile(EXPENSESFILE);
    for (const auto& expense : expenses) {
        expense.saveToFile(outFile);
    }
    outFile.close();
}

void saveSuppliersToFile() {
    ofstream outFile(SUPPLIERSFILE);
    for (const auto& supplier : suppliers) {
        supplier.saveToFile(outFile);
    }
    outFile.close();
}

void saveVehiclesToFile() {
    ofstream outFile(VEHICLESFILE);
    for (const auto& vehicle : vehicles) {
        vehicle.saveToFile(outFile);
    }
    outFile.close();
}

void saveDriversToFile() {
    ofstream outFile(DRIVERSFILE);
    for (const auto& driver : drivers) {
        driver.saveToFile(outFile);
    }
    outFile.close();
}

void registerUser() {
    string email, password, companyName;

    cout << "Register" << endl;
    cout << "--------\n" << endl;

    do {
        cout << "Enter email: ";
        cin >> email;
        if (!isValidEmail(email)) {
            cout << "Invalid email format. Try again." << endl;
        } else if (emailExists(email)) {
            cout << "Email already exists. Try again." << endl;
        } else {
            break;
        }
    } while (true);

    do {
        cout << "Enter password: ";
        cin >> password;
        if (!isValidPassword(password)) {
            cout << "Password must be at least 6 characters long. Try again." << endl;
        } else {
            break;
        }
    } while (true);

    cin.ignore(); // To clear the newline character from the buffer
    do {
        cout << "Enter company name: ";
        getline(cin, companyName);
        if (!isValidCompanyName(companyName)) {
            cout << "Company name must contain spaces and at least two words. Try again." << endl;
        } else {
            break;
        }
    } while (true);

    User newUser(email, password, companyName);
    users.push_back(newUser);

    ofstream outFile(FILENAME, ios::app);
    newUser.saveToFile(outFile);
    outFile.close();

    cout << "Registration successful!" << endl;
}

bool loginUser()
{
    string email, password;

    cout << "Login" << endl;
    cout << "-----\n" << endl;

    do {
        cout << "Enter email: ";
        cin >> email;
        if (!isValidEmail(email)) {
            cout << "Invalid email format. Try again." << endl;
        } else {
            break;
        }
    } while (true);

    do {
        cout << "Enter password: ";
        cin >> password;
        if (!isValidPassword(password)) {
            cout << "Password must be at least 6 characters long. Try again." << endl;
        } else {
            break;
        }
    } while (true);

    for (const auto& user : users) {
        if (user.getEmail() == email && user.getPassword() == password) {
            user.displayUserInfo();
            loggedInUser = user;
            return true;
        }
    }
    return false;
}

int main() {
    try {
        loadUsersFromFile();
        loadOrdersFromFile();
        loadInvoicesFromFile();
        loadExpensesFromFile();
        loadSuppliersFromFile();
        loadVehiclesFromFile();
        loadDriversFromFile();
        int choice;
        do {
            cout << "1. Register" << endl;
            cout << "2. Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            // validate if choice is integer
            if (cin.fail()) {
                system("cls");
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Try again." << endl;
                continue;
            }
            switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    system("cls");
                    printYellowMessage("Login successful!");
                    int loggedInChoice;
                    do {
                        cout << "\nDashboard actions:" << endl;
                        cout << "1. Profile" << endl;
                        cout << "2. Orders" << endl;
                        cout << "3. Invoices" << endl;
                        cout << "4. Expenses" << endl;
                        cout << "5. Suppliers" << endl;
                        cout << "6. Vehicles" << endl;
                        cout << "7. Drivers" << endl;
                        cout << "8. Logout" << endl;
                        cout << "Enter action: ";
                        cin >> loggedInChoice;

                        Order newOrder;
                        Invoice newInvoice;
                        Expense newExpense;
                        Supplier newSupplier;
                        Vehicle newVehicle;
                        Driver newDriver;
                        // Declare these variables before the switch statement
                        string newPassword;
                        string newCompanyName;

                        string inputPrice;

                        //for orders
                        string orderNumber;
                        double price;
                        string supplier;
                        string vehicle;
                        string description;
                        string findorderNumber;

                        // for invoices
                        bool orderExists = true;
                        string invoiceNumber;
                        double invoicePrice;
                        string invoiceSupplier;
                        string invoiceDescription;
                        string findInvoiceNumber;

                        // for expenses
                        string expenseNumber;
                        double expensePrice;
                        string expenseSupplier;
                        string expenseDescription;
                        string findExpenseNumber;

                        // for suppliers
                        string supplierName;
                        string findSupplierName;

                        // for vehicles
                        string vehicleNumber;
                        string findVehicleNumber;

                        // for drivers
                        string driverName;
                        string findDriverName;

                        switch (loggedInChoice) {
                        case 1:
                            system("cls");
                            printBlueMessage("Profile\n");
                            loggedInUser.displayUserInfo();
                            int profileChoice;
                            do {
                                cout << "\n1. Change password" << endl;
                                cout << "2. Change company name" << endl;
                                cout << "3. Go back to dashboard" << endl;
                                cout << "Enter action: ";
                                cin >> profileChoice;
                                switch (profileChoice) {
                                case 1:
                                    system("cls");
                                    printBlueMessage("Change password");
                                    cout << "Enter new password (leave blank to keep the current password): ";
                                    cin.ignore();
                                    getline(cin, newPassword);

                                    // If the new password is empty, retain the current password
                                    if (newPassword.empty()) {
                                        newPassword = loggedInUser.getPassword();
                                    }

                                    for (auto& user : users) {
                                        if (user.getEmail() == loggedInUser.getEmail()) {
                                            user.setPassword(newPassword);
                                            loggedInUser = user;
                                            break;
                                        }
                                    }
                                    saveUsersToFile();
                                    printGreenMessage("Password changed successfully!");
                                    break;
                                case 2:
                                    system("cls");
                                    printBlueMessage("Change company name\n");
                                    cin.ignore();
                                    // Show the current company name
                                    cout << "Current company name: " << loggedInUser.getCompanyName() << endl;

                                    // Ask for new company name
                                    cout << "Enter new company name (leave blank to keep the current name): ";
                                    getline(cin, newCompanyName);

                                    // If the new company name is empty, retain the current company name
                                    if (newCompanyName.empty()) {
                                        newCompanyName = loggedInUser.getCompanyName();
                                    }

                                    for (auto& user : users) {
                                        if (user.getEmail() == loggedInUser.getEmail()) {
                                            user.setCompanyName(newCompanyName);
                                            loggedInUser = user;
                                            break;
                                        }
                                    }
                                    saveUsersToFile();
                                    printGreenMessage("Company name changed successfully!");
                                    break;
                                case 3:
                                    system("cls");
                                    break;
                                default:
                                    system("cls");
                                    cout << "Invalid choice. Try again." << endl;
                                }
                            } while (profileChoice != 3);
                            break;
                        case 2:
                            system("cls");
                            printBlueMessage("ORDERS");
                            int orderChoice;
                            do {
                                cout << "\n1. Add order" << endl;
                                cout << "2. View all orders" << endl;
                                cout << "3. Edit order" << endl;
                                cout << "4. Delete order" << endl;
                                cout << "5. Go back to dashboard" << endl;
                                cout << "Enter action: ";
                                cin >> orderChoice;
                                switch (orderChoice) {
                                case 1:
                                    system("cls");
                                    printBlueMessage("Add order\n\n");
                                    printBlueMessage("Suppliers\n");
                                    Supplier::printSuppliersTable(suppliers, loggedInUser.getId());
                                    printBlueMessage("Vehicles\n");
                                    Vehicle::printVehiclesTable(vehicles, loggedInUser.getId());

                                    cin.ignore();
                                        do {
                                            cout << "Enter order number: ";
                                            getline(cin, orderNumber);
                                            if (orderNumber.empty()) {
                                                cout << "Order number cannot be empty. Try again." << endl;
                                            }
                                            // check if order number already exists
                                            for (const auto& order : orders) {
                                                if (order.getOrderNumber() == reduce(orderNumber) && order.getUserId() == loggedInUser.getId()) {
                                                    cout << "Order number already exists. Try again." << endl;
                                                    orderNumber.clear();
                                                    break;
                                                }
                                            }
                                        } while (!isNotEmpty(orderNumber));

                                        do {
                                            cout << "Enter price: ";
                                            getline(cin, inputPrice);
                                            if (!isPositiveNumber(inputPrice)) {
                                                cout << "Price must be a positive number. Try again: ";
                                            }
                                        } while (!isPositiveNumber(inputPrice));
                                        price = stod(inputPrice);

                                        do {
                                            cout << "Enter supplier from list: ";
                                            getline(cin, supplier);
                                            if (supplier.empty()) {
                                                cout << "Supplier cannot be empty. Try again." << endl;
                                            }
                                        } while (!isNotEmpty(supplier));

                                        orderExists = false;
                                        // check if supplier entered exists
                                        do {
                                            orderExists = false;
                                            for (const auto& supplier1 : suppliers) {
                                                if (supplier1.getName() == reduce(supplier) && supplier1.getUserId() == loggedInUser.getId()) {
                                                    orderExists = true;
                                                    break;
                                                }
                                            }
                                            if (!orderExists) {
                                                cout << "Supplier does not exist. Try again: ";
                                                getline(cin, supplier);
                                            }
                                        } while (!orderExists);

                                        do {
                                            cout << "Enter vehicle: ";

                                            getline(cin, vehicle);
                                            if (vehicle.empty()) {
                                                cout << "Vehicle cannot be empty. Try again." << endl;
                                            }
                                        } while (!isNotEmpty(vehicle));

                                        orderExists = false;
                                        // check if vehicle entered exists
                                        do {
                                            orderExists = false;
                                            for (const auto& vehicle1 : vehicles) {
                                                if (vehicle1.getVehicleNumber() == reduce(vehicle) && vehicle1.getUserId() == loggedInUser.getId()) {
                                                    orderExists = true;
                                                    break;
                                                }
                                            }
                                            if (!orderExists) {
                                                cout << "Vehicle does not exist. Try again: ";
                                                getline(cin, vehicle);
                                            }
                                        } while (!orderExists);

                                        do {
                                            cout << "Enter description: ";

                                            getline(cin, description);
                                            if (description.empty()) {
                                                cout << "Description cannot be empty. Try again." << endl;
                                            }
                                        } while (!isNotEmpty(description));


                                        newOrder = Order(orderNumber, price, supplier, vehicle, description, loggedInUser.getId());
                                        orders.push_back(newOrder);
                                        saveOrdersToFile();
                                        printGreenMessage("Order added successfully!");

                                    break;
                                case 2:
                                    system("cls");
                                    printBlueMessage("View orders\n");
                                    Order::printOrdersTable(orders, loggedInUser.getId());
                                    break;
                                case 3:
                                    system("cls");
                                    printBlueMessage("Edit order\n");
                                    Order::printOrdersTable(orders, loggedInUser.getId());

                                    cin.ignore();
                                    cout << "Enter order number to edit (leave blank to cancel): ";
                                    getline(cin, findorderNumber);

                                    if (findorderNumber.empty()) {
                                        break;
                                    }

                                    orderExists = false;

                                    do {
                                        orderExists = false;
                                        for (const auto& order : orders) {
                                            if (order.getOrderNumber() == reduce(findorderNumber)) {
                                                orderExists = true;
                                                break;
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Order number does not exist. Try again: ";
                                            getline(cin, findorderNumber);
                                            if (findorderNumber.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto& order : orders) {
                                        if (order.getOrderNumber() == findorderNumber) {
                                            order.displayOrderInfo();
                                            cout << "\nEnter new price (leave blank to keep the current price): ";
                                            string newPriceStr;
                                            getline(cin, newPriceStr);
                                            cin.ignore();
                                            if (!newPriceStr.empty()) {
                                                double newPrice = stod(newPriceStr);
                                                order.setPrice(newPrice);
                                            }

                                            cout << "Enter new supplier (leave blank to keep the current supplier): ";


                                            getline(cin, supplier);
                                            if (!supplier.empty()) {
                                                order.setSupplier(supplier);
                                            }

                                            orderExists = false;
                                            // check if supplier entered exists
                                            do {
                                                orderExists = false;
                                                for (const auto& supplier1 : suppliers) {
                                                    if (supplier1.getName() == reduce(supplier) && supplier1.getUserId() == loggedInUser.getId()) {
                                                        orderExists = true;
                                                        break;
                                                    }
                                                }
                                                if (!orderExists) {
                                                    cout << "Supplier does not exist. Try again: ";
                                                    getline(cin, supplier);
                                                    if (supplier.empty()) {
                                                        break;
                                                    }
                                                }
                                            } while (!orderExists);

                                            cout << "Enter new vehicle (leave blank to keep the current vehicle): ";

                                            getline(cin, vehicle);
                                            if (!vehicle.empty()) {
                                                order.setVehicle(vehicle);
                                            }

                                            orderExists = false;
                                            // check if vehicle entered exists
                                            do {
                                                orderExists = false;
                                                for (const auto& vehicle1 : vehicles) {
                                                    if (vehicle1.getVehicleNumber() == reduce(vehicle) && vehicle1.getUserId() == loggedInUser.getId()) {
                                                        orderExists = true;
                                                        break;
                                                    }
                                                }
                                                if (!orderExists) {
                                                    cout << "Vehicle does not exist. Try again: ";
                                                    getline(cin, vehicle);
                                                    if (vehicle.empty()) {
                                                        break;
                                                    }
                                                }
                                            } while (!orderExists);

                                            cout << "Enter new description (leave blank to keep the current description): ";

                                            getline(cin, description);
                                            if (!description.empty()) {
                                                order.setDescription(description);
                                            }

                                            saveOrdersToFile();
                                            break;
                                        }
                                    }
                                    break;
                                case 4:
                                    system("cls");
                                    printBlueMessage("Delete order\n");
                                    Order::printOrdersTable(orders, loggedInUser.getId());

                                    cout << "Enter order number to delete (leave blank to cancel): ";
                                    cin.ignore();
                                    getline(cin, findorderNumber);
                                    if (findorderNumber.empty()) {
                                        break;
                                    }
                                    orderExists = false;

                                    do {
                                        orderExists = false;  // Reset the flag at the start of each loop iteration
                                        for (const auto& order : orders) {
                                            if (order.getOrderNumber() == reduce(findorderNumber)) {
                                                orderExists = true;
                                                break;  // Exit the loop early since the order number is found
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Order number does not exist. Try again: ";
                                            getline(cin, findorderNumber);
                                            if (findorderNumber.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto it = orders.begin(); it != orders.end(); ++it) {
                                        if (it->getOrderNumber() == findorderNumber) {
                                            orders.erase(it);
                                            saveOrdersToFile();
                                            printGreenMessage("Order deleted successfully!");
                                            break;
                                        }
                                    }
                                    break;
                                case 5:
                                    system("cls");
                                    break;
                                default:
                                    system("cls");
                                    cout << "Invalid choice. Try again." << endl;
                                }
                            } while (orderChoice != 5);
                            break;
                        case 3:
                            system("cls");
                            printBlueMessage("INVOICES");
                            int invoiceChoice;

                            do {
                                cout << "\n1. Add invoice" << endl;
                                cout << "2. View all invoices" << endl;
                                cout << "3. Edit invoice" << endl;
                                cout << "4. Delete invoice" << endl;
                                cout << "5. Go back to dashboard" << endl;
                                cout << "Enter action: ";
                                cin >> invoiceChoice;
                                switch (invoiceChoice) {
                                case 1:
                                    system("cls");
                                    printBlueMessage("Add invoice\n");
                                    do {
                                        cout << "Enter invoice number: ";
                                        cin.ignore();
                                        getline(cin, invoiceNumber);
                                        if (invoiceNumber.empty()) {
                                            cout << "Invoice number cannot be empty. Try again." << endl;
                                        }
                                        for (const auto& invoice : invoices) {
                                            if (invoice.getInvoiceNumber() == reduce(invoiceNumber) && invoice.getUserId() == loggedInUser.getId()) {
                                                cout << "Invoice number already exists. Try again." << endl;
                                                invoiceNumber.clear();
                                                break;
                                            }
                                        }
                                    } while (!isNotEmpty(invoiceNumber));

                                    do {
                                        cout << "Enter price: ";
                                        getline(cin, inputPrice);
                                        if (!isPositiveNumber(inputPrice)) {
                                            cout << "Price must be a positive number. Try again: ";
                                        }
                                    } while (!isPositiveNumber(inputPrice));
                                    invoicePrice = stod(inputPrice);

                                    do {
                                        cout << "Enter supplier: ";
                                        cin.ignore();
                                        getline(cin, invoiceSupplier);
                                        if (invoiceSupplier.empty()) {
                                            cout << "Supplier cannot be empty. Try again." << endl;
                                        }
                                    } while (!isNotEmpty(invoiceSupplier));

                                    do {
                                        cout << "Enter description: ";
                                        cin.ignore();
                                        getline(cin, invoiceDescription);
                                        if (invoiceDescription.empty()) {
                                            cout << "Description cannot be empty. Try again." << endl;
                                        }
                                    } while (!isNotEmpty(invoiceDescription));

                                    newInvoice = Invoice(invoiceNumber, invoicePrice, invoiceSupplier, invoiceDescription, loggedInUser.getId());
                                    invoices.push_back(newInvoice);
                                    saveInvoicesToFile();
                                    printGreenMessage("Invoice added successfully!");
                                case 2:
                                    system("cls");
                                    printBlueMessage("View all invoices\n");
                                    Invoice::printInvoicesTable(invoices, loggedInUser.getId());
                                    break;
                                case 3:
                                    system("cls");
                                    printBlueMessage("Edit invoice\n");
                                    Invoice::printInvoicesTable(invoices, loggedInUser.getId());

                                    cout << "Enter invoice number to edit (leave blank to cancel): ";
                                    cin.ignore();
                                    getline(cin, findInvoiceNumber);
                                    if (findInvoiceNumber.empty()) {
                                        break;
                                    }
                                    orderExists = false;
                                    do {
                                        orderExists = false;  // Reset the flag at the start of each loop iteration
                                        for (const auto& invoice : invoices) {
                                            if (invoice.getInvoiceNumber() == reduce(findInvoiceNumber)) {
                                                orderExists = true;
                                                break;  // Exit the loop early since the order number is found
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Invoice number does not exist. Try again: ";
                                            getline(cin, findInvoiceNumber);
                                            if (findInvoiceNumber.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto& invoice : invoices) {
                                        if (invoice.getInvoiceNumber() == findInvoiceNumber) {
                                            invoice.displayInvoiceInfo();
                                            cout << "\nEnter new price (leave blank to keep the current price): ";
                                            cin.ignore();
                                            string newPriceStr;
                                            getline(cin, newPriceStr);
                                            if (!newPriceStr.empty()) {
                                                double newPrice = stod(newPriceStr);
                                                invoice.setPrice(newPrice);
                                            }

                                            cout << "Enter new supplier (leave blank to keep the current supplier): ";

                                            getline(cin, invoiceSupplier);
                                            if (!invoiceSupplier.empty()) {
                                                invoice.setSupplier(invoiceSupplier);
                                            }

                                            cout << "Enter new description (leave blank to keep the current description): ";

                                            getline(cin, invoiceDescription);
                                            if (!invoiceDescription.empty()) {
                                                invoice.setDescription(invoiceDescription);
                                            }

                                            saveInvoicesToFile();
                                            break;
                                        }
                                    }
                                    break;
                                case 4:
                                    system("cls");
                                    printBlueMessage("Delete invoice\n");
                                    Invoice::printInvoicesTable(invoices, loggedInUser.getId());

                                    cout << "Enter invoice number to delete (leave blank to cancel): ";
                                    cin.ignore();
                                    getline(cin, findInvoiceNumber);
                                    if (findInvoiceNumber.empty()) {
                                        break;
                                    }
                                    orderExists = false;
                                    do {
                                        orderExists = false;
                                        for (const auto& invoice : invoices) {
                                            if (invoice.getInvoiceNumber() == reduce(findInvoiceNumber)) {
                                                orderExists = true;
                                                break;
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Invoice number does not exist. Try again: ";
                                            getline(cin, findInvoiceNumber);
                                            if (findInvoiceNumber.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);

                                    for (auto it = invoices.begin(); it != invoices.end(); ++it) {
                                        if (it->getInvoiceNumber() == findInvoiceNumber) {
                                            invoices.erase(it);
                                            saveInvoicesToFile();
                                            printGreenMessage("Invoice deleted successfully!");
                                            break;
                                        }
                                    }

                                    break;
                                case 5:
                                    system("cls");
                                    break;
                                default:
                                    system("cls");
                                    cout << "Invalid choice. Try again." << endl;
                                }
                            } while (invoiceChoice != 5);
                            break;
                        case 4:
                            system("cls");
                            // same as above
                            printBlueMessage("EXPENSES");
                            int expenseChoice;

                            do {
                                cout << "\n1. Add expense" << endl;
                                cout << "2. View all expenses" << endl;
                                cout << "3. Edit expense" << endl;
                                cout << "4. Delete expense" << endl;
                                cout << "5. Go back to dashboard" << endl;
                                cout << "Enter action: ";
                                cin >> expenseChoice;
                                switch (expenseChoice) {
                                case 1:
                                    system("cls");
                                    printBlueMessage("Add expense\n");
                                    cin.ignore();
                                    do {
                                        cout << "Enter expense number: ";
                                        getline(cin, expenseNumber);
                                        if (expenseNumber.empty()) {
                                            cout << "Expense number cannot be empty. Try again." << endl;
                                        }
                                        for (const auto& expense : expenses) {
                                            if (expense.getExpenseNumber() == reduce(expenseNumber) && expense.getUserId() == loggedInUser.getId()) {
                                                cout << "Expense number already exists. Try again." << endl;
                                                expenseNumber.clear();
                                                break;
                                            }
                                        }
                                    } while (!isNotEmpty(expenseNumber));

                                    do {
                                        cout << "Enter price: ";
                                        getline(cin, inputPrice);
                                        if (!isPositiveNumber(inputPrice)) {
                                            cout << "Price must be a positive number. Try again: ";
                                        }
                                    } while (!isPositiveNumber(inputPrice));
                                    expensePrice = stod(inputPrice);

                                    do {
                                        cout << "Enter supplier: ";
                                        getline(cin, expenseSupplier);
                                        if (expenseSupplier.empty()) {
                                            cout << "Supplier cannot be empty. Try again." << endl;
                                        }
                                    } while (!isNotEmpty(expenseSupplier));

                                    do {
                                        cout << "Enter description: ";
                                        getline(cin, expenseDescription);
                                        if (expenseDescription.empty()) {
                                            cout << "Description cannot be empty. Try again." << endl;
                                        }
                                    } while (!isNotEmpty(expenseDescription));

                                    newExpense = Expense(expenseNumber, expensePrice, expenseSupplier, expenseDescription, loggedInUser.getId());
                                    expenses.push_back(newExpense);
                                    saveExpensesToFile();
                                    printGreenMessage("Expense added successfully!");
                                case 2:
                                    system("cls");
                                    printBlueMessage("View all expenses\n");
                                    Expense::printExpensesTable(expenses, loggedInUser.getId());
                                    break;
                                case 3:
                                    system("cls");
                                    printBlueMessage("Edit expense\n");
                                    Expense::printExpensesTable(expenses, loggedInUser.getId());

                                    cout << "Enter expense number to edit (leave blank to cancel): ";
                                    cin.ignore();
                                    getline(cin, findExpenseNumber);
                                    if (findExpenseNumber.empty()) {
                                        break;
                                    }
                                    orderExists = false;
                                    do {
                                        orderExists = false;
                                        for (const auto& expense : expenses) {
                                            if (expense.getExpenseNumber() == reduce(findExpenseNumber)) {
                                                orderExists = true;
                                                break;
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Expense number does not exist. Try again: ";
                                            getline(cin, findExpenseNumber);
                                            if (findExpenseNumber.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto& expense : expenses) {
                                        if (expense.getExpenseNumber() == findExpenseNumber) {
                                            expense.displayExpenseInfo();
                                            cout << "\nEnter new price (leave blank to keep the current price): ";
                                            string newPriceStr;
                                            getline(cin, newPriceStr);
                                            if (!newPriceStr.empty()) {
                                                double newPrice = stod(newPriceStr);
                                                expense.setPrice(newPrice);
                                            }

                                            cout << "Enter new supplier (leave blank to keep the current supplier): ";

                                            getline(cin, expenseSupplier);
                                            if (!expenseSupplier.empty()) {
                                                expense.setSupplier(expenseSupplier);
                                            }

                                            cout << "Enter new description (leave blank to keep the current description): ";

                                            getline(cin, expenseDescription);
                                            if (!expenseDescription.empty()) {
                                                expense.setDescription(expenseDescription);
                                            }

                                            saveExpensesToFile();
                                            break;
                                        }
                                    }
                                    break;
                                case 4:
                                    system("cls");
                                    printBlueMessage("Delete expense\n");
                                    Expense::printExpensesTable(expenses, loggedInUser.getId());

                                    cout << "Enter expense number to delete (leave blank to cancel): ";
                                    cin.ignore();
                                    getline(cin, findExpenseNumber);
                                    if (findExpenseNumber.empty()) {
                                        break;
                                    }
                                    orderExists = false;
                                    do {
                                        orderExists = false;
                                        for (const auto& expense : expenses) {
                                            if (expense.getExpenseNumber() == reduce(findExpenseNumber)) {
                                                orderExists = true;
                                                break;
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Expense number does not exist. Try again: ";
                                            getline(cin, findExpenseNumber);
                                            if (findExpenseNumber.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto it = expenses.begin(); it != expenses.end(); ++it) {
                                        if (it->getExpenseNumber() == findExpenseNumber) {
                                            expenses.erase(it);
                                            saveExpensesToFile();
                                            printGreenMessage("Expense deleted successfully!");
                                            break;
                                        }
                                    }

                                    break;
                                case 5:
                                    system("cls");
                                    break;
                                default:
                                    system("cls");
                                    cout << "Invalid choice. Try again." << endl;
                                }
                            } while (expenseChoice != 5);

                            break;
                        case 5:
                            system("cls");
                            // same way as above
                            printBlueMessage("SUPPLIERS");
                            int supplierChoice;

                            do {
                                cout << "\n1. Add supplier" << endl;
                                cout << "2. View all suppliers" << endl;
                                cout << "3. Edit supplier" << endl;
                                cout << "4. Delete supplier" << endl;
                                cout << "5. Go back to dashboard" << endl;
                                cout << "Enter action: ";
                                cin >> supplierChoice;
                                switch (supplierChoice) {
                                case 1:
                                    system("cls");
                                    printBlueMessage("Add supplier\n");
                                    cin.ignore();

                                    do {
                                        cout << "Enter supplier name: ";
                                        getline(cin, supplierName);
                                        if (supplierName.empty()) {
                                            cout << "Supplier name cannot be empty. Try again." << endl;
                                        }
                                        for (const auto& supplier1 : suppliers) {
                                            if (supplier1.getName() == reduce(supplierName) && supplier1.getUserId() == loggedInUser.getId()) {
                                                cout << "Supplier name already exists. Try again." << endl;
                                                supplierName.clear();
                                                break;
                                            }
                                        }
                                    } while (!isNotEmpty(supplierName));

                                    newSupplier = Supplier(supplierName, loggedInUser.getId());
                                    suppliers.push_back(newSupplier);
                                    saveSuppliersToFile();
                                    printGreenMessage("Supplier added successfully!");

                                case 2:
                                    system("cls");
                                    printBlueMessage("View all suppliers\n");
                                    Supplier::printSuppliersTable(suppliers, loggedInUser.getId());
                                    break;
                                case 3:
                                    system("cls");
                                    printBlueMessage("Edit supplier\n");
                                    Supplier::printSuppliersTable(suppliers, loggedInUser.getId());

                                    cout << "Enter supplier name to edit (leave blank to cancel): ";
                                    cin.ignore();
                                    getline(cin, findSupplierName);
                                    if (findSupplierName.empty()) {
                                        break;
                                    }
                                    orderExists = false;
                                    do {
                                        orderExists = false;
                                        for (const auto& supplier1 : suppliers) {
                                            if (supplier1.getName() == reduce(findSupplierName) && supplier1.getUserId() == loggedInUser.getId()) {
                                                orderExists = true;
                                                break;
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Supplier name does not exist. Try again: ";
                                            getline(cin, findSupplierName);
                                            if (findSupplierName.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto& supplier1 : suppliers) {
                                        if (supplier1.getName() == findSupplierName) {
                                            supplier1.displaySupplierInfo();
                                            cout << "\nEnter new supplier name (leave blank to keep the current name): ";
                                            getline(cin, newCompanyName);
                                            if (!newCompanyName.empty()) {
                                                supplier1.setName(newCompanyName);
                                            }

                                            saveSuppliersToFile();
                                            break;
                                        }
                                    }
                                    break;
                                case 4:
                                    system("cls");
                                    printBlueMessage("Delete supplier\n");
                                    Supplier::printSuppliersTable(suppliers, loggedInUser.getId());

                                    cin.ignore();
                                    cout << "Enter supplier name to delete (leave blank to cancel): ";
                                    getline(cin, findSupplierName);

                                    if (findSupplierName.empty()) {
                                        break;
                                    }
                                    orderExists = false;
                                    do {
                                        orderExists = false;
                                        for (const auto& supplier1 : suppliers) {
                                            if (supplier1.getName() == reduce(findSupplierName) && supplier1.getUserId() == loggedInUser.getId()) {
                                                orderExists = true;
                                                break;
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Supplier name does not exist. Try again: ";
                                            getline(cin, findSupplierName);
                                            if (findSupplierName.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto it = suppliers.begin(); it != suppliers.end(); ++it) {
                                        if (it->getName() == findSupplierName) {
                                            suppliers.erase(it);
                                            saveSuppliersToFile();
                                            printGreenMessage("Supplier deleted successfully!");
                                            break;
                                        }
                                    }
                                    break;
                                case 5:
                                    system("cls");
                                    break;
                                default:
                                    system("cls");
                                    cout << "Invalid choice. Try again." << endl;
                                }
                            } while (supplierChoice != 5);
                            break;
                        case 6:
                            system("cls");
                            printBlueMessage("VEHICLES");

                            int vehicleChoice;

                            do {
                                cout << "\n1. Add vehicle" << endl;
                                cout << "2. View all vehicles" << endl;
                                cout << "3. Edit vehicle" << endl;
                                cout << "4. Delete vehicle" << endl;
                                cout << "5. Go back to dashboard" << endl;
                                cout << "Enter action: ";
                                cin >> vehicleChoice;
                                switch (vehicleChoice) {
                                case 1:
                                    system("cls");
                                    printBlueMessage("Add vehicle\n");
                                    cin.ignore();
                                    do {
                                        cout << "Enter vehicle number: ";
                                        getline(cin, vehicleNumber);
                                        if (vehicleNumber.empty()) {
                                            cout << "Vehicle number cannot be empty. Try again." << endl;
                                        }
                                        for (const auto& vehicle1 : vehicles) {
                                            if (vehicle1.getVehicleNumber() == reduce(vehicleNumber) && vehicle1.getUserId() == loggedInUser.getId()) {
                                                cout << "Vehicle number already exists. Try again." << endl;
                                                vehicleNumber.clear();
                                                break;
                                            }
                                        }
                                    } while (!isNotEmpty(vehicleNumber));

                                    newVehicle = Vehicle(vehicleNumber, loggedInUser.getId());
                                    vehicles.push_back(newVehicle);
                                    saveVehiclesToFile();
                                    printGreenMessage("Vehicle added successfully!");
                                case 2:
                                    system("cls");
                                    printBlueMessage("View all vehicles\n");
                                    Vehicle::printVehiclesTable(vehicles, loggedInUser.getId());
                                    break;
                                case 3:
                                    system("cls");
                                    printBlueMessage("Edit vehicle\n");
                                    Vehicle::printVehiclesTable(vehicles, loggedInUser.getId());
                                    cin.ignore();
                                    cout << "Enter vehicle number to edit (leave blank to cancel): ";
                                    getline(cin, findVehicleNumber);
                                    if (findVehicleNumber.empty()) {
                                        break;
                                    }
                                    orderExists = false;
                                    do {
                                        orderExists = false;
                                        for (const auto& vehicle1 : vehicles) {
                                            if (vehicle1.getVehicleNumber() == reduce(findVehicleNumber) && vehicle1.getUserId() == loggedInUser.getId()) {
                                                orderExists = true;
                                                break;
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Vehicle number does not exist. Try again: ";
                                            getline(cin, findVehicleNumber);
                                            if (findVehicleNumber.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto& vehicle1 : vehicles) {
                                        if (vehicle1.getVehicleNumber() == reduce(findVehicleNumber)) {
                                            vehicle1.displayVehicleInfo();
                                            cout << "\nEnter new vehicle number (leave blank to keep the current number): ";
                                            getline(cin, newCompanyName);
                                            if (!newCompanyName.empty()) {
                                                vehicle1.setVehicleNumber(newCompanyName);
                                            }

                                            saveVehiclesToFile();
                                            break;
                                        }
                                    }
                                    break;
                                case 4:
                                    system("cls");
                                    printBlueMessage("Delete vehicle\n");
                                    Vehicle::printVehiclesTable(vehicles, loggedInUser.getId());
                                    cin.ignore();
                                    cout << "Enter vehicle number to delete (leave blank to cancel): ";
                                    getline(cin, findVehicleNumber);
                                    if (findVehicleNumber.empty()) {
                                        break;
                                    }
                                    orderExists = false;
                                    do {
                                        orderExists = false;
                                        for (const auto& vehicle1 : vehicles) {
                                            if (vehicle1.getVehicleNumber() == reduce(findVehicleNumber) && vehicle1.getUserId() == loggedInUser.getId()) {
                                                orderExists = true;
                                                break;
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Vehicle number does not exist. Try again: ";
                                            getline(cin, findVehicleNumber);
                                            if (findVehicleNumber.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
                                        if (it->getVehicleNumber() == findVehicleNumber) {
                                            vehicles.erase(it);
                                            saveVehiclesToFile();
                                            printGreenMessage("Vehicle deleted successfully!");
                                            break;
                                        }
                                    }
                                    break;
                                case 5:
                                    system("cls");
                                    break;
                                default:
                                    system("cls");
                                    cout << "Invalid choice. Try again." << endl;
                                }
                            } while (vehicleChoice != 5);
                            break;
                        case 7:
                            system("cls");
                            printBlueMessage("DRIVERS");
                            int driverChoice;

                            do {
                                cout << "\n1. Add driver" << endl;
                                cout << "2. View all drivers" << endl;
                                cout << "3. Edit driver" << endl;
                                cout << "4. Delete driver" << endl;
                                cout << "5. Go back to dashboard" << endl;
                                cout << "Enter action: ";
                                cin >> driverChoice;
                                switch (driverChoice) {
                                case 1:
                                    system("cls");
                                    printBlueMessage("Add driver\n");
                                    cin.ignore();
                                    do {
                                        cout << "Enter driver name: ";
                                        getline(cin, driverName);
                                        if (driverName.empty()) {
                                            cout << "Driver name cannot be empty. Try again." << endl;
                                        }
                                        for (const auto& driver : drivers) {
                                            if (driver.getName() == reduce(driverName) && driver.getUserId() == loggedInUser.getId()) {
                                                cout << "Driver name already exists. Try again." << endl;
                                                driverName.clear();
                                                break;
                                            }
                                        }
                                    } while (!isNotEmpty(driverName));

                                    newDriver = Driver(driverName, loggedInUser.getId());
                                    drivers.push_back(newDriver);
                                    saveDriversToFile();
                                    printGreenMessage("Driver added successfully!");
                                case 2:
                                    system("cls");
                                    printBlueMessage("View all drivers\n");
                                    Driver::printDriversTable(drivers, loggedInUser.getId());
                                    break;
                                case 3:
                                    system("cls");
                                    printBlueMessage("Edit driver\n");
                                    Driver::printDriversTable(drivers, loggedInUser.getId());
                                    cin.ignore();
                                    cout << "Enter driver name to edit (leave blank to cancel): ";
                                    getline(cin, findDriverName);
                                    if (findDriverName.empty()) {
                                        break;
                                    }
                                    orderExists = false;
                                    do {
                                        orderExists = false;
                                        for (const auto& driver : drivers) {
                                            if (driver.getName() == reduce(findDriverName) && driver.getUserId() == loggedInUser.getId()) {
                                                orderExists = true;
                                                break;
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Driver name does not exist. Try again: ";
                                            getline(cin, findDriverName);
                                            if (findDriverName.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto& driver : drivers) {
                                        if (driver.getName() == reduce(findDriverName)) {
                                            driver.displayDriverInfo();
                                            cout << "\nEnter new driver name (leave blank to keep the current name): ";
                                            getline(cin, newCompanyName);
                                            if (!newCompanyName.empty()) {
                                                driver.setName(newCompanyName);
                                            }

                                            saveDriversToFile();
                                            break;
                                        }
                                    }
                                    break;
                                case 4:
                                    system("cls");
                                    printBlueMessage("Delete driver\n");
                                    Driver::printDriversTable(drivers, loggedInUser.getId());
                                    cin.ignore();
                                    cout << "Enter driver name to delete (leave blank to cancel): ";
                                    getline(cin, findDriverName);
                                    if (findDriverName.empty()) {
                                        break;
                                    }
                                    orderExists = false;
                                    do {
                                        orderExists = false;
                                        for (const auto& driver : drivers) {
                                            if (driver.getName() == reduce(findDriverName) && driver.getUserId() == loggedInUser.getId()) {
                                                orderExists = true;
                                                break;
                                            }
                                        }
                                        if (!orderExists) {
                                            cout << "Driver name does not exist. Try again: ";
                                            getline(cin, findDriverName);
                                            if (findDriverName.empty()) {
                                                break;
                                            }
                                        }
                                    } while (!orderExists);
                                    for (auto it = drivers.begin(); it != drivers.end(); ++it) {
                                        if (it->getName() == findDriverName) {
                                            drivers.erase(it);
                                            saveDriversToFile();
                                            printGreenMessage("Driver deleted successfully!");
                                            break;
                                        }
                                    }
                                    break;
                                case 5:
                                    system("cls");
                                    break;
                                default:
                                    system("cls");
                                    cout << "Invalid choice. Try again." << endl;
                                }
                            } while (driverChoice != 5);
                            break;
                        case 8:
                            system("cls");
                            saveUsersToFile();
                            saveOrdersToFile();
                            saveInvoicesToFile();
                            saveExpensesToFile();
                            saveSuppliersToFile();
                            saveVehiclesToFile();
                            saveDriversToFile();
                            loggedInUser = User();
                            break;
                        default:
                            system("cls");
                            cout << "Invalid choice. Try again." << endl;
                        }
                    } while (loggedInChoice != 8);
                } else {
                    cout << "Login failed! Invalid email or password" << endl;
                }
                break;
            case 3:
                saveUsersToFile();
                saveOrdersToFile();
                saveInvoicesToFile();
                saveExpensesToFile();
                saveSuppliersToFile();
                saveVehiclesToFile();
                saveDriversToFile();
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != 3);

        return 0;
    } catch (const exception& e) {
        cerr << e.what() << '\n';
        return -1;
    }
}


