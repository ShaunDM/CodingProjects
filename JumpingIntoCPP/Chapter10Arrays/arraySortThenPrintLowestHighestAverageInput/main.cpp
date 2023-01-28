/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 10 Arrays
Problem 2
*/

#include <iostream>

using namespace std;

int sort_array(int i, int j)
{
    i = j;
    return i;
}

int main()
{
    int arraySize;
    cout << "Please input the number of integers you would like to sort and I will register the highest, lowest, and average value and then print the sorted list." << endl;
    cin >> arraySize;
    while (arraySize < 1)
    {
        cout << "Invalid entry. Please try again." << endl;
        cin >> arraySize;
    }
    int anArray [arraySize];
    for (int i = 0; i < arraySize; i++)
    {
       cout << "Please input integer #" << i + 1 << ": ";
       cin >> anArray [i];
    }
    for (int i = 0; i < arraySize; i++)
    {
        int balast = 0;
        for (int j = 0; j < arraySize - 1; j++)
        {
            if (anArray [j] > anArray [j + 1])
            {
                int aux = anArray [j];
                anArray [j] = sort_array (anArray [j], anArray [j + 1]);
                anArray [j + 1] = aux;
                balast++;
            }
        }
        if (balast == 0)
            break;
    }
    int sum = 0;
    float average;
    for (int i = 0; i < arraySize; i++)
    {
        sum += anArray [i];
    }
    average = sum/arraySize;
    cout << "Highest value: " << anArray[arraySize - 1] << endl;
    cout << "Lowest value: " << anArray [0] << endl;
    cout << "Average: " << average << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout <<"Input #" << i+1 << ": " << anArray [i] << endl;
    }
    return 0;
}
