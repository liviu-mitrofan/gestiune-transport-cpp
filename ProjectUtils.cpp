#include "ProjectUtils.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>

using namespace std;

// Function definitions without default arguments in the cpp file
void printRedMessage(const string &message) {
    cout << "\033[1;31m" << message << "\033[0m" << endl;
}

void printYellowMessage(const string &message) {
    cout << "\033[1;33m" << message << "\033[0m" << endl;
}

void printGreenMessage(const string& message) {
    cout << "\033[1;32m" << message << "\033[0m" << endl;
}

void printBlueMessage(const string& message) {
    cout << "\033[1;34m" << message << "\033[0m" << endl;
}

bool isValidEmail(const string& email) {
    const regex pattern(R"((\w+)(\.|\-)?(\w*)@(\w+)(\.(\w+))+)");
    return regex_match(email, pattern);
}

bool isValidPassword(const string& password) {
    return !password.empty();
}

bool isValidCompanyName(const string& companyName) {
    return !companyName.empty();
}

bool isNotEmpty(const string& input) {
    return !input.empty() && input.find_first_not_of(' ') != string::npos;
}

bool isFileEmpty(const string& filename) {
    ifstream inFile(filename, ios::binary | ios::ate);
    return inFile.tellg() == 0;
}

bool isIntOrDouble(const string& s) {
    try {
        stod(s);
    } catch (...) {
        return false;
    }
    return true;
}

bool isPositiveInt(const string& s) {
    try {
        int num = stoi(s);
        if (num < 0) {
            return false;
        }
    } catch (...) {
        return false;
    }
    return true;
}

bool isPositiveDouble(const string& s) {
    try {
        double num = stod(s);
        if (num < 0) {
            return false;
        }
    } catch (...) {
        return false;
    }
    return true;
}

bool isPositiveNumber(const string& s) {
    return isPositiveInt(s) || isPositiveDouble(s);
}

string toLowerCase(const string& s) {
    string lowerCaseString = s;
    for (char &c : lowerCaseString) {
        c = tolower(c);
    }
    return lowerCaseString;
}

int randomInt() {
    return rand() % 9000 + 1000;
}

string trim(const string& str, const string& whitespace) {
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

string reduce(const string& str, const string& fill, const string& whitespace) {
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != string::npos) {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return toLowerCase(result);
}
/*
template<typename T>
void printTable(const vector<T>& items, int userId,
                           const vector<string>& headers,
                           const vector<function<string(const T&)>>& extractors) {
    // Print header
    cout << "-----------------------------------------------------------------\n";
    for (const auto& header : headers) {
        cout << "| " << setw(15) << header << " ";
    }
    cout << "|\n";
    cout << "-----------------------------------------------------------------\n";

    // Print rows
    for (const auto& item : items) {
        if (item.getUserId() != userId) {
            continue;
        }
        for (const auto& extractor : extractors) {
            cout << "| " << setw(15) << extractor(item) << " ";
        }
        cout << "|\n";
    }
    cout << "-----------------------------------------------------------------\n";
}

*/