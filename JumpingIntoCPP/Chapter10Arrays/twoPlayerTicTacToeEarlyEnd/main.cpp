/*

Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 10 Arrays
Problem 4

*/

#include <iostream>

using namespace std;

int p1wins = 0, p2wins = 0, ties = 0;

void winner (int player);

int main()
{
    int play = 0, player = -1;
    cout << "Welcome to Tic Tac Toe" << endl;
    cout << "The board is separated into a grid with the row specified first, then the column. The rows and column are numbered in conventional order from 1 to 3." << endl;
    cout << "To play enter 1, to quit enter 0." << endl;
    cin >> play;
    if (!play)
    {
        cout << "P1 wins: " << p1wins << endl;
        cout << "P2 wins: " << p2wins << endl;
        cout << "Ties: " << ties << endl;
        return 0; // For some reason program doesn't end if playing 2nd or more game, still completes rest of if statement.
    }
    int board [3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board [i][j] = 0;
        }
    }
    int tracker [8];
    for (int i = 0; i < 8; i++)
    {
        tracker[i] = 0;
    }
    for (int i = 0; i < 9; i++)
    {
        int row = -1, column = -1;
        if (i % 2 == 0)
        {
            cout << "Player 1, make your move." << endl;
            cout << "Please enter the row: ";
            cin >> row;
            while (row > 3 || row < 1)
            {
                cout << "Invalid entry, try again." << endl;
                cin >> row;
            }
            cout << "Please enter the column: ";
            cin >> column;
            while (column > 3 || column < 1)
            {
                cout << "Invalid entry, try again." << endl;
                cin >> column;
            }
            while (board [row - 1][column -1] != 0)
            {
                cout << "Space already chosen, please choose again." << endl;
                cout << "Row: ";
                cin >> row;
                cout << "Column: ";
                cin >> column;
            }
            board [row - 1][column -1] = 1;
            tracker [row - 1] += 1;
            tracker [column + 2] += 1;
            if (row == column)
                tracker [6] += 1;
            if (column == row + 2 || (column == row && row == 2) || column == row - 2)
                tracker [7] += 1;
        }
        else
        {
            cout << "Player 2, make your move." << endl;
            cout << "Please enter the row: ";
            cin >> row;
            while (row > 3 || row < 1)
            {
                cout << "Invalid entry, try again." << endl;
                cin >> row;
            }
            cout << "Please enter the column: ";
            cin >> column;
            while (column > 3 || column < 1)
            {
                cout << "Invalid entry, try again." << endl;
                cin >> column;
            }
            while (board [row - 1][column -1] != 0)
            {
                cout << "Space already chosen, please choose again." << endl;
                cout << "Row: ";
                cin >> row;
                cout << "Column: ";
                cin >> column;
            }
            board [row - 1][column -1] = 2;
            tracker [row - 1] += 10;
            tracker [column + 2] += 10;
            if (row == column)
                tracker [6] += 10;
            if (column == row + 2 || (column == row && row == 2) || column == row - 2)
                tracker [7] += 10;
        }
        for (int j = 0; j < 8; j++)
        {
            if((tracker [j] % 3 == 0) && (tracker [j] < 10) && tracker [j] != 0)
            {
                player = 1;
                winner (player);
            }
            else if(tracker [j] % 30 == 0 && tracker [j] != 0)
            {
                player = 2;
                winner (player);
            }
        }
        if (i == 7)
        {
            for (int j = 0; j < 8; j++)
            {
                if ((tracker [j] < 10) || (tracker [j] % 10 == 0))
                    break;
                else
                {
                    player = 0;
                    winner (player);
                }
            }
        }
        else if (i == 8)
        {
            player = 0;
            winner (player);
        }
    }
    return 0;
}

void winner (int player)
{
    switch (player)
    {
    case 0:
        {
            ++ties;
            cout << "Tie" << endl;
            break;
        }

    case 1:
        {
            ++p1wins;
            cout << "Player " << player << " Wins!" << endl;
            break;
        }
    case 2:
        {
            ++p2wins;
            cout << "Player " << player << " Wins!" << endl;
            break;
        }
    }
    cout << "P1 wins: " << p1wins << endl;
    cout << "P2 wins: " << p2wins << endl;
    cout << "Ties: " << ties << endl;
    main ();
}
