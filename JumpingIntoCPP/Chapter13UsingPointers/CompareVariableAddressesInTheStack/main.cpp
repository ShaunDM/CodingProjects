/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 13, Using Pointers
Problem 5
*/

#include <iostream>

using namespace std;

stackAddressSort()
{
    int a, b;
    if (&a < &b)
    {
        cout << "Address of a: " << &a << endl;
        cout << "Address of b: " << &b << endl;
    }
    else
    {
        cout << "Address of b: " << &b << endl;
        cout << "Address of a: " << &a << endl;
    }

}

int main()
{
    cout << "Hello world!" << endl;
    stackAddresses();
    return 0;
}
