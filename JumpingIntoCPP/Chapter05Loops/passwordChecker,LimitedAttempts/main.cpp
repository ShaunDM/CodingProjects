/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 5 Loops
Problem 4
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter your password: " << endl;
    string password_attempt, password = "password";
    for (int i = 0; i < 3; i++)
    {
        getline (cin, password_attempt);
        if(password == password_attempt)
        {
            cout << "Login successful, welcome user." << endl;
            break;
        }
        else
        {
            cout << "Login failed, incorrect password. Please try again." << endl;
            if(i != 2)
                continue;
        }
        cout << "Number of login attempts allowed has been exceeded. Please try later." << endl;
    }
    return 0;
}
