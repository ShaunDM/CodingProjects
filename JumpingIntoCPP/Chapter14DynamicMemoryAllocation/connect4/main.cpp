#include <iostream>


using namespace std;

int winCounter[3] = {0, 0, 0};
bool oneMoreGame = 1;

void intro (int &height, int &width)
{
    cout << "Welcome to Connect Four - Flex!" << endl;
    cout << "A Connect Four game that allows you to choose the size of the board you wish to play!" << endl << endl;
     cout << "A minimum of 4 columns and rows is required to play the game." << endl;
    cout << "Please enter the number of columns you would like your board to have, an excess number of columns may cause impairment to rendering the board." << endl << endl;
    while (width < 4)
    {
        cout << "Columns: ";
        cin >> width;
    }
    cout << endl << "Please enter the number of rows you would like your board to have." << endl;
    while (height < 4)
    {
        cout << "Rows: ";
        cin >> height;
    }
    cout << endl;
}
void clearBoard (char **ppBoard, int height, int width, int *pFillOfColumn)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            ppBoard[i][j] = ' ';
        }
    }
    for (int i = 0; i < width; i++)
    {
        pFillOfColumn[i] = 0;
    }
}
void printBoard (char **ppBoard, int height, int width)
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
                    {
                        if (i > 9 && k > 9)
                            cout << k << ", " << i << " |";
                        else if (i > 9 || k > 9)
                            cout << k << ", " << i << "  |";
                        else
                            cout << k << ", " << i << "   |";
                    }

                    else
                        cout << "   " << ppBoard[k][i] << "   |";
                }
                else
                    cout << "       |";
            }
            if (j == 1)
            {
                if (ppBoard[width - 1][i] == ' ')
                    cout << width - 1 << ", " << i;
                else
                    cout << "   " << ppBoard[width - 1][i];
            }
            cout << endl;
        }
        for (int l = 0; l < width - 1; l++)
        {
          cout << "_______|";
        }
        cout << "________" << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            if (i == 1)
            {
                if (ppBoard[j][0] == ' ')
                {
                    if (i > 9 && j > 9)
                        cout << j << ", " << 0 << " |";
                    else if (i > 9 || j > 9)
                        cout << j << ", " << 0 << "  |";
                    else
                        cout << j << ", " << 0 << "   |";
                }
                else
                    cout << "   " << ppBoard[j][0] << "   |";
            }

            else
                cout << "       |";
        }
        if (i == 1)
        {
            if (ppBoard[width - 1][0] == ' ')
                cout << width - 1 << ", " << 0;
            else
                cout << "   " << ppBoard[width - 1][0];
        }
        cout << endl;
    }
    cout << endl;
}
bool checkValidity (char **ppBoard, int height, int width, int select, int *pFillOfColumn)
{
    if (select > width - 1 || select < 0 || pFillOfColumn[select] == height)
    {
        cout << endl;
        cout << "Invalid selection" << endl << endl;
        return 1;
    }
    return 0;
}
void makeAMove (char **ppBoard, int height, int width, int player, int *pFillOfColumn)
{
    bool invalid;
    int select;
    do
    {
        invalid = 1;
        cout << "Player " << player << " it is your turn." << endl;
        cout << "Enter the column you would like to place your piece." << endl;
        cout << "Column: ";
        cin >> select;
        invalid = checkValidity(ppBoard, height, width, select, pFillOfColumn);
    }while (invalid);
    if (player == 1)
    {
        ppBoard[select][pFillOfColumn[select]] = 'x';
        pFillOfColumn[select]++;
    }
    else
    {
        ppBoard[select][pFillOfColumn[select]] = '+';
        pFillOfColumn[select]++;
    }
}
int evaluateWin(char **ppBoard, int height, int width, int player, int *pFillOfColumn)
{
    //win via 4 in the same column
    for (int i = 0; i < height - 3; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(ppBoard[j][i] == ppBoard[j][i + 1] && ppBoard[j][i] == ppBoard[j][i + 2] && ppBoard[j][i] == ppBoard[j][i + 3] && ppBoard[j][i] != ' ')
            {
                cout << "Congratulations, Player " << player << " Wins!" << endl;
                return player;
            }
        }
    }
    //win via 4 in the same row
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - 3; j++)
        {
            if(ppBoard[j][i] == ppBoard[j + 1][i] && ppBoard[j][i] == ppBoard[j + 2][i] && ppBoard[j][i] == ppBoard[j + 3][i] && ppBoard[j][i] != ' ')
            {
                cout << "Congratulations, Player " << player << " Wins!" << endl;
                return player;
            }
        }
    }
    //win via 4 diagonally, lower left to higher right
    for (int i = 0; i < height - 3; i++)
    {
        for (int j = 0; j < width - 3; j++)
        {
            if(ppBoard[j][i] == ppBoard[j + 1][i + 1] && ppBoard[j][i] == ppBoard[j + 2][i + 2] && ppBoard[j][i] == ppBoard[j + 3][i + 3] && ppBoard[j][i] != ' ')
            {
                cout << "Congratulations, Player " << player << " Wins!" << endl;
                return player;
            }
        }
    }
    //win via 4 diagonally, higher left to lower right
    for (int i = height; i > 2; i--)
    {
        for (int j = 0; j < width - 3; j++)
        {
            if(ppBoard[j][i] == ppBoard[j + 1][i - 1] && ppBoard[j][i] == ppBoard[j + 2][i - 2] && ppBoard[j][i] == ppBoard[j + 3][i - 3] && ppBoard[j][i] != ' ')
            {
                cout << "Congratulations, Player " << player << " Wins!" << endl;
                return player;
            }
        }
    }
    //draw
    int draw = 0;
    for (int i = 0; i < width; i++)
    {
        if (pFillOfColumn[i] == height - 1)
            draw++;
    }
    if (draw == width)
        return 0;
    return -1;
}
int main()
{
    int height = 3, width = 3, turn = 0, player, winner = -1;
    intro (height, width);
    char **ppBoard = new char* [width];
    int *pFillOfColumn = new int [width];
    for (int i = 0; i < width; i++)
    {
        ppBoard[i] = new char [height];
    }
    clearBoard (ppBoard, height, width, pFillOfColumn);
    printBoard (ppBoard, height, width);
    cout << "Player 1 uses 'x' to mark their space, Player 2 uses '+' to mark their space. The game is about to begin." << endl << endl;
    for ( ; ; )
    {
        player = turn % 2 + 1;
        makeAMove(ppBoard, height, width, player, pFillOfColumn);
        printBoard(ppBoard, height, width);
        winner = evaluateWin(ppBoard, height, width, player, pFillOfColumn);
        if (winner >= 0)
        {
            winCounter[winner]++;
            cout << "P1: " << winCounter[1] << endl;
            cout << "P2: " << winCounter[2] << endl;
            cout << "Draws: " << winCounter[0] << endl << endl;
            cout << "To continue enter 1, to quit enter 0." << endl;
            cout << "Continue?" << endl << endl;
            cin >> oneMoreGame;
            cout << endl;
            if (oneMoreGame)
                main();
            break;
        }
        turn++;
    }
    return 0;
}
