#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int * assignArray(int x, int *y)
{
    int *newY = new int [x];
    for (int i = 0; i < x/2; i++)
    {
        newY [i] = y [i];
    }
    delete [] y;
    return newY;
}


int main()
{
    int *pAddressBook = new int [5], sizeArray = 10;
    for (int i = 0; i < 5; i++)
    {
        pAddressBook[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << pAddressBook[i] << endl;
    }
    pAddressBook = assignArray (sizeArray, pAddressBook);
    for (int i = 5; i < sizeArray; i++)
    {
        pAddressBook[i] = i;
    }
    for (int i = 0; i < sizeArray; i++)
    {
        cout << pAddressBook[i] << endl;
    }

    return 0;
}
