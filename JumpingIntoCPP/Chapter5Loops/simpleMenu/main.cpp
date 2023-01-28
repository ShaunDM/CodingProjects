/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 5 Loops
Problem 2
*/

#include <iostream>

using namespace std;

int main()
{
    int order = 0;
    string dish;
    cout << "Select one of the options from the following menu to order." << endl;
    while (order < 1 || order > 3)
    {
        cout << "1) Fish and Chips \n" "2) Eggs and Bacon \n" << "3) Steak and Potatoes" << endl;
        cin >> order;
        if (order < 1 || order > 3)
            cout << "Invalid order, please try again.\n";
        if (order == 1)
            dish = "Fish and Chips";
        if (order == 2)
            dish = "Eggs and Bacon";
        if (order == 3)
            dish = "Steak and Potatoes";
    }
    cout << "You have ordered: " << dish << endl << "Thank you for your patronage!" << endl;
    return 0;
}
