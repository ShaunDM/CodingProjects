/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 5 Loops
Problem 7
*/

#include <iostream>

using namespace std;

int main()
{
    int input = -1, one = 0, two = 0, three = 0;
    while (input != 0)
    {
        cout << "Do you think infants should be cannibalized for their stem cells, in the name of science and the one true God, Satan?" << endl;
        cout << "Please input the number next to the answer that most strongly resonates with you." << endl << endl;
        cout << "1) Hail Satan!" << endl;
        cout << "2) Stem cell research could save many lives, repair debilitating injuries, and may be the key to the evolutionary control of our species. It's fine if they were from aborted fetuses." << endl;
        cout << "3) What kind of question is that you monsters, I'm calling the cops!" << endl;
        cin >> input;
        cout << "You have input: " << input << endl;
        if (input == 2 || input == 3)
        {
            cout << "Quick grab them, they may have precious stem cells." << endl;
        }
        if (input == 1)
            one++;
        else if (input == 2)
            two++;
        else if (input == 3)
            three++;
        else if (input == 0)
        {
            for(int i = 5; i > 1; --i)
            {
               cout << "*";
            }

            cout << endl;
            for(int i = two; i > 1; --i)
            {
                cout << "*";
            }
            cout << endl;
            for(int i = three; i > 1; --i)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
                cout << "Invalid entry" << endl;
    }

    return 0;
}
