/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 13, Using Pointers
Problem 4
*/

#include <iostream>

using namespace std;

multiSum (int a, int b, int *multiply)
{
    int sum;
    sum = a + b;
    *multiply = a * b;
    return sum;
}

int main()
{
    int a, b, sum, multiple, *pMultiple = &multiple;
    cout << "Enter two integers and I will give you their sum and multiple" << endl;
    cout << "First integer: ";
    cin >> a;
    cout << "Second integer: ";
    cin >> b;
    sum = multiSum(a, b, pMultiple);
    cout << "Adding the integers results in: " << sum << endl;
    cout << "Multiplying the integers results in: " << multiple << endl;
    return 0;
}
