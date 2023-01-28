/*

Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 13 Using Pointers
Problem 1, 3

*/
#include <iostream>
#include <string>

using namespace std;

string inputName (string *p)
{
    string firstName;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> *p;
    cout << endl;
    return firstName;
}

string inputName (string &r)
{
    string firstName;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> r;
    cout << endl;
    return firstName;
}

string inputName ()
{
    string firstName;
    cout << "First Name: ";
    cin >> firstName;
    cout << endl;
    return firstName;
}

int main()
{
    string lastName, *pLastName = NULL, firstName;
    if (pLastName == NULL)
    {
        pLastName = &lastName;
        firstName = inputName(pLastName);
    }

    else
        firstName = inputName();

    cout << "Name: " << firstName << " " << lastName << endl << endl;

    string &rlast = lastName;
    firstName = inputName(&rlast);
    cout << "Name: " << firstName << " " << lastName << endl << endl;

    return 0;
}
