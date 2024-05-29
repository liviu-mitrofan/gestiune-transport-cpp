#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
protected:
    int id;
    string name;

public:
    Person(const string& name);
    Person() : id(0), name("") {}

    // Getters
    int getId() const;
    string getName() const;

    // Setters
    void setName(const string& name);

    virtual void displayInfo() const;
    virtual void saveToFile(ofstream& outFile) const = 0;
    static Person* loadFromFile(ifstream& inFile);
};



#endif //PERSON_H
