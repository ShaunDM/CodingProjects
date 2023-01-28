/*

Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 11 Structures
Problem 1, 3

*/

#include <iostream>
#include <string>

using namespace std;

struct userScore
{
    string user;
    long int score;
};

struct userEntries
{
    string user;
    int totalEntries;
};

int menu ()
{
    int option;
    cout << "To input a score enter 1." << endl;
    cout << "To search for a user profile enter 2." << endl;
    cout << "To see the leader board enter 3." << endl;
    cout << "To quit enter 0." << endl << endl;
    cin >> option;
    while (option < 0 || option > 3)
    {
        cout << "Invalid entry please try again." << endl;
        cin >> option;
    }
    cout << endl;
    return option;
}

string inputU ()
{
    string user;
    cout << "New score" << endl;
    cout << "User name: ";
    cin.ignore();
    getline (cin, user);
    return user;
}
int inputS ()
{
    int score;
    cout << "Score: ";
    cin >> score;
    cout << endl;
    return score;
}

int main()
{
    userScore scoreKeeper [100], highScores[100]; // scoreKeeper tracks all entries, highScores only tracks high scores
    int entries = 0, option = -1, users = 0, userNum;
    userEntries individualEntries[100];// individualEntries array tracks number of entries for each user
    bool newUser = 0, unsorted, quit = 0;
    for (int i = 0; i < 100; i++)
    {//set arrays to "0"
        individualEntries[i].user = "";
        individualEntries[i].totalEntries = 0;
        scoreKeeper[i].user = "";
        scoreKeeper[i].score = 0;
        highScores[i].user = "";
        highScores[i].score = 0;
    }
    cout << "Welcome to the unimportant game leader boards!" << endl;
    cout << "Here you'll be able to track your scores, see the scores of other users, and see each user's high score." << endl << endl;
    while (!quit)
    {
        option = menu ();
        switch (option)
        {
        case 0:
            {//Quit
                cout << "Goodbye" << endl;
                quit = 1;
                break;
            }

        case 1:
            {// add a new entry, augment variables for user, sort users and high scores
                scoreKeeper[entries].user = inputU ();
                scoreKeeper[entries].score = inputS ();
                for (int i = 0; i <= entries; i++)
                { // checks if entry is given by a new user, if so adds new user to highScores
                    newUser = 0;
                    if ((i == entries -1 && scoreKeeper[i].user != scoreKeeper[entries].user) || entries == 0)
                    {
                        newUser = 1;
                        ++users;
                        individualEntries[users - 1].user = scoreKeeper[entries].user;
                        individualEntries[users - 1].totalEntries++;
                        highScores[users - 1].user = scoreKeeper[entries].user;
                        highScores[users - 1].score = scoreKeeper[entries].score;
                        break;
                    }
                    else if (scoreKeeper[i].user == scoreKeeper[entries].user)
                        break;
                }
                if (!newUser)
                { // user and entry sort for repeat user
                    userNum = -1;
                    for (int i = 0; i <= entries; i += individualEntries[userNum].totalEntries)
                    {
                        ++userNum;
                        if (scoreKeeper[entries].user == scoreKeeper[i].user)
                        {
                            string newEntryU = scoreKeeper[entries].user;
                            int newEntryS = scoreKeeper[entries].score;
                            for (int j = entries; j > i + individualEntries[userNum].totalEntries; j--)
                            {
                                scoreKeeper[j].user = scoreKeeper[j - 1].user;
                                scoreKeeper[j].score = scoreKeeper[j - 1].score;
                            }
                            scoreKeeper[i + individualEntries[userNum].totalEntries].user = newEntryU;
                            scoreKeeper[i + individualEntries[userNum].totalEntries].score = newEntryS;
                            individualEntries[userNum].totalEntries++;
                            do
                            { // sorts scores of user after new entry
                                unsorted = 0;
                                for (int j = i; j < i + individualEntries[userNum].totalEntries - 1; j++)
                                {
                                    if (scoreKeeper[j].score < scoreKeeper[j + 1].score)
                                    {
                                        int temp = scoreKeeper[j].score;
                                        scoreKeeper[j].score = scoreKeeper[j + 1].score;
                                        scoreKeeper[j + 1].score = temp;
                                        unsorted = 1;
                                    }
                                }
                            } while (unsorted);
                            for (int j = 0; j < users; j++)
                            {//replaces high score of new entry for user if higher
                                if (scoreKeeper[i].user == highScores[j].user && scoreKeeper[i].score > highScores[j].score)
                                {
                                    highScores[j].score = scoreKeeper[i].score;
                                    break;
                                }
                                else if (scoreKeeper[i].user == highScores[j].user)
                                {
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
                do
                {// Sorting high score array
                    unsorted = 0;
                    for (int i = 0; i < users; i++)
                    {
                        if (highScores[i].score < highScores[i + 1].score)
                        {
                            string tempU = highScores[i].user;
                            int tempS = highScores[i].score;
                            highScores[i].user = highScores[i + 1].user;
                            highScores[i].score = highScores[i + 1].score;
                            highScores[i + 1].user = tempU;
                            highScores[i + 1].score = tempS;
                            unsorted = 1;
                        }
                    }
                }while (unsorted);
                ++entries;
                break;
            }
        case 2:
            {// Search for a profile
                string query;
                cout << "To search for a profile enter the user's name: ";
                cin.ignore();
                getline (cin, query);
                int entryCount = 0;
                for (int i = 0; i < entries; i++)
                {
                    if (scoreKeeper[i].user == query)
                    {
                        ++entryCount;
                        if (entryCount == 1)
                        {
                            cout << endl << "Scores: " << endl;
                        }
                        cout << entryCount << ") " << scoreKeeper[i].score << endl;
                    }
                    else if (entryCount && scoreKeeper[i + 1].user != scoreKeeper[i].user)
                        break;
                }
                if (!entryCount)
                {
                    cout << endl << "No user listed, returning to the main menu..." << endl;
                }
                cout << endl;
                break;
            }
        case 3:
            {// Print high score of all users
                cout << "High scores of all users: " << endl << endl;
                for (int i = 0; i < users; i++)
                {
                    cout << i + 1 << ") ";
                    cout << highScores[i].user << ": ";
                    cout << highScores[i].score << endl;
                }
                break;
            }
        }
    }
    return 0;
}
