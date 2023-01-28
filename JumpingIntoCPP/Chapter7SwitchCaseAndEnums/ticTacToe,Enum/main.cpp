/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 7 Switch Case and Enums
Problem 3
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Welcome to a game of tic tac toe." << endl;
    cout << "X's go first, please name the X player." << endl;
    cout << "X: ";
    string x, o;
    int o_counter = 0, x_counter = 0, tl, tm, tr, ml, mm, mr, bl, bm, br;
    getline (cin, x);
    cout << "Please name the O player." << endl;
    cout << "O: ";
    getline (cin, o);
    cout << "To play designate a row and column number on the board, using the form: row#column#, without spaces, i.e. 11 for the top left space." << endl;
    cout << "There are three rows and three columns numbered from 1 to 3." << endl;
    cout << "The game ends when someone gets three in a row, there are no spaces to fill, or a player enters: '0'." << endl;
    enum tic_tac_toe_board
    {
        TL = 11,
        TM = 12,
        TR = 13,
        ML = 21,
        MM = 22,
        MR = 23,
        BL = 31,
        BM = 32,
        BR = 33
    };
while (1)
{
    for (int i = 0; i < 9; i++)
    {
        int piece, position;
        if (i % 2 == 0)
            piece = 1;
        else
            piece = 2;
        if (i % 2 == 0)
            cout << x << " place your marker: ";
        else
            cout << o << " place your marker: ";
        cin >> position;
        switch (position)
        {
        case TL:
            {
            tl = piece;
            break;
            }
        case TM:
            {
            tm = piece;
            break;
            }
        case TR:
            {
            tr = piece;
            break;
            }
        case ML:
            {
            ml = piece;
            break;
            }

        case MM:
            {
            mm = piece;
            break;
            }
        case MR:
            {
            mr = piece;
            break;
            }
        case BL:
            {
            bl = piece;
            break;
            }
        case BM:
            {
            bm = piece;
            break;
            }
        case BR:
            {
            br = piece;
            break;
            }
        case 0:
            {
            cout << "Winner: ";
            if (piece == 1)
            {
                cout << o << endl;
                o_counter++;
            }
            if (piece == 2)
            {
                cout << x << endl;
                x_counter++;
            }
            cout << x << "wins: " << x_counter << endl;
            cout << o << "wins: " << o_counter << endl;
            tl = 0, tm = 0, tr = 0, ml = 0, mm = 0, mr = 0, bl = 0, bm = 0, br = 0;
            break;
            }
        }
        if (i > 1)
        {
            if (tl == tm && tm == tr && tl != 0)
            {
                cout << "Winner: ";
                if (tl == 1)
                {
                    cout << x << endl;
                    x_counter++;
                }
                else
                {
                    cout << o << endl;
                    o_counter++;
                }
                cout << x << "wins: " << x_counter << endl;
                cout << o << "wins: " << o_counter << endl;
                tl = 0, tm = 0, tr = 0, ml = 0, mm = 0, mr = 0, bl = 0, bm = 0, br = 0;
                break;
            }
            else if (ml == mm && mm == mr && ml != 0)
            {
                cout << "Winner: ";
                if (tl == 1)
                {
                    cout << x << endl;
                    x_counter++;
                }
                else
                {
                    cout << o << endl;
                    o_counter++;
                }
                cout << x << "wins: " << x_counter << endl;
                cout << o << "wins: " << o_counter << endl;
                tl = 0, tm = 0, tr = 0, ml = 0, mm = 0, mr = 0, bl = 0, bm = 0, br = 0;
                break;
            }
            else if (bl == bm && bm == br && bl != 0)
            {
                cout << "Winner: ";
                if (tl == 1)
                {
                    cout << x << endl;
                    x_counter++;
                }
                else
                {
                    cout << o << endl;
                    o_counter++;
                }
                cout << x << "wins: " << x_counter << endl;
                cout << o << "wins: " << o_counter << endl;
                tl = 0, tm = 0, tr = 0, ml = 0, mm = 0, mr = 0, bl = 0, bm = 0, br = 0;
                break;
            }
            else if (tl == ml && ml == bl && tl != 0)
            {
                cout << "Winner: ";
                if (tl == 1)
                {
                    cout << x << endl;
                    x_counter++;
                }
                else
                {
                    cout << o << endl;
                    o_counter++;
                }
                cout << x << "wins: " << x_counter << endl;
                cout << o << "wins: " << o_counter << endl;
                tl = 0, tm = 0, tr = 0, ml = 0, mm = 0, mr = 0, bl = 0, bm = 0, br = 0;
                break;
            }
            else if (tm == mm && mm == bm && tm != 0)
            {
                cout << "Winner: ";
                if (tl == 1)
                {
                    cout << x << endl;
                    x_counter++;
                }
                else
                {
                    cout << o << endl;
                    o_counter++;
                }
                cout << x << "wins: " << x_counter << endl;
                cout << o << "wins: " << o_counter << endl;
                tl = 0, tm = 0, tr = 0, ml = 0, mm = 0, mr = 0, bl = 0, bm = 0, br = 0;
                break;
            }
             else if (tr == mr && mr == br && tr != 0)
            {
                cout << "Winner: ";
                if (tl == 1)
                {
                    cout << x << endl;
                    x_counter++;
                }
                else
                {
                    cout << o << endl;
                    o_counter++;
                }
                cout << x << "wins: " << x_counter << endl;
                cout << o << "wins: " << o_counter << endl;
                tl = 0, tm = 0, tr = 0, ml = 0, mm = 0, mr = 0, bl = 0, bm = 0, br = 0;
                break;
            }
             else if (tr == mm && mm == bl && tr != 0)
            {
                cout << "Winner: ";
                if (tl == 1)
                {
                    cout << x << endl;
                    x_counter++;
                }
                else
                {
                    cout << o << endl;
                    o_counter++;
                }
                cout << x << "wins: " << x_counter << endl;
                cout << o << "wins: " << o_counter << endl;
                tl = 0, tm = 0, tr = 0, ml = 0, mm = 0, mr = 0, bl = 0, bm = 0, br = 0;
                break;
            }
            else if (tl == mm && mm == br && tl != 0)
            {
                cout << "Winner: ";
                if (tl == 1)
                {
                    cout << x << endl;
                    x_counter++;
                }
                else
                {
                    cout << o << endl;
                    o_counter++;
                }
                cout << x << "wins: " << x_counter << endl;
                cout << o << "wins: " << o_counter << endl;
                tl = 0, tm = 0, tr = 0, ml = 0, mm = 0, mr = 0, bl = 0, bm = 0, br = 0;
                break;
            }
            else if (i == 8)
            {
                cout << "Draw" << endl;
                tl = 0, tm = 0, tr = 0, ml = 0, mm = 0, mr = 0, bl = 0, bm = 0, br = 0;
                cout << x << "wins: " << x_counter << endl;
                cout << o << "wins: " << o_counter << endl;
                break;
            }
        }
    }
}
    return 0;
}


/*. Players receive explanation
. Instructions on who is going
. Player enters a value to place a piece
. Game evaluates if there are three in a row
. If no winner, instructs next player to go
; if winner, announces winner.
; if tie, announces tie
. Maybe add function to name players*/
