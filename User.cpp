// User.cpp
#include "User.h"
#include "ProjectUtils.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


User::User(const string& email, const string& password, const string& companyName)
    : Person(email), email(reduce(email)), password(reduce(password)), companyName(reduce(companyName)) {}

int User::getId() const {
    return id;
}

string User::getEmail() const {
    return email;
}

string User::getPassword() const {
    return password;
}

string User::getCompanyName() const {
    return companyName;
}

void User::setEmail(const string& email) {
    this->email = reduce(email);
}

void User::setPassword(const string& password) {
    this->password = reduce(password);
}

void User::setCompanyName(const string& companyName) {
    this->companyName = reduce(companyName);
}

void User::displayUserInfo() const {
    cout << "User ID: " << id << endl;
    cout << "Email: " << email << endl;
    cout << "Company Name: " << companyName << endl << endl;
}

void User::saveToFile(ofstream& outFile) const {
    outFile << id << "," << email << "," << password << "," << companyName << endl;
}

User User::loadFromFile(ifstream& inFile) {
    string line;
    if (!getline(inFile, line)) {
        throw runtime_error("Failed to read user data from file.");
    }

    stringstream ss(line);
    string idStr, email, password, companyName;

    if (!getline(ss, idStr, ',') || !getline(ss, email, ',') || !getline(ss, password, ',') || !getline(ss, companyName, ',')) {
        throw runtime_error("Failed to parse user data from file.");
    }

    try {
        User user(email, password, companyName);
        user.id = stoi(idStr);
        return user;
    } catch (const invalid_argument& e) {
        throw runtime_error("Invalid user ID format in file.");
    }
}

void User::serialize(ofstream& outFile) const {
    outFile.write(reinterpret_cast<const char*>(this), sizeof(*this));
}

void User::deserialize(ifstream& inFile) {
    inFile.read(reinterpret_cast<char*>(this), sizeof(*this));
}