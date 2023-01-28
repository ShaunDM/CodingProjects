/*
Creator: Shaun McRae
Jumping into C++
Chapter 8 Randomizing your Programs
Problem 4
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int run_slot()
{
    return rand () % 3;
}

int main()
{
    srand (time (NULL));
    cout << "Welcome to the slot machine" << endl;
    cout << "Base payout of $10 and then add the base multiplied by matched number" << endl;
    cout << "Winning Combos: " << endl;
    cout << "1) 000" << endl;
    cout << "2) 111" << endl;
    cout << "3) 222" << endl;
    cout << "To pull enter 0" << endl;
    int pull, slot_1, slot_2, slot_3, payout, sum;
    while (1)
    {
        cin >> pull;
        if (pull == 0)
        {
            slot_1 = run_slot();
            slot_2 = run_slot();
            slot_3 = run_slot();
        }
        cout << slot_1 << slot_2 << slot_3 << endl;
        if (slot_1 == slot_2 && slot_1 == slot_3)
        {
            cout << "Winner!" << endl;
            payout = 10;
            if (slot_1 == 1)
                payout += payout;
            else if (slot_1 == 2)
                payout += payout * 2;
            sum += payout;
            cout << "$" << payout << endl;
        }
        cout << "Total payout: $" << sum << endl;
    }

    return 0;
}
