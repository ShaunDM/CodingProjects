/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 14, Dynamic Memory Allocation
Problem 1
*/

#include <iostream>

using namespace std;

int main()
{
    int width, height;
    cout << "Welcome to the multiplication table app, create a multiplication for the size you wish." << endl;
    cout << "Please input the number of columns you would like your table to have." << endl;
    cout << "Columns: ";
    cin >> width;
    cout << "Please input the number of rows you would like your table to have." << endl;
    cout << "Rows: ";
    cin >> height;
    int multiplicationTable[height][width];
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            multiplicationTable[i][j]= i * j;
            cout << multiplicationTable[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
