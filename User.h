#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include "Person.h"

using namespace std;

class User : public Person {
private:
    string email;
    string password;
    string companyName;

public:
    User(const string& email, const string& password, const string& companyName);
    User() {}

    // Getters
    int getId() const;
    string getEmail() const;
    string getPassword() const;
    string getCompanyName() const;

    // Setters
    void setEmail(const string& email);
    void setPassword(const string& password);
    void setCompanyName(const string& companyName);

    // Other methods for user management
    void displayUserInfo() const;
    void saveToFile(ofstream& outFile) const override;
    static User loadFromFile(ifstream& inFile);
    void serialize(ofstream& outFile) const;
    void deserialize(ifstream& inFile);

};

#endif // USER_H_INCLUDED
