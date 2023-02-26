/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 14, Dynamic Memory Allocation
Problem 2
*/

#include <iostream>
// try using only a single pointer and initializing the new pointers created.
//need to add comments with problem number and chapter above, also fix save point in folders
using namespace std;

intitialize3DArray (int ***table, int a, int b, int c)
{

    table = new int **[a];
    for (int i = 0; i < a; i++)
    {
        table[i] = new int *[b];
        for (int j = 0; j < b; j++)
        {
            table[i][j] = new int [c];
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                table[i][j][k] = (i + 1) * (j + 1) * (k + 1);
                cout << table [i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    for (int j = 0; j < b; j++)
    {
        for (int k = 0; k < c; k++)
        {
            delete [] table [j][k];
        }
        delete [] table [j];
    }
    delete [] table;
}

int main()
{
    int height, width, length, ***pppHeight = NULL;
    cout << "Welcome to 3D multiplication table!" << endl;
    cout << "Please enter the dimensions of the table you would like to create." << endl;
    cout << "Height: ";
    cin >> height;
    cout << "Width: ";
    cin >> width;
    cout << "Length: ";
    cin >> length;
    intitialize3DArray (pppHeight, height, width, length);
    return 0;
}
