#include <iostream>


using namespace std;

void intro (int &height, int &width)
{
    cout << "Welcome to Connect Four - Flex!" << endl;
    cout << "Connect Four game that allows you to choose the size of the board you wish to play!" << endl << endl;
    cout << "Please enter the number of rows you would like your board to have." << endl;
    cout << "Rows: ";
    cin >> height;
    cout << endl << "Please enter the number of columns you would like your board to have." << endl;
    cout << "Columns: ";
    cin >> width;
    cout << endl;
}

void clearBoard (char **ppArray, int height, int width)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            ppBoard[i][j] = ' ';
        }
    }
}

void printBoard (char **ppArray, int height, int width)
{
    for (int i = height - 1; i > 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < width - 1; k++)
            {
                if (j == 1)
                {
                    if (ppBoard[k][i] == ' ')
                        cout << k << ", " << i << " |";
                    else
                        cout << "  " << ppBoard[k][i] << "  |";
                }
                else
                    cout << "     |";
                if (j == 1)
                    cout
            }
            cout << endl;
        }
        for (int l = 0; l < width - 1; l++)
        {
          cout << "_____|";
        }
        cout << "______" << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            if (i == 1)
                cout << "  " << ppBoard[j][0] << "  |";
            else
                cout << "     |";
        }
        cout << endl;
    }
}

int main()
{
    int height, width;
    intro (height, width);
    char **ppBoard = new char* [height];
    for (int i = 0; i < height; i++)
    {
        ppBoard[i] = new char [width];
    }
    clearBoard (ppBoard, height, width);
    printBoard ()

    return 0;
}
