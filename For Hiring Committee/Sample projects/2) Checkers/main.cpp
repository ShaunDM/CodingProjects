/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 10 Arrays
Problem 6
*/

#include <iostream>

using namespace std;

int select (int axis)
{//select a piece
    switch (axis)
    {
    case 0:
        {
            cout << "Piece row: ";
            cin >> axis;
            break;
        }
    case 1:
        {
            cout << "Piece column: ";
            cin >> axis;
            break;
        }
    case 2:
        {
            cout << "Space row: ";
            cin >> axis;
            break;
        }
    case 3:
        {
            cout << "Space column: ";
            cin >> axis;
            break;
        }
    case 4:
        {
            cout << "Select the next row you would like to move your piece to." << endl;
            cout << "Otherwise, to end your turn enter 0. " << endl;
            cin >> axis;
            break;
        }
    case 5:
        {
            cout << "Select the next column you would like to move your piece to." << endl;
            cout << "Otherwise, to end your turn enter 0." << endl;
            cin >> axis;
            break;
        }
    }
    return axis - 1;
}

int distance (int a, int b)
{//calculate absolute value of distance
    int distance = a - b;
    if (distance < 0)
        distance *= -1;
    return distance;
}

int distanceRow (int a, int b, int player)
{// calculate vector
    int distance = a - b;
    if (player == 1)
        return distance;
    else
        return distance * -1;
}

int jumpedSpace (int a, int b)
{//outputs coordinate of a jumped piece
    if (a > b)
    {
        a -= ((a - b)/2);
        return a;
    }
    else
    {
        b -= ((b - a)/2);
        return b;
    }
}

bool jumpEval (int player, int jumpedPiece)
{// evaluates if a jump is legal

    if (jumpedPiece> 2)
        jumpedPiece -= 2;
    if (jumpedPiece != player && jumpedPiece != 0)
        return 0;
    else
        return 1;
}

