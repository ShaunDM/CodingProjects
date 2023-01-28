/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 5 Loops
Problem 3
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter any number of integers to sum and I will sum them. When finished enter '0'." << endl;
    int number, sum = 0;
    cout << "Please enter the first number." << endl;
    do
    {
        cin >> number;
        sum += number;
        if (number == 0)
            break;
        cout << "You have entered: " << number << endl << "The sum is now: " << sum << endl;
        cout << "Please enter the next number." << endl;
    }   while (number != 0);
    cout << "The final sum is: " << sum << endl;
    return 0;
}
