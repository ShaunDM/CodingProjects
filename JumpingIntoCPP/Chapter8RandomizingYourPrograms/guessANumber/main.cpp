/*
Creator: Shaun McRae
Jumping into C++
Chapter 8 Randomizing your Programs
Problem 2, 3
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int picking_number()
{
    return rand() % (101);
}

int game (int number, int counter)
{
    int highest = 100, lowest = 1;
    int guess = 50;
    do
    {
        if (counter != 0)
            if ((highest % 2 == 0 && lowest % 2 == 0) || (highest % 2 == 1 && lowest % 2 == 1))
                guess = (highest-lowest)/2 + lowest;
            else
                guess = (highest-lowest)/2 + lowest + 1;
        cout << guess << endl;
        counter++;
        if (guess < 1 || guess > 100)
            cout << "Now you're not even trying" << endl;
        else if (guess > number)
        {
            cout << "lower" << endl;
            highest = guess;
        }

        else if (guess < number)
        {
            cout << "higher" << endl;
            lowest = guess;
        }
        else
            cout << "You guessed the number, congratulations!" << endl;

    } while (guess != number);
        return counter;
}

int main()
{
    srand(time(NULL));
    cout << "I will choose a number between 1 and 100, guess it if you can." << endl;
    cout << "I will tell you higher or lower after each guess, good luck!" << endl;
    cout << "Thinking" << endl << "Thinking" << endl << "Got it. Make your first guess." << endl;
    int number = picking_number();
    int guess, counter = 0;
    counter = game (number, counter);
        cout << "It took " << counter << " guesses to pick the right number." << endl;
    return 0;
}
