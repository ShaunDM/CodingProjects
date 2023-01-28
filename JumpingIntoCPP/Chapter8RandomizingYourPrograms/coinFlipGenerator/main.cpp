/*
Creator: Shaun McRae
Jumping into C++
Chapter 8 Randomizing your Programs
Problem 1
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int flip(string input)
{
    if (input == "0")
        return NULL;
    else
        return rand() % 2;
}
int main()
{
    int coin_flip, heads_counter = 0, tails_counter = 0;
    string result, input;
    srand (time(NULL));
    while (input != "0")
    {
    cin >> input;
    coin_flip = flip(input);
        if (coin_flip == 0)
        {
            result = "Heads";
            heads_counter++;
        }
        else if (coin_flip == 1)
        {
            result = "Tails";
            tails_counter++;
        }
        else
        {
            cout << heads_counter << endl;
            cout << tails_counter << endl;
            return 0;
        }
        cout << result << endl;
        cout << heads_counter << endl;
        cout << tails_counter << endl << endl;

    }
    return 0;
}
