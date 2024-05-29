#ifndef PROJECTUTILS_H
#define PROJECTUTILS_H

#include <functional>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>


using namespace std;

void printRedMessage(const string& message);
void printYellowMessage(const string& message);
void printGreenMessage(const string& message);
void printBlueMessage(const string& message);
bool isValidEmail(const string& email);
bool isValidPassword(const string& password);
bool isValidCompanyName(const string& companyName);
bool isNotEmpty(const string& input);
bool isFileEmpty(const string& filename);
bool isPositiveNumber(const string& s);
string toLowerCase(const string& s);
int randomInt();
string trim(const string& str, const string& whitespace = " \t");
string reduce(const string& str, const string& fill = "", const string& whitespace = " \t");

template<typename T>
void printTable(const vector<T>& items,int userId,
                const vector<string>& headers,
                const vector<function<string(const T&)>>& extractors) {
    const int columnWidth = 15;
    const int padding = 3;
    int totalWidth = (columnWidth + padding) * headers.size() + 1;

    string dashedLine(totalWidth, '-');

    cout << dashedLine << "\n";
    for (const auto& header : headers) {
        cout << "| " << setw(columnWidth) << header << " ";
    }
    cout << "|\n";
    cout << dashedLine << "\n";

    // Print rows
    for (const auto& item : items) {
        if (item.getUserId() != userId) {
            continue;
        }
        for (const auto& extractor : extractors) {
            cout << "| " << setw(columnWidth) << extractor(item) << " ";
        }
        cout << "|\n";
    }
    cout << dashedLine << "\n";
}

#endif //PROJECTUTILS_H
