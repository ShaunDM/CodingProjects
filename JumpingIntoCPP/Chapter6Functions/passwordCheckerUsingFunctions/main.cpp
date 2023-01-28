/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 6 Functions
Problem 3
*/

#include <iostream>
#include <string>

using namespace std;

string username, password;
int menu()
{
    cout << "Please input the relevant number to select an option" << endl;
    cout << "1) Login" << endl << "2) Set up an account" << endl;
    int select;
    cin >> select;

    if (select == 1 || select == 2)
    {
        return select;
    }
     else
    {
        cout << "Invalid entry, please try again" << endl;
        menu();
    }
}
void login()
{
    cout << "Username: ";
    string user;
    getline(cin, user);
    string password_attempt;
    cout << "Password: ";
    getline(cin, password_attempt, '\n');
    if (user == username && password == password_attempt)
        cout << "Login successful" << endl;
    else
    {
        cout << "Username or password are invalid. Please try again." << endl;
        login();
    }
}
void set_up(void)
{
    cout << "To create an account, please follow the prompts." << endl;
    cout << "Please enter your username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Please enter the password for user, " << username << ": ";
    getline(cin, password);
    cout << "After being redirected, please login." << endl;
    login();
}

int main()
{
    int select;
    cout << "Welcome to our website, please login or setup an account." << endl;
    select = menu();
    if (select == 1)
        login();
    if (select == 2)
        set_up();
    return 0;
}
