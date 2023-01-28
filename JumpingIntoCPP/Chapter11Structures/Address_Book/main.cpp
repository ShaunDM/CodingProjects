/*

Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 11 Structures
Problem 1

*/

#include <iostream>

using namespace std;

struct address
{

};

struct contactInfo
{
    string name;
    string line1;
    string line2;
    string town;
    string state;
    string zipCode;
    string phone;
};

int main()
{
    contactInfo contact;
    cout << "Contact information" << endl;
    cout << "Name: ";
    getline(cin, contact.name);
    cout << "Address Line 1: " << endl;
    getline(cin, contact.line1);
    cout << "Address Line 2: " << endl;
    getline(cin, contact.line2);
    cout << "Town: ";
    getline(cin, contact.town);
    cout << "State: ";
    getline(cin, contact.state);
    cout << "Zip Code: ";
    getline (cin, contact.zipCode);
    cout << "Phone #: ";
    cin >> contact.phone;
    cout << contact.name << endl;
    cout << contact.line1 << endl;
    cout << contact.line2 << endl;
    cout << contact.town << endl;
    cout << contact.state << endl;
    cout << contact.zipCode << endl;
    cout << contact.phone << endl;
    return 0;
}
