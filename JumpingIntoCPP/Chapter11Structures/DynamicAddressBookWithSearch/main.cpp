/*

Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 11 Structures
Problem 1, 3

*/

#include <iostream>
#include <string>

using namespace std;

struct contact
{
    string name;
    string phone;
    string grouping;
};


string addContact (int type)
{
    string entry;
    switch (type)
    {
    case 0:
        {
            cout << "Please enter the new contact's full name." << endl;
            break;
        }
    case 1:
        {
            cout << "Please enter the new contact's phone number." << endl;
            break;
        }
    case 2:
        {
            cout << "Please enter the new contact's group. This is used to sort your contacts." <<
            endl << "If you don't know what to sort by, the first letter of the last name is a good method."<< endl;
            break;
        }
    }
    getline (cin, entry);
    return entry;

}

int menu ()
{
    cout << "To add a contact enter 1." << endl;
    cout << "To search for a group enter 2." << endl;
    cout << "To quit enter 0." << endl;
    cout << "Enter your choice when ready." << endl;
    int option;
    cin >> option;
    cin.ignore();
    while (option > 2 || option < 0)
    {
        cout << "Invalid selection. Please try again.";
        cin >> option;
        cin.ignore();
    }
    return option;
}

int main()
{
    int contacts = 0;
    contact addressBook[100];
    cout << "Welcome to the address book, address book can store up to a hundred contacts." << endl;
    cout << "To begin enter in the contact's information. Starting with their name." << endl;
    addressBook[contacts].name = addContact(0);
    addressBook[contacts].phone = addContact(1);
    addressBook[contacts].grouping = addContact(2);
    contacts++;
    int option = -1, proceed = 1;
    string searchContacts;
    while (option)
    {
        proceed = 1;
        option = menu ();
        switch (option)
        {
        case 0:
            {
                break;
            }
        case 1:
            {
                while (proceed)
                {
                    if (contacts > 99)
                    {
                        cout << "Your contact list is full." << endl;
                        break;
                    }
                    addressBook[contacts].name = addContact(0);
                    addressBook[contacts].phone = addContact(1);
                    addressBook[contacts].grouping = addContact(2);
                    contacts++;
                    cout << "To return to the menu enter 0, to continue enter 1." << endl;
                    cin >> proceed;
                    cin.ignore();
                }
                break;
            }
        case 2:
            {
                while (proceed)
                {
                    cout << "Please enter the group you would like to search for." << endl;
                    cout << "If you would like to see all of your contacts enter: all." << endl;
                    cout << "Search: ";
                    getline(cin, searchContacts);
                    cout << endl;
                    if (searchContacts == "all")
                    {
                        for (int i = 0; i < contacts; i++)
                        {
                            cout << addressBook[i].name << endl;
                            cout << addressBook[i].phone << endl;
                            cout << addressBook[i].grouping << endl;
                            cout << endl;
                        }
                    }
                    else
                    {
                        int results = 0;
                        cout << searchContacts << endl << endl;
                        for (int i = 0; i < contacts; i++)
                        {
                            if (addressBook[i].grouping == searchContacts)
                            {
                                cout << addressBook[i].name << endl;
                                cout << addressBook[i].phone << endl;
                                cout << endl;
                                results++;
                            }
                        }
                        if (!results)
                        {
                            cout << "No groupings listed for: " << searchContacts << endl;
                        }
                    }
                    cout << "To return to the menu enter 0, to continue enter 1." << endl;
                    cin >> proceed;
                    cin.ignore();
                }
                break;
            }
        }
        if (!option)
        {
            return 0;
        }
    }
}
