/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 14, Dynamic Memory Allocation
Problem 3
*/

#include <iostream>

using namespace std;

int main()
{
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << &arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
