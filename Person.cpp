#include "Person.h"
#include "ProjectUtils.h"

#include <iostream>
#include <fstream>

using namespace std;

Person::Person(const string& name) : id(randomInt()), name(name) {}

int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::displayInfo() const {
    cout << "ID: " << id << ", Name: " << name << endl;
}
