/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 7 Switch Case and Enums
Problem 2
*/

#include <iostream>

using namespace std;

string dayeth(int i)
{
    string day;
    switch (i)
    {
        case 1:
            day = "first";
            break;
        case 2:
            day = "second";
            break;
        case 3:
            day = "third";
            break;
        case 4:
            day = "fourth";
            break;
        case 5:
            day = "fifth";
            break;
        case 6:
            day = "sixth";
            break;
        case 7:
            day = "seventh";
            break;
        case 8:
            day = "eighth";
            break;
        case 9:
            day = "ninth";
            break;
        case 10:
            day = "tenth";
            break;
        case 11:
            day = "eleventh";
            break;
        case 12:
            day = "twelfth";
            break;
    }
    return day;
}

void lyrics (int i, string day)
{
    cout << "On the " << day << " day of Christmas my true love sent to me: " << endl;
        switch(i)
        {
            case 12:
                cout << "Twelve drummers drumming," << endl;
            case 11:
                cout << "Eleven pipers piping," << endl;
            case 10:
                cout << "Ten lords a-leaping," << endl;
            case 9:
                cout << "Nine ladies dancing," << endl;
            case 8:
                cout << "Eight maids a-milking," << endl;
            case 7:
                cout << "Seven swans a-swimming," << endl;
            case 6:
                cout << "Six geese a-laying," << endl;
            case 5:
                cout << "Five gold rings," << endl;
            case 4:
                cout << "Four calling birds," << endl;
            case 3:
                cout << "Three French hens," << endl;
            case 2:
                cout << "Two turtle doves," << endl;
            case 1:
                if (i == 1)
                    cout << "A partridge in a pear tree." << endl << endl;
                else
                    cout << "and a partridge in a pear tree." << endl << endl;
                break;
        }
}
int main()
{
    string day_count;
    for(int i = 1; i <= 12; i++)
    {
        day_count = dayeth(i);
        lyrics(i, day_count);
    }
    return 0;
}
