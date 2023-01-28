/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 5 Loops
Problem 1
*/

#include <iostream>

using namespace std;

int main()
{
    int beer = 99;
    for(int i = 0; i < 99; i++)
    {
        cout << beer << " bottles of beer on the wall, " << beer << " bottles of beer on the wall. " << endl;
        --beer;
        cout << "Take one down pass it around, "<< beer << " bottles of beer on the wall." << endl;
    }
    return 0;
}