int main()
{
    cout << "Welcome to Checkers!" << endl;
    cout << "Player 1 moves first." << endl;
    int board [8][8];
    { // initial board set up
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board [i][j] = 0;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (i % 2 == 1)
            {
                for (int j = 1; j < 8; j += 2)
                {
                    board [i][j] = 1;
                }
            }
            else
            {
                for (int j = 0; j < 8; j+= 2)
                    board [i][j] = 1;
            }
        }

        for (int i = 7; i > 4; i--)
        {
            if (i % 2 == 1)
            {
                for (int j = 1; j < 8; j += 2)
                {
                    board [i][j] = 2;
                }
            }
            else
            {
                for (int j = 0; j < 8; j+= 2)
                    board [i][j] = 2;
            }
        }
    }
    int row, column, moveRow, moveCol, player, pieces[2], distRow, distCol;
    pieces [0] = 12, pieces [1] = 12;
    { // gameplay
        for (int i = 0; ; i++)
        {
            if (i % 2 == 0)
            {
                player = 1;
            }
            else
            {
                player = 2;
            }
            { // evaluates if a player can't make a move
                int possibleMove[2];
                possibleMove[0] = 0, possibleMove[1] = 0;
                for (int j = 0; j < 8; j++)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        if (board [j][k] > 0)
                        {
                            for (int l = -2; l < 3; l++)
                            {
                                for (int m = -2; m < 3; m++)
                                {
                                    distCol = distance (k + m, k);
                                    if (board [j][k] < 3)
                                    {
                                        distRow = distanceRow (j + l, j, board[j][k]);
                                    }
                                    else // checking move validity King
                                    {
                                        distRow = distance (j + l, j);
                                    }
                                    if (board[j + l][j + m] == 0 && distRow == distCol && (distRow == 1 || distRow == 2) &&
                                        j + l >= 0 && j + l < 8 && k + m >= 0 && k + m < 8)
                                    {
                                        if (distRow == 2)
                                        {
                                            if (jumpEval (board[j][k], board [jumpedSpace(j + l, j)][jumpedSpace (k, k + m)]))
                                                continue;
                                        }
                                        if (board[j][k] > 2)
                                            possibleMove[board[j][k] - 3]++;
                                        else
                                            possibleMove[board[j][k] - 1]++;
                                    }
                                }
                            }
                        }
                    }
                    if (possibleMove [0] > 0 && possibleMove [1] > 0)
                        break;
                }
                for (int j = 0; j < 2; j++)
                {
                    if (possibleMove[j] == 0 && possibleMove[j + 1] == 0 && j == 0)
                    {
                        cout << "Tie" << endl;
                        return 0;
                    }
                    if (possibleMove[player - 1] == 0)
                    {
                        switch (player - 1)
                        {
                        case 0:
                            {
                            cout << "Player 2 Wins!" << endl;
                            return 0;
                            }

                        case 1:
                            {
                            cout << "Player 1 Wins!" << endl;
                            return 0;
                            }
                        }
                    }
                }
            }
            int subtract = 0, playerFactor;
            bool jump =  0;
            cout << "Player " << player << " it is your move. Please select the piece to be moved." << endl;
            { // Evaluate if there is a possible jump move
                for (int j = 0; j < 8; j++)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        if (board[j][k] == player || board[j][k] == player + 2)
                        {
                            playerFactor = player;
                            if (board[j][k] > 2)
                                playerFactor = 3;
                            switch (playerFactor)
                            {
                            case 1:
                                {
                                    if (!jumpEval (player, board [jumpedSpace(j + 2, j)][jumpedSpace (k + 2, k)]))
                                        {
                                            if ((j + 2 < 8 && k + 2 < 8) && board[j + 2][k + 2] == 0)
                                                jump = 1;
                                        }
                                    else if (!jumpEval (player, board [jumpedSpace(j + 2, j)][jumpedSpace (k - 2, k)]))
                                        {
                                            if ((j + 2 < 8 && k - 2 > -1) && board[j + 2][k - 2] == 0)
                                                jump = 1;
                                        }
                                    break;
                                }
                            case 2:
                                {
                                    if (!jumpEval (player, board [jumpedSpace(j - 2, j)][jumpedSpace (k + 2, k)]))
                                        {
                                            if ((j - 2 > -1 && k + 2 < 8) && board[j - 2][k + 2] == 0)
                                                jump = 1;
                                        }
                                    else if (!jumpEval (player, board [jumpedSpace(j - 2, j)][jumpedSpace (k - 2, k)]))
                                        {
                                            if ((j - 2 > -1 && k - 2 > -1) && board[j - 2][k - 2] == 0)
                                                jump = 1;
                                        }
                                    break;
                                }
                            case 3:
                                {
                                    if (!jumpEval (player, board [jumpedSpace(j + 2, j)][jumpedSpace (k + 2, k)]))
                                        {
                                            if ((j + 2 < 8 && k + 2 < 8) && board[j + 2][k + 2] == 0)
                                                jump = 1;
                                        }
                                    else if (!jumpEval (player, board [jumpedSpace(j + 2, j)][jumpedSpace (k - 2, k)]))
                                        {
                                            if ((j + 2 < 8 && k - 2 > -1) && board[j + 2][k - 2] == 0)
                                                jump = 1;
                                        }
                                    else if (!jumpEval (player, board [jumpedSpace(j - 2, j)][jumpedSpace (k - 2, k)]))
                                        {
                                            if ((j - 2 > -1 && k - 2 > -1) && board[j - 2][k - 2] == 0)
                                                jump = 1;
                                        }
                                    else if (!jumpEval (player, board [jumpedSpace(j - 2, j)][jumpedSpace (k + 2, k)]))
                                        {
                                            if ((j - 2 > -1 && k + 2 < 8) && board[j - 2][k + 2] == 0)
                                                jump = 1;
                                        }
                                    break;
                                }
                            }
                        }
                        if (jump)
                            break;
                    }
                    if (jump)
                        break;
                }
            }
            {// Player's initial move
                bool selectPiece = 0, selectSpace = 0, jumping = 0;
                row = select(0);
                column = select(1);
                cout << "Please select the space you would like to move your piece to." << endl;
                moveRow = select(2);
                moveCol = select(3);
                do
                {// evaluate and, if necessary, repeat move selection
                    subtract = 0;
                    if (selectPiece || selectSpace || jumping)
                    {
                        cout << "Please select the piece you would like to move." << endl;
                        row = select(0);
                        column = select(1);
                        cout << "Please select the space you would like to move your piece to." << endl;
                        moveRow = select(2);
                        moveCol = select(3);
                        selectPiece = 0, selectSpace = 0, jumping = 0;
                    }
                    {// Picking a piece not owned by player
                        if (board [row][column] > 2)
                            subtract = 2;
                        if (board [row][column] - subtract != player)
                        {
                            cout << "Invalid selection, piece. Try again." << endl;
                            selectPiece = 1;
                            continue;
                        }
                    }
                    distCol = distance (moveCol, column);
                    if (jump)// Evaluates if player chose to take an opponent's piece when able
                    {
                        if (distCol != 2)
                        {
                            cout << "You're required to take an opponent's piece if able. Invalid move, try again." << endl;
                            jumping = 1;
                            continue;
                        }

                    }
                    switch (board [row][column])// Finding distance depending on piece type
                    {
                    case 1:
                        {

                        }
                    case 2:
                        {
                           distRow = distanceRow (moveRow, row, player);

                           break;
                        }
                    case 3:
                        {

                        }
                    case 4:
                        {
                            distRow = distance (moveRow, row);
                            break;
                        }
                    }
                    {// evaluate move validity, first move
                        if (distCol == 2) // checking if player can jump over the piece
                        {
                            if (jumpEval (player, board [jumpedSpace(moveRow, row)][jumpedSpace (moveCol, column)]))
                                moveRow = -2;
                        }
                        if (board[moveRow][moveCol] != 0 || distRow != distCol || (distRow != 1 && distRow != 2) ||
                                   moveRow < 0 || moveRow > 7 || moveCol < 0 || moveCol > 7)
                        {
                            cout << "Invalid selection, space. Try again." << endl;
                            selectSpace = 1;
                            continue;
                        }
                    }
                } while (selectPiece || selectSpace || jumping);
            }
            {// Setting variables after first move
                board[moveRow][moveCol] = board[row][column];
                board[row][column] = 0;
                if (distCol == 2)
                {
                        board [jumpedSpace(moveRow, row)][jumpedSpace (moveCol, column)] = 0;
                        if (player == 1)
                        {
                            --pieces [1];
                        }
                        else
                        {
                            --pieces [0];
                        }
                }
                {// Kinging a piece
                    if (player == 1 && moveRow == 7 && board[moveRow][moveCol] < 3)
                    {
                        board[moveRow][moveCol] += 2;
                        distCol = 1;
                    }

                    else if (player == 2 && moveRow == 0 && board[moveRow][moveCol] < 3)
                    {
                        board[moveRow][moveCol] += 2;
                        distCol = 1;
                    }
                }
            }
            while (distCol == 2)
            {// evaluate move validity, selecting moves for jumping multiple pieces, setting variables after each jump
                {// selecting move
                    row = moveRow;
                    column = moveCol;
                    moveRow = select(4);
                    if (moveRow == -1)
                        break;
                    moveCol = select(5);
                    if (moveCol == -1)
                        break;
                }
                { // evaluate move validity jumping multiple pieces
                    distCol = distance (moveCol, column);
                    if (distCol == 2) // checking if player can jump over the piece
                    {
                        if (jumpEval (player, board [jumpedSpace(moveRow, row)][jumpedSpace (moveCol, column)]))
                            moveRow = -2;
                    }
                    if (board [row][column] < 3) // checking move validity regular piece jumping multiple pieces
                    {
                        distRow = distanceRow (moveRow, row, player);
                        while (board[moveRow][moveCol] != 0 || distRow != distCol || distRow != 2 ||
                               moveRow < 0 || moveRow > 7 || moveCol < 0 || moveCol > 7)
                        {
                            cout << "Invalid selection, space. Try again." << endl;
                            moveRow = select(4);
                            if (moveRow == -1)
                                break;
                            moveCol = select(5);
                            if (moveCol == -1)
                                break;
                            distRow = distanceRow (moveRow, row, player);
                            distCol = distance (moveCol, column);
                            if (jumpEval (player, board [jumpedSpace(moveRow, row)][jumpedSpace (moveCol, column)]))
                                moveRow = -2;
                        }
                    }
                    else // checking move validity King jumping multiple pieces
                    {
                        distRow = distance (moveRow, row);
                        while (board[moveRow][moveCol] != 0 || distRow != distCol || distRow != 2 ||
                               moveRow < 0 || moveRow > 7 || moveCol < 0 || moveCol > 7)
                        {
                            cout << "Invalid selection, space. Try again." << endl;
                            moveRow = select(4);
                            if (moveRow == -1)
                                break;
                            moveCol = select(5);
                            if (moveCol == -1)
                                break;
                            distRow = distance (moveRow, row);
                            distCol = distance (moveCol, column);
                            if (distRow == 2)
                            {
                                if (jumpEval (player, board [jumpedSpace(moveRow, row)][jumpedSpace (moveCol, column)]))
                                    moveRow = -2;
                            }
                        }
                    }
                }
                {// Setting variables after jumping a piece
                    board[moveRow][moveCol] = board[row][column];
                    board[row][column] = 0;
                    board [jumpedSpace(moveRow, row)][jumpedSpace (moveCol, column)] = 0;
                    if (player == 1)
                    {
                        --pieces [1];
                    }
                    else
                    {
                        --pieces [0];
                    }
                }
            }
            { // evaluate win
                for (int j = 0; j < 2; j++)
                {
                    if (pieces [j] == 0)
                    {
                        cout << "Player " << player << " Wins!" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
