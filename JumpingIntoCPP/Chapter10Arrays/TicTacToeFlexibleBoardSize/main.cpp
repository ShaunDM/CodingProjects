/*

Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 10 Arrays
Problem 5

*/
#include <iostream>

using namespace std;

void winner (int player);

int pMove (int player, int axis, int rows, int columns)
{

    switch (axis)
    {
    case 0:
        {
            cout << "P"<< player << " enter the row: ";
            cin >> axis;
            while (axis > rows || axis < 1)
            {
                cout << "Invalid entry, try again." << endl;
                cin >> axis;
            }
            break;
        }
    case 1:
    {
        cout << "P"<< player << " enter the column: ";
        cin >> axis;
        while (axis > columns || axis < 1)
        {
            cout << "Invalid entry, try again." << endl;
            cin >> axis;
        }
        break;
    }
    return axis;
    }

}

int main()
{
    int rows, columns;
    cout << "Welcome to Tic Tac Toe Flex!" << endl;
    cout << "The board is separated into a grid with the row specified first, then the column. The rows and columns are numbered in conventional order starting from 1." << endl;
    cout << "Winner is the first to get four in a row." << endl;
    cout << "Select what size board you would like to play with, up to 100 by 100." << endl;
    cout << "How many rows would you like to play with?" << endl;
    cout << "Rows: ";
    cin >> rows;
    while (rows < 4 || rows > 100)
    {
        cout << "Invalid Entry" << endl;
        cout << "Rows: ";
        cin >> rows;
    }
    cout << "How many columns would you like to play with?" << endl;
    cout << "Columns: ";
    cin >> columns;
    while (columns < 4 || columns > 100)
    {
        cout << "Invalid Entry" << endl;
        cout << "Columns: ";
        cin >> columns;
    }
    int board [rows][columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            board [i][j] = 0;
        }
    }
    for (int i = 0; ; i++)
    {
        int row = -1, column = -1;
        if (i % 2 == 0)
        {
            cout << "Player 1's move." << endl;
            row = pMove (1, 0, rows, columns);
            column = pMove (1, 1, rows, columns);
            while (board [row - 1][column -1] != 0)
            {
                cout << "Space already chosen." << endl;
                row = pMove (1, 0, rows, columns);
                column = pMove (1, 1, rows, columns);
            }
            board [row - 1][column -1] = 1;
        }
        else
        {
            cout << "Player 2's move." << endl;
            row = pMove (2, 0, rows, columns);
            column = pMove (2, 1, rows, columns);
            while (board [row - 1][column -1] != 0)
            {
                cout << "Space already chosen." << endl;
                row = pMove (1, 0, rows, columns);
                column = pMove (1, 1, rows, columns);
            }
            board [row - 1][column -1] = 2;
        }

        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < columns -3; k++)
            {
                if (board[j][k] == board[j][k + 1] && board[j][k] == board[j][k + 2] && board[j][k] == board[j][k + 3] && board[j][k] != 0)
                {
                    if (i % 2 == 0)
                        winner (1);
                    else
                        winner (2);
                    return 0;
                }
            }

        }
        for (int j = 0; j < columns; j++)
        {
            for (int k = 0; k < rows -3; k++)
            {
                if (board[k][j] == board[k + 1][j] && board[j][k] == board[k + 2][j] && board[j][k] == board[k + 3][j] && board[j][k] != 0)
                {
                    if (i % 2 == 0)
                        winner (1);
                    else
                        winner (2);
                    return 0;
                }
            }
        }
        for (int j = 0; j < rows - 3; j++)
        {
            for (int k = 0; k < columns -3; k++)
            {
                 if (board[j][k] == board[j + 1][k + 1] && board[j][k] == board[j + 2][k + 2] && board[j][k] == board[j + 3][k + 3] && board[j][k] != 0)
                {
                    if (i % 2 == 0)
                        winner (1);
                    else
                        winner (2);
                    return 0;
                }
            }


        }
        for (int j = rows - 1; j > 2; j--)
        {
            for (int k = 0; k < columns - 3; k++)
            {
                 if (board[j][k] == board[j - 1][k + 1] && board[j][k] == board[j - 2][k + 2] && board[j][k] == board[j - 3][k + 3] && board[j][k] != 0)
                {
                    if (i % 2 == 0)
                        winner (1);
                    else
                        winner (2);
                    return 0;
                }
            }
        }
        if (i == rows * columns)
        {
            winner (0);
            return 0;
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
            cout << "Tie" << endl;
            break;
        }

    case 1:
        {

        }
    case 2:
        {
            cout << "Player " << player << " Wins!" << endl;
            break;
        }
    }
}
