/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 6 Functions
Problem 2
*/

#include <iostream>

using namespace std;

int add(int total, int number)
{
    total += number;
    return total;
}
int subtract(int total, int number)
{
    total-= number;
    return total;
}
int multiply(int total, int number)
{
    total *= number;
    return total;
}
int divide(int total, int number)
{
    total /= number;
    return total;
}
int exponential(int total, int number)
{
    if (number > 0)
        for (int i = number; i > 1; i--)
            total *= total;
    if (number < 0)
        for (int i = number; i < 0; i++)
            total /= total;

    return total;
}
int main()
{
    cout << "Calculator 2.0, enter the number you would like to operate on/with for a running total. When finished enter 0 at any time." << endl;
    int total, number;
    cin >> number;
    total = number;
    char op;
    while (number != 0 || op != '0')
    {
        cout << "Enter operator" << endl;
        cin >> op;
        if (op == '0')
            break;
        cout << "Enter operating number" << endl;
        cin >> number;
        if (number == 0)
            break;
        else if (op == '+')
            total = add(total, number);
        else if (op == '-')
            total = subtract(total, number);
        else if (op == '*')
            total = multiply(total, number);
        else if (op == '/')
            total = divide(total, number);
        else if (op == '^')
            total = exponential(total, number);
        else
            cout << "Invalid operator, try again" << endl;
        cout << "Total: " << total << endl;

    }
    cout << "The final total is: " << total;

    return 0;
}
