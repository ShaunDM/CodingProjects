/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 6 Functions
Problem 1
*/

#include <iostream>

using namespace std;

void sum(void)
{
    cout << "Input the first number of the running sum, when finished enter 0." << endl;
    int number, total = 0;
    while (number != 0)
    {
       cin >> number;
       if(number == 0)
            continue;
       total += number;
       cout << "The total is: " << total << endl;
       cout << "Input the next number." << endl;
    }
    cout << "The final total is: " << total << endl;
}
void bottles_beer(void)
{
    int bottles = 99;
    for(int i = bottles; i != 0; i--)
    {
        cout << i << " bottles of beer on the wall. " << i << " bottles of beer on the wall." << endl;
        cout << "Take one down, pass it around. " << i - 1 << " bottles of beer on the wall." << endl;
    }
}
void square(void)
{
    int number;
    cout << "Input a number and I will square it." << endl;
    cin >> number;
    cout << number << "squared is: " << number * number << endl;
}
int main()
{
    cout << "This program has various functions, input the appropriate number to execute them. " << endl;
    cout << "When finished enter 0." << endl;
    cout << "1) sum an undefined amount of numbers" << endl;
    cout << "2) sing 99 bottles of beer" << endl;
    cout << "3) square a number" << endl;
    int input = -1;
    while (input != 0)
    {
        cout << "Input the function number you would like to execute: ";
        cin >> input;
        if (input == 1)
            sum();
        else if (input == 2)
            bottles_beer();
        else if (input == 3)
            square();
        else if (input == 0)
            return 0;
        else
            cout << "Invalid Entry" << endl;
    }
}
