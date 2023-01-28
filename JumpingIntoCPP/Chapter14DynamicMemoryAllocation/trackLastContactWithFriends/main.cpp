/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 14, Dynamic Memory Allocation
Problem 4
*/

#include <iostream>
#include <string>

using namespace std;

struct contact
{
    string firstName = "";
    string lastName = "";
    string phone = "";
    string email = "";
    int month = 0;
    int day = 0;
    int year = 0;
    int time = 0;
    string unitOfTime = "";
};

{//Functions
    int menu ()
    {

        return option;
    }

    int timeSinceLastContact (int *pMonth, int *pDay, int *pYear, string *pUnits, int currentDay = 16, int currentMonth = 1, int currentYear = 2023)
    {// calculates time since last contact, returns appropriate time passed and units
        int daysPassed, monthsPassed, yearsPassed;
        if (currentDay < *pDay)
        {//'carries over' month before finding difference in days passed
            if (currentMonth != 1)
                currentMonth -= 1;
            else
                currentMonth = 12;
            switch (currentMonth)
            {
            case 1:
                {
                    daysPassed = currentDay + 31 - *pDay
                    break;
                }
            case 2:
                {
                    if (currentYear % 4 != 0)
                        daysPassed = currentDay + 28 - *pDay
                    else
                        daysPassed = currentDay + 29 - *pDay
                    break;
                }
            case 3:
                {
                    daysPassed = currentDay + 31 - *pDay
                    break;
                }
            case 4:
                {
                    daysPassed = currentDay + 30 - *pDay
                    break;
                }
            case 5:
                {
                    daysPassed = currentDay + 31 - *pDay
                    break;
                }
            case 6:
                {
                    daysPassed = currentDay + 30 - *pDay
                    break;
                }
            case 7:
                {
                    daysPassed = currentDay + 31 - *pDay
                    break;
                }
            case 8:
                {
                    daysPassed = currentDay + 31 - *pDay
                    break;
                }
            case 9:
                {
                    daysPassed = currentDay + 30 - *pDay
                    break;
                }
            case 10:
                {
                    daysPassed = currentDay + 31 - *pDay
                    break;
                }
            case 11:
                {
                    daysPassed = currentDay + 30 - *pDay
                    break;
                }
            case 12:
                {
                    daysPassed = currentDay + 31 - *pDay
                    break;
                }
            }
        }
        else
            daysPassed = currentDay - *pDay;
        if (currentMonth < *pMonth)
        {
           monthsPassed = currentMonth + 12 - *pMonth;
           --currentYear;
        }
        else
            monthsPassed = currentMonth - *pMonth;
        yearsPassed = currentYear - *pYear;
        if (years)
        {
            *pUnits = "yrs";
            return yearsPassed;
        }
        else if (months)
        {
            *pUnits = "mths";
            return monthsPassed;
        }
        else
        {
            *pUnits = "days";
            return daysPassed;
        }
    }

    addFriend (string *pFirst, string *pLast, string *pPhone, string *pEmail, int *pMonth, int *pDay, int *pYear, int *pTime, int *pTimeUnits,
                int friends, int *pDaysPassed, int *pMonthsPassed, int *pYearsPassed)
    {
        cout << "New friend contact information" << endl << endl;
        cout << "First Name: ";
        cin >> *pFirst;
        cout << "Last Name: ";
        cin >> *pLast;
        cout << "Phone #: ";
        cin.ignore();
        getline (cin, *pPhone);
        cout << "Email: ";
        getline (cin, *pEmail);
        cout << "Date of last contact" << endl;
        cout << "Month: ";
        cin >> *pMonth;
        cout << "Day: ";
        cin >> *pDay;
        cout << "Year: "
        cin >> *pYear;
        *pTime = timeSinceLastContact (pMonth, pDay, pYear, pTimeUnits);
        ++friends;
        sortaddressbook//add this
        return friends;
    }

    int deleteContact (int friends, int deleteContact, contact *pArray)
    {
        for (int i = deleteContact + 1; i < friends; i++)
        {
            pArray.lastName[i] = pArray.lastName [i - 1];
            pArray.firstName[i] = pArray.firstName [i - 1];
            pArray.phone[i] = pArray.phone[i - 1];
            pArray.email[i] = pArray.email[i - 1];
            pArray.month[i] = pArray.month[i - 1];
            pArray.day[i] = pArray.day[i - 1];
            pArray.year[i] = pArray.year[i - 1];
            pArray.time[i] = pArray.time[i - 1];
            pArray.unitOfTime[i] = pArray.unitOfTime[i - 1];
        }
        pArray.lastName[friends - 1] = "";
        pArray.firstName[friends - 1] = "";
        pArray.phone[friends - 1] = "";
        pArray.email[friends - 1] = "";
        pArray.month[friends - 1] = 0;
        pArray.day[friends - 1] = 0;
        pArray.year[friends - 1] = 0;
        pArray.time[friends - 1] = 0;
        pArray.unitOfTime[friends - 1] = "";
        --friends;
        return friends;
    }

    sortAddressBook (contact *pArray, int friends)
    {
        contact *p1compare, *p2compare;
        bool unsorted = 0;
        string tempLast, tempFirst, tempPhone, tempEmail, tempUnitOfTime;
        int tempMonth, tempDay, tempYear, tempTime;
        do
        {
            for (int i = 0; i < friends; i++)
            {
                if (pArray.lastName[i] != "")
                    p1compare = pArray.lastName[i];
                else
                    p1compare = pArray.firstName[i];
                if (pArray.lastName[i + 1] == "")
                    p2compare = pArray.lastName[i];
                else
                    p2compare = pArray.firstName[i];
                if (p1compare < p2compare)
                {
                    tempLast = pArray.lastName [i];
                    tempFirst = pArray.firstName [i];
                    tempPhone = pArray.phone[i];
                    tempEmail = pArray.email[i];
                    tempMonth = pArray.month[i];
                    tempDay = pArray.day[i];
                    tempYear = pArray.year[i];
                    tempTime = pArray.time[i];
                    tempUnitOfTime = pArray.UnitOfTime[i + 1];
                    pArray.lastName[i] = pArray.lastName [i + 1];
                    pArray.firstName[i] = pArray.firstName [i + 1];
                    pArray.phone[i] = pArray.phone[i + 1];
                    pArray.email[i] = pArray.email[i + 1];
                    pArray.month[i] = pArray.month[i + 1];
                    pArray.day[i] = pArray.day[i + 1];
                    pArray.year[i] = pArray.year[i + 1];
                    pArray.time[i] = pArray.time[i + 1];
                    pArray.unitOfTime[i] = pArray.unitOfTime[i + 1];
                    pArray.lastName[i+ 1] = tempLast;
                    pArray.firstName[i + 1] = tempFirst;
                    pArray.phone[i + 1] = tempPhone;
                    pArray.email[i + 1] = tempEmail;
                    pArray.month[i + 1] = tempMonth
                    pArray.day[i + 1] = tempDay;
                    pArray.year[i + 1] = tempYear;
                    pArray.time[i + 1] = tempTime;
                    pArray.unitOfTime[i + 1] = tempUnitOfTime;
                    unsorted = 1;
                }
                else if (p1compare == p2compare)
                {
                    if (pArray.firstName[i] < pArray.firstName [i + 1])
                    {
                        tempLast = pArray.lastName [i];
                        tempFirst = pArray.firstName [i];
                        tempPhone = pArray.phone[i];
                        tempEmail = pArray.email[i];
                        tempMonth = pArray.month[i];
                        tempDay = pArray.day[i];
                        tempYear = pArray.year[i];
                        tempTime = pArray.time[i];
                        tempUnitOfTime = pArray.UnitOfTime[i + 1];
                        pArray.lastName[i] = pArray.lastName [i + 1];
                        pArray.firstName[i] = pArray.firstName [i + 1];
                        pArray.phone[i] = pArray.phone[i + 1];
                        pArray.email[i] = pArray.email[i + 1];
                        pArray.month[i] = pArray.month[i + 1];
                        pArray.day[i] = pArray.day[i + 1];
                        pArray.year[i] = pArray.year[i + 1];
                        pArray.time[i] = pArray.time[i + 1];
                        pArray.unitOfTime[i] = pArray.unitOfTime[i + 1];
                        pArray.lastName[i+ 1] = tempLast;
                        pArray.firstName[i + 1] = tempFirst;
                        pArray.phone[i + 1] = tempPhone;
                        pArray.email[i + 1] = tempEmail;
                        pArray.month[i + 1] = tempMonth
                        pArray.day[i + 1] = tempDay;
                        pArray.year[i + 1] = tempYear;
                        pArray.time[i + 1] = tempTime;
                        pArray.unitOfTime[i + 1] = tempUnitOfTime;
                        unsorted = 1;
                    }
                }
            }
        }while (unsorted)
    }

    editContact (int i, contact *pArray)
    {
        int option = -1;
        string tempS;
        int tempI;
        while (option)
        {
            cout << "To edit, enter the number of the parameter you would like to change." << endl << endl;
            cout << "1) First Name: " << pArray.firstName [i] << endl;
            cout << "2) Last Name: " << pArray.lastName [i] << endl;
            cout << "3) Phone #: " << pArray.phone [i] << endl;
            cout << "4) Email: " << pArray.email [i] << endl;
            cout << "5) Date of Last Contact: " << pArray.month [i] << "/" << pArray.day [i] << "/" << pArray.year << endl;
            cout << "To return, enter 0" << endl << endl;
            cin >> option;
            switch (option)
            {
            case 0:
                {
                    break;
                }
            case 1:
                {
                    cout << "Please enter the new first name: " << endl;
                    cin.ignore();
                    getline (cin, tempS);
                    pArray.firstName [i] = tempS;
                }
            case 2:
                {
                    cout << "Please enter the new last name: " << endl;
                    cin.ignore();
                    getline (cin, tempS);
                    pArray.lastName [i] = tempS;
                }
            case 3:
                {
                    cout << "Please enter the new phone #: " << endl;
                    cin.ignore();
                    getline (cin, tempS);
                    pArray.phone [i] = tempS;
                }
            case 4:
                {
                    cout << "Please enter the new email: " << endl;
                    cin.ignore();
                    getline (cin, tempS);
                    pArray.phone [i] = tempS;
                }
            case 5:
                {
                    cout << "Please enter the new date of last contact" << endl;
                    cout << "Month: ";
                    cin tempI;
                    while (tempI < 1 || tempI > 12)
                    {
                        cout << "Invalid selection, please try again." << endl;
                        cout << "Month: ";
                        cin tempI;
                    }
                    pArray.month [i] = tempI;
                    cout << "Day: ";
                    cin tempI;
                    bool retry = 0;
                    do
                    {
                        switch (pArray.month [i])
                        {
                        case 1:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        case 2:
                            {
                                if (tempI > 28 || tempI < 1)
                                    retry = 1;
                            }
                        case 3:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        case 4:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        case 5:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        case 6:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        case 7:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        case 8:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        case 9:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        case 10:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        case 11:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        case 12:
                            {
                                if (tempI > 31 || tempI < 1)
                                    retry = 1;
                            }
                        }
                    }
                    pArray.day [i] = tempI;
                    cout << "Year: ";
                    cin tempI;
                    pArray.year [i] = tempI;

                }
            }
        }
    }

    int searchFriends(string query, int arraySize, contact pAddressBook[], int selectContact = 0)
    {
        int i, matches[arraySize], match = 0, option = -1;

        for (i = 0; i < arraySize; i++)
        {
            if (query == pAddressBook.firstName[i] || query == pAddressBook.lastName[i] || query == pAddressBook.phone[i] || query == pAddressBook.email[i])
            {
                matches[match] = i;
                ++match;
                cout << match + 1 << ") " << pAddressBook.firstName[i] << " " << pAddressBook.lastName[i] << endl;
                cout << "  " << pAddressBook.phone[i] << endl;
                cout << "  " << pAddressBook.email[i] << endl;
                cout << "  " << pAddressBook.time[i] << " " << pAddressBook.unitOfTime[i] << "since last contact" << endl << endl;
            }
        }
        if (match != 0ghkb)// need to add additional section to skip this for edit and delete finctions)
        {
            cout << "If you would like to edit a contact from your search results, enter their number. To return to the menu, enter 0." << endl;
            cin >> option;
            while (option)
            {
                selectContact = option;
                cout << "If you would like to edit the contact, enter 1." << endl;
                cout << "To delete, enter 2." << endl;
                cout << "To return to the menu, enter 0." << endl;
                switch (option)
                {
                case 0:
                    {
                        return 0;
                    }
                case 1:
                    {
                        editContact (matches[selectContact]), //number to skip search for editContact function)
                        break;
                    }
                case 2:
                    {
                        deleteContact (matches[selectContact]), //number to skip search for deleteContact function)
                        break;
                    }
                }
            }
        }

        else
        {
            cout << "No contact by that name." << endl;
            cout << "To try again enter 1, to return to the menu enter 0." << endl;
            int newSearch
            cin newSearch;
            if (newSearch == 1);
            {
                cin.ignore();
                getline (cin, query);
                selectContact = searchFriends (query, arraySize, pAddressBook[]);
            }
        }
        return selectContact;
    }

    contact *growAddressBook (int &arraySize, contact *pointer)
    {
        arraySize *= 2;
        int* newPointer = new contact [arraySize];
        for (int i = 0; i < arraySize/2; i++)
        {
            newPointer.firstName [i] = pointer.firstName [i];
            newPointer.lastName [i] = pointer.lastName [i];
            newPointer.phone [i] = pointer.phone [i];
            newPointer.email [i] = pointer.email [i];
            newPointer.month [i] = pointer.month [i];
            newPointer.day [i] = pointer.day [i];
            newPointer.year [i] = pointer.year [i];
            newPointer.time [i] = pointer.time [i];
            newPointer.unitOfTime [i] = pointer.unitOfTime [i];
        }
        delete [] pointer;
        pointer = NULL;
        return newPointer;
    }
    int menu ()
    {
        int option;
        cout << "Please select from the following options" << endl << endl;
        cout << "1) Add Contact" << endl << "2) Edit existing contact" << endl << "3) Search Address Book" << endl <<
            "4) View list of contacts and time since last contact" << "0) Quit" << endl << endl;
        cin >> option;
        while (option > 4 || option < 0)
        {
            cout << "Invalid selection, please try again." << endl;
            cin >> option;
        }
        return option;
    }
}
int main()
{
    cout << "Welcome to your friends list and last contact tracker!" << endl;
    cout << "Keep track of when you last talked with each of your friends!" << endl;
    cout << "Please enter the information for your first contact." << endl;
    contact *pAddressBook = new int [2];
    string *pFirst = pAddressBook.firstName[0], *pLast = pAddressBook.lastName[0], *pPhone = pAddressBook.phone[0], *pEmail = pAddressBook.email[0],
        *pTimeUnits = pAddressBook.unitOfTime[0];
    int *pTime = pAddressBook.time[0], arraySize = 2, friends = 0, task, &sizeOfArray = arraySize;
    int *pMonth = pAddressBook.month[0], *pDay = pAddressBook.day[0], *pYear = pAddressBook.year[0];
    friends = addFriend (pFirst, pLast, pPhone, pEmail, pMonth, pDay, pYear, pTime, pTimeUnits);
    bool quit = 0;
    while (!quit)
    {
        task = menu ();
        switch (task)
        {
        case 0:
            {
                quit = 1;
                break;
            }
        case 1:
            {
                friends = addFriend (pFirst, pLast, pPhone, pEmail, pMonth, pDay, pYear, pTime, pTimeUnits);
                if (arraysize == friends)
                    pAddressBook = growArray(sizeOfArray, pAddressBook);
                break;
            }
        case 2:
            {

            }
        }
    }
}
