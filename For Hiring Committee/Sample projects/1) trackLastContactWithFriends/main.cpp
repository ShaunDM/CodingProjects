/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 14, Dynamic Memory Allocation
Problem 4

*******************************************************************************
Improvements

Having two arrays, one for the address book and one for favorites adds a lot of unnecessary complexity. Instead change struct contact.favorites to the element's own position in the array.
This will remove functions and make the program easier to handle. The only downside is that anytime favorites are accessed the program will have to go through the entire
address book every time. However, given the size of the average person's address book it might not be a big deal.
A happy medium might be to create a temporary array for the favorites so that the program only has to go through once and then update the main array once the user is finished.
Use faves and friends to change the limit of loops.

Possible additional features
Give the user the ability to set alarms if they haven't contacted one of their contacts in a certain amount of time.
Add the ability to track birthdays as well and use the alarm to alert them.
*/



#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

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
    bool isFavorite = 0;
    int favorite = -1;
};

//Functions
int menu ();//Main menu
int menuFav ();//Favorite's menu
void swapContact(struct contact *pArrC, int i);
string newInput (string original);//allows user to input contact information
int checkValidity (int value, int high, string parameter, int low);//checks whether user input is valid, changes range: low
int checkValidity (int value, int high, string parameter);//checks whether user input is valid
void printContact(int contact, struct contact *pArrC);//prints contact information for a single contact
int getDate (int type);//Can use this function to get the current date, but haven't covered it yet, stole from stack overflow
int timeSinceLastContact(int i, struct contact *pArrC);//calculates time since last contact, returns appropriate time passed and units
void editTimeSinceLastContact (int toEdit, struct contact *pArrC);//updates date since last contact for a single contact
void sortFavorites (int *pArrF, int &faves, struct contact *pArrC, int i);
//sorts favorites, if favorite is removed for any reason it also adjusts relevant variables such as faves
void sortAddressBook (struct contact *pArrC, int friends, int *pArrF, int &faves);
//sorts address book of user by last name, if not available - first name
int changeFavoriteStatus (int toEdit, int faves, int *pArrF, struct contact *pArrC);//reverses favorite status
int editFavorite (int toEdit, int *pArrF, int &faves, struct contact *pArrC, int friends, int &rSizeFavList, int option);
//allows user to edit favorite(s) in their favorite list
void addFavorite (int *pArrF, int &faves, int newFav, int &rArraySize); // adds contact to their favorite list
int addFriend (int friends, struct contact *pArrC, int *pArrF, int &faves, int &rSizeFavList);//adds friend to the addressBook
int deleteContact (int toDelete, struct contact *pArrC, int friends, int *pArrF, int &faves);
//deletes friend from the address book and removes from favorite list if applicable
int editContact (int toEdit, struct contact *pArrC, int friends, int *pArrF, int &faves, int &rSizeFavList, int option);// not done
//allows user to edit contacts in their address book
int printList (struct contact *pArrC, int friends);//Prints all contacts in the address book
int printList (int *pArrF, int faves, struct contact *pArrC);// prints favorites
int searchContacts(int friends, struct contact *pArrC, int *pArrF, int &faves, int &rSizeFavList);
//searches for a matching name in the address book, user can also print entire address book or favorite's list
struct contact *growArray (int &arraySize, struct contact *pointer); //grows address book array when it reaches capacity
int *growArray (int &arraySize, int *pointer); //grows favorite's array when capacity is reached
void initialize (int *ArrF, int arraySize, int low);
void initialize (struct contact *ArrC, int arraySize, int low);
void resetElement (struct contact *pArrC, int toReset);
int main()
{
    cout << "Welcome to your friends list and last contact tracker!" << endl;
    cout << "Keep track of when you last talked with each of your friends using your address book!" << endl;
    cout << "Please enter the information for your first contact." << endl;
    struct contact *pAddressBook = new struct contact [2];
    int *pFavList = new int [2];
    int sizeAddressBook = 2, sizeFavList = 2, friends = 0, faves = 0, task, &rSizeAddressBook = sizeAddressBook,
        &rSizeFavList = sizeFavList, toEdit = -2;
    initialize (pAddressBook, sizeAddressBook, friends);
    initialize (pFavList, sizeFavList, faves);
    bool quit = 0;
    while (!quit)
    {
        task = menu ();
        toEdit = -2;
        switch (task)
        {
        case 0:
            {
                quit = 1;
                break;
            }
        case 1:
            {
                friends = addFriend(friends, pAddressBook, pFavList, faves, rSizeAddressBook);
                if (sizeAddressBook == friends)
                    pAddressBook = growArray(rSizeAddressBook, pAddressBook);
                if (faves == sizeFavList)
                    pFavList = growArray(rSizeFavList, pFavList);
                break;
            }
        case 2:
            {
                toEdit = printList(pAddressBook, friends);
                friends = editContact(toEdit, pAddressBook, friends, pFavList, faves, rSizeFavList, -1);
                break;
            }
        case 3:
            {
                friends = searchContacts(friends, pAddressBook, pFavList, faves, rSizeFavList);
                break;
            }
        case 4:
            {
                toEdit = printList (pFavList, faves, pAddressBook);
                friends = editFavorite (toEdit, pFavList, faves, pAddressBook, friends, rSizeFavList, 1);
                break;
            }
        case 5:
            {
                friends = editFavorite (toEdit, pFavList, faves, pAddressBook, friends, rSizeFavList, -1);
                break;
            }
        }
    }
    return 0;
}

int menu ()
{
    int option;
    cout << "Please select an option." << endl << endl;
    cout << "1) Add contact" << endl;
    cout << "2) View contacts" << endl;
    cout << "3) Search contacts" << endl;
    cout << "4) Met a friend in my favorite's list, update the tracker" << endl;
    cout << "5) Edit favorite's list" << endl;
    cout << "To quit, enter 0" << endl << endl;
    cin >> option;
    cout << endl;
    option = checkValidity(option, 5, "menu selection");
    return option;
}
int menuFav ()
{
    int option;
    cout << "1) Update last contact tracker." << endl;
    cout << "2) Edit contact." << endl;
    cout << "3) Unfavorite." << endl;
    cout << "To cancel, enter 0 at any time." << endl;
    cin >> option;
    option = checkValidity(option, 3, "menu selection");
    return option;
}
void swapContact (struct contact *pArrC, int i)
{
    string tempLast = pArrC[i].lastName;
    string tempFirst = pArrC[i].firstName;
    string tempPhone = pArrC[i].phone;
    string tempEmail = pArrC[i].email;
    int tempMonth = pArrC[i].month;
    int tempDay = pArrC[i].day;
    int tempYear = pArrC[i].year;
    int tempTime = pArrC[i].time;
    string tempUnitOfTime = pArrC[i].unitOfTime;
    int tempFav = pArrC[i].favorite;
    bool tempIsFav = pArrC[i].isFavorite;
    pArrC[i].lastName = pArrC[i + 1].lastName;
    pArrC[i].firstName = pArrC[i + 1].firstName;
    pArrC[i].phone = pArrC[i + 1].phone;
    pArrC[i].email = pArrC[i + 1].email;
    pArrC[i].month = pArrC[i + 1].month;
    pArrC[i].day = pArrC[i + 1].day;
    pArrC[i].year = pArrC[i + 1].year;
    pArrC[i].time = pArrC[i + 1].time;
    pArrC[i].unitOfTime = pArrC[i + 1].unitOfTime;
    pArrC[i].favorite = pArrC[i + 1].favorite;
    pArrC[i].isFavorite = pArrC[i + 1].isFavorite;
    pArrC[i+ 1].lastName = tempLast;
    pArrC[i+ 1].firstName = tempFirst;
    pArrC[i+ 1].phone = tempPhone;
    pArrC[i+ 1].email = tempEmail;
    pArrC[i+ 1].month = tempMonth;
    pArrC[i+ 1].day = tempDay;
    pArrC[i+ 1].year = tempYear;
    pArrC[i+ 1].time = tempTime;
    pArrC[i+ 1].unitOfTime = tempUnitOfTime;
    pArrC[i+ 1].favorite = tempFav;
    pArrC[i+ 1].isFavorite = tempIsFav;
}
string newInput (string original)
{
    string tempS;
    cin.ignore();
    getline (cin, tempS);
    if (tempS == "0")
        return original;
    return tempS;
}
int checkValidity (int value, int high, string parameter, int low)
{
    while ((value < low || value > high) && value != 0)
    {
        cout << "Invalid selection, " << parameter << ". Please try again. To cancel, enter 0 at any time." << endl;
        cout << parameter << ": ";//fix, when learn substrings can capitalize
        cin >> value;
        cout << endl;
    }
    return value;
}
int checkValidity (int value, int high, string parameter)
{
    int low = 0;
    while (value < low || value > high)
    {
        cout << "Invalid selection, " << parameter << ". Please try again. To cancel, enter 0 at any time." << endl;
        cout << parameter << ": ";//fix, when learn substrings can capitalize
        cin >> value;
        cout << endl;
    }
    return value;
}
void printContact(int toPrint, struct contact *pArrC)
{
    pArrC[toPrint].time = timeSinceLastContact(toPrint, pArrC);
    if (pArrC[toPrint].isFavorite)
        cout << "* ";
    cout << pArrC[toPrint].firstName << " " << pArrC[toPrint].lastName << endl;
    cout << "  " << pArrC[toPrint].phone << endl;
    cout << "  " << pArrC[toPrint].email << endl;
    cout << "  " << "Last contact: " << pArrC[toPrint].month  << "/" << pArrC[toPrint].day  << "/" << pArrC[toPrint].year << endl;
    cout << "  " << pArrC[toPrint].time << " " << pArrC[toPrint].unitOfTime << " since last contact" << endl << endl;
}
int getDate (int type)
{// Can use this function to get the current date, but haven't covered it yet, stole from stack overflow
    typedef std::chrono::system_clock Clock;

    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *parts = std::localtime(&now_c);
    switch (type)
    {
    case 0:
        {
            return 1 + parts->tm_mon;
        }
    case 1:
        {
            return parts->tm_mday;
        }
    case 2:
        {
            return 1900 + parts->tm_year;
        }
    }
}
int timeSinceLastContact(int i, struct contact *pArrC)
{// calculates time since last contact, returns appropriate time passed and units
    int days, months, years;
    int currentMonth = getDate (0), currentDay = getDate (1), currentYear = getDate (2);
    if (currentDay < pArrC[i].day)
    {//'carries over' month before finding difference in days passed
        if (currentMonth != 1)
            --currentMonth;
        else
        {
           currentMonth = 12;
           --currentYear;
        }

        switch (currentMonth)
        {
        case 1:
            {

            }
        case 3:
            {

            }
        case 5:
            {

            }
        case 7:
            {

            }
        case 8:
            {

            }
        case 10:
            {

            }
        case 12:
            {
                days = currentDay + 31 - pArrC[i].day;
                break;
            }
        case 2:
            {
                if (currentYear % 4 != 0)
                    days = currentDay + 28 - pArrC[i].day;
                else
                    days = currentDay + 29 - pArrC[i].day;
                break;
            }
        case 4:
            {

            }
        case 6:
            {

            }
        case 9:
            {

            }
        case 11:
            {
                days = currentDay + 30 - pArrC[i].day;
                break;
            }
        }
    }
    else
        days = currentDay - pArrC[i].day;
    if (currentMonth < pArrC[i].month)
    {
       months = currentMonth + 12 - pArrC[i].month;
       --currentYear;
    }
    else
        months = currentMonth - pArrC[i].month;
    years = currentYear - pArrC[i].year;
    if (years)
    {
        pArrC[i].unitOfTime = "yrs";
        return years;
    }
    else if (months)
    {
        pArrC[i].unitOfTime = "mths";
        return months;
    }
    else
    {
        pArrC[i].unitOfTime = "days";
        return days;
    }
}
void editTimeSinceLastContact(int toEdit, struct contact *pArrC)
{
    cout << "Please choose an option." << endl;
    cout << "If you'd like to use the current date, enter 1" << endl;
    cout << "To manually enter the date, enter 2" << endl;
    cout << "To cancel, enter 0 at any time" << endl;
    int select, tempM, tempD, tempY;
    cin >> select;
    cout << endl;
    select = checkValidity (select, 2, "option");
    switch (select)
    {
    case 0:
        {
            break;
        }
    case 1:
        {
            pArrC[toEdit].month = getDate(0), pArrC[toEdit].day = getDate(1), pArrC[toEdit].year = getDate(2);
            break;
        }
    case 2:
        {
            cout << "Please enter the date of last contact" << endl;
            cout << "Month: ";
            cin >> tempM;
            cout << "Day: ";
            cin >> tempD;
            cout << "Year: ";
            cin >> tempY;
            cout << endl;
            tempM = checkValidity (tempM, 12, "month");
            if (!tempM)
                break;
            switch (tempM) // evaluates if day is valid
            {
            case 0:
                {
                    break;
                }

            case 1:
                {

                }
            case 3:
                {

                }
            case 5:
                {

                }
            case 7:
                {

                }
            case 8:
                {

                }
            case 10:
                {

                }
            case 12:
                {
                    tempD = checkValidity(tempD, 31, "day");
                    break;
                }
            case 2:
                {
                    if (tempY % 4 != 0)
                    {
                        tempD = checkValidity(tempD, 28, "day");
                    }
                    else
                    {
                        tempD = checkValidity(tempD, 29, "day");
                    }
                    break;
                }
            case 4:
                {

                }
            case 6:
                {

                }
            case 9:
                {

                }
            case 11:
                {
                    tempD = checkValidity(tempD, 30, "day");
                    break;
                }
            }
            if (!tempD)
                break;
            tempY = checkValidity(tempY, getDate(2), "year", getDate(2) - 125);
            if (!tempY)
                break;
            pArrC[toEdit].month = tempM, pArrC[toEdit].day = tempD, pArrC[toEdit].year = tempY;
            break;
        }
    }
    pArrC[toEdit].time = timeSinceLastContact(toEdit, pArrC);
}
void sortFavorites (int *pArrF, int &faves, struct contact *pArrC, int i = -1)
{//sorts favorites, if favorite is removed for any reason it also adjusts relevant variables such as faves
    int tempI;
    bool unsorted = 0;
    if (i == -1)
    {
        do
        {
            unsorted = 0;
            for (i = 0; i < faves - 1; i++)
            {
                if (pArrF[i] > pArrF[i + 1])
                {
                    tempI = pArrF[i];
                    pArrF[i] = pArrF[i + 1];
                    pArrF[i + 1] = tempI;
                    pArrC[pArrF[i]].favorite = i + 1;
                    pArrC[pArrF[i + 1]].favorite = i;
                    unsorted = 1;
                }
            }
        }while (unsorted);
    }
    else
    {
        pArrC[pArrF[i]].isFavorite = 0;
        for (i; i < faves - 1; i++)
        {
            pArrF[i] = pArrF[i + 1];
            pArrC[pArrF[i]].favorite = i;
        }
        --faves;
        pArrF[faves] = -1;
    }
}
void sortAddressBook (struct contact *pArrC, int friends, int *pArrF, int &faves)
{
    string p1compare, p2compare;
    bool unsorted = 0;
    do
    {
        unsorted = 0;
        for (int i = 0; i < friends - 1; i++)
        {
            if (pArrC[i].lastName != "")
                p1compare = pArrC[i].lastName;
            else
                p1compare = pArrC[i].firstName;
            if (pArrC[i + 1].lastName != "")
                p2compare = pArrC[i + 1].lastName;
            else
                p2compare = pArrC[i + 1].firstName;
            if (p1compare == p2compare)
            {
                if (p1compare == pArrC[i].lastName && p2compare == pArrC[i + 1].firstName)//If no last name is listed, manages sort
                    p2compare = "";
                else if (p2compare == pArrC[i + 1].lastName && p1compare == pArrC[i].firstName)
                    p1compare = "";
                else if (pArrC[i].firstName < pArrC[i + 1].firstName)
                {
                    swapContact (pArrC, i);
                    unsorted = 1;
                }
            }
            if (p1compare > p2compare)
            {
                swapContact (pArrC, i);
                unsorted = 1;
            }
        }
    }while (unsorted);
    sortFavorites(pArrF, faves, pArrC, -1);
}
int changeFavoriteStatus (int toEdit, int faves, int *pArrF, struct contact *pArrC)
{//when this function is called need to add 'check selection' to ensure vaild
    char confirm = 'a';
    if (pArrC[toEdit].isFavorite)
    {
        while (confirm != 'y' && confirm != 'n')
        {
            cout << "Remove " << pArrC[pArrF[toEdit]].firstName << " " << pArrC[pArrF[toEdit]].lastName;
            cout << " from your favorites list? (y/n): ";
            cin >> confirm;
        }
        if (confirm == 'n')
            return faves;
        pArrC[pArrF[toEdit]].isFavorite = 0;
        pArrC[pArrF[toEdit]].favorite = -1;
        sortFavorites(pArrF, faves, pArrC, toEdit);
    }
    else
    {
        pArrF[faves] = toEdit;
        pArrC[pArrF[faves]].isFavorite = 1;
        ++faves;
        cout << pArrC[pArrF[toEdit]].firstName << " " << pArrC[pArrF[toEdit]].lastName << " added to your favorites" << endl;
        sortFavorites(pArrF, faves, pArrC);
    }
    return faves;
}
int editFavorite (int toEdit, int *pArrF, int &faves, struct contact *pArrC, int friends, int &rSizeFavList, int option = -1)
{
    if (toEdit == -1)
        return friends;
    if (option == -1)
    {
        toEdit = printList (pArrF, faves, pArrC);
        if (toEdit == -1)
            return friends;
        option = menuFav();
    }
    else if (option == -2)
    {
        option = menuFav();
    }
    switch (option)
    {
    case 0:
        {
            return friends;
        }
    case 1://updates date for tracker
        {
            printContact(pArrF[toEdit], pArrC);
            editTimeSinceLastContact(pArrF[toEdit], pArrC);
            printContact(pArrF[toEdit], pArrC);
            toEdit = printList (pArrF, faves, pArrC);
            break;
        }
    case 2:
        {
            friends = editContact(pArrF[toEdit], pArrC, friends, pArrF, faves, rSizeFavList, -1);
            toEdit = printList (pArrF, faves, pArrC);
            break;
        }
    case 3:
        {
            friends = editContact(pArrF[toEdit], pArrC, friends, pArrF, faves, rSizeFavList, 6);
            toEdit = printList (pArrF, faves, pArrC);
            break;
        }
    }
    friends = editFavorite(toEdit, pArrF, faves, pArrC, friends, rSizeFavList, option = -2);
    return friends;
}
void addFavorite (int *pArrF, int &faves, int newFav, int &rArraySize)
{
    pArrF[faves] = newFav;
    ++faves;
}
int addFriend (int friends, struct contact *pArrC, int *pArrF, int &faves, int &rSizeFavList)
{
    char fav;
    cout << "New friend's contact information" << endl;
    cout << "First Name: ";
    cin >> pArrC[friends].firstName;
    cout << "Last Name: ";
    cin >> pArrC[friends].lastName;
    cout << "Phone #: ";
    cin.ignore();
    getline (cin, pArrC[friends].phone);
    cout << "Email: ";
    getline (cin, pArrC[friends].email);
    cout << endl;
    editTimeSinceLastContact (friends, pArrC);
    pArrC[friends].time = timeSinceLastContact(friends, pArrC);
    cout << "Add to favorites list (y/n)" << endl;
    cin >> fav;
    if (fav == 'y')
    {
        pArrC[friends].isFavorite = 1;
        pArrC[friends].favorite = faves;
        addFavorite (pArrF, faves, friends, rSizeFavList);
    }
    ++friends;
    sortAddressBook(pArrC, friends, pArrF, faves);
    cout << endl;
    return friends;
}
int deleteContact(int toDelete, struct contact *pArrC, int friends, int *pArrF, int &faves)
{
    char confirm = 'a';
    while (confirm != 'y' && confirm != 'n')
    {
      cout << "Delete " << pArrC[toDelete].firstName << " " << pArrC[toDelete].lastName << "? (y/n): ";
      cin >> confirm;
    }
    if (confirm == 'n')
        return friends;
    if (pArrC[toDelete].isFavorite)
    {
        sortFavorites(pArrF, faves, pArrC, pArrC[toDelete].favorite);
    }
    for (int i = toDelete; i < friends - 1; i++)
    {
        pArrC[i].lastName = pArrC[i + 1].lastName;
        pArrC[i].firstName = pArrC[i + 1].firstName;
        pArrC[i].phone = pArrC[i + 1].phone;
        pArrC[i].email = pArrC[i + 1].email;
        pArrC[i].month = pArrC[i + 1].month;
        pArrC[i].day = pArrC[i + 1].day;
        pArrC[i].year = pArrC[i + 1].year;
        pArrC[i].time = pArrC[i + 1].time;
        pArrC[i].unitOfTime = pArrC[i + 1].unitOfTime;
        if (pArrC[i + 1].isFavorite)
        {
            pArrC[i].favorite = pArrC[i + 1].favorite;
            pArrC[i].isFavorite = pArrC[i + 1].isFavorite;
            pArrF[pArrC[i].favorite] = i;
        }
    }
    --friends;
    resetElement(pArrC, friends);
    return friends;
}
int editContact(int toEdit, struct contact *pArrC, int friends, int *pArrF, int &faves, int &rSizeFavList, int option = -1)// not done
{
    bool skip = 0;
    if (option != -1)
        skip = 1;
    if (toEdit < 0)
    {
        return friends;
    }
    string tempS;
    while (option)
    {
        if (option == -1)
        {
            cout << "To edit, enter the number/letter of the parameter you would like to change." << endl;
            cout << "To cancel, enter 0 at any time." << endl << endl;
            cout << "1) First Name: " << pArrC[toEdit].firstName << endl;
            cout << "2) Last Name: " << pArrC[toEdit].lastName << endl;
            cout << "3) Phone #: " << pArrC[toEdit] .phone << endl;
            cout << "4) Email: " << pArrC[toEdit].email << endl;
            cout << "5) Date of Last Contact: " << pArrC[toEdit].month << "/" << pArrC[toEdit].day << "/" << pArrC[toEdit].year;
            cout << ", " << pArrC[toEdit].time << " " << pArrC[toEdit].unitOfTime << " since last contact." << endl;
            if (!pArrC[toEdit].isFavorite)
                cout << "6) Favorite" << endl;
            else
                cout << "6) Unfavorite" << endl;
            cout << "7) Delete contact" << endl;
            cout << "0) Return" << endl << endl;
            cout << "Select #";
            cin >> option;
        }
        option = checkValidity(option, 7, "menu selection");
        switch (option)
        {
        case 0:
            {
                break;
            }
        case 1:
            {
                cout << "Please enter the new first name: ";
                pArrC[toEdit].firstName = newInput(pArrC[toEdit].firstName);
                break;
            }
        case 2:
            {
                cout << "Please enter the new last name: ";
                pArrC[toEdit].lastName = newInput(pArrC[toEdit].lastName);
                break;
            }
        case 3:
            {
                cout << "Please enter the new phone #: ";
                pArrC[toEdit].phone = newInput(pArrC[toEdit].phone);
                break;
            }
        case 4:
            {
                cout << "Please enter the new email: ";
                pArrC[toEdit].email = newInput(pArrC[toEdit].email);
                break;
            }
        case 5:
            {
                editTimeSinceLastContact(toEdit, pArrC);
                break;
            }
        case 6:
            {
                faves = changeFavoriteStatus (toEdit, faves, pArrF, pArrC);
                if (faves == rSizeFavList)
                {
                    pArrF = growArray(rSizeFavList, pArrF);
                }
                break;
            }
        case 7:
            {
                friends = deleteContact(toEdit, pArrC, friends, pArrF, faves);
                return friends;
            }
        default:
            {
                cout << "Invalid selection, please try again." << endl;
                break;
            }
        }
        cout << endl;
        if (!option)
            break;
        else if (skip)
            break;
        else
            option = -1;
    }
    sortAddressBook(pArrC, friends, pArrF, faves);
    return friends;
}
int printList (struct contact *pArrC, int friends)
{//Prints all friends
    int select;
    if (!friends)
    {
        cout << "No contacts saved in the address book" << endl;
        return -1;
    }
    for (int i = 0; i < friends; i++)
    {
        if (pArrC[i].isFavorite)
            cout << "* ";
        cout << i + 1 << ") ";
        cout << pArrC[i].firstName << " " << pArrC[i].lastName << endl;
    }
    cout << endl;
    cout << "To select a friend to update, enter the number next to their name. To return to the menu enter 0 at any time." << endl;
    cin >> select;
    cout << endl;
    return select - 1;
}
int printList (int *pArrF, int faves, struct contact *pArrC)
{//prints favorites
    int toEdit;
    if (!faves)
    {
        cout << "No favorites designated among contacts" << endl;
        return -1;
    }
    for (int i = 0; i < faves; i++)
    {
        cout << i + 1 << ") ";
        cout << pArrC[pArrF[i]].firstName << " " << pArrC[pArrF[i]].lastName << endl;
    }
    cout << endl;
    cout << "To select a favorite to update, enter the number next to their name. To return to the menu enter 0 at any time." << endl;
    cin >> toEdit;
    cout << endl;
    toEdit = checkValidity (toEdit, faves, "favorite");
    toEdit--;
    return toEdit;
}
int searchContacts(int friends, struct contact *pArrC, int *pArrF, int &faves, int &rSizeFavList)
{
    string query;
    int toEdit = -2;
    cout << "To view all friends search 'all'; to view your favorites search 'favorites'." << endl;
    cout << "Search: ";
    cin.ignore();
    getline(cin, query);
    if (query == "all")
    {
        while (toEdit != -1)
        {
            toEdit = printList(pArrC, friends);
            friends = editContact(toEdit, pArrC, friends, pArrF, faves, rSizeFavList);
        }
        return friends;
    }
    if (query == "favorites")
    {
        while (toEdit != -1)
        {
            toEdit = printList (pArrF, faves, pArrC);
            friends =  editFavorite (toEdit, pArrF, faves, pArrC, friends, rSizeFavList, -1);
        }
        return friends;
    }
    int i, matches[friends], match = 0;
    do
    {
        for (i = 0; i < friends; i++)
        {
            if (query == pArrC[i].firstName || query == pArrC[i].lastName || query == pArrC[i].phone || query == pArrC[i].email)
            {
                matches[match] = i;
                ++match;
                cout << match << ") ";
                printContact(i, pArrC);
            }
        }
        if (match != 0)// need to add additional section to skip this for edit and delete functions)
        {
            while (toEdit != -1)
            {
                cout << "If you would like to edit a contact from your search results, enter the number next to their name. To return to the menu, enter 0." << endl;
                cin >> toEdit;
                toEdit = checkValidity(toEdit, match, "Selection");
                toEdit--;
                if (toEdit == -1)
                    break;
                toEdit = matches[toEdit];
                friends = editContact(toEdit, pArrC, friends, pArrF, faves, rSizeFavList);
                match = 0;
                for (i = 0; i < friends; i++)
                {
                    if (query == pArrC[i].firstName || query == pArrC[i].lastName || query == pArrC[i].phone || query == pArrC[i].email)
                    {
                        matches[match] = i;
                        ++match;
                        cout << match << ") ";
                        printContact(i, pArrC);
                    }
                }
            }
        }
        else
        {
            cout << "No contact by that name." << endl;
            cout << "To search again enter 1, to return to the menu enter 0." << endl;
            cin >> toEdit;
            if (toEdit)
            {
                cin.ignore();
                getline (cin, query);
                friends = searchContacts (friends, pArrC, pArrF, faves, rSizeFavList);
                break;
            }
            toEdit--;
        }
    }while (toEdit != -1);
    return friends;
}
void resetElement (struct contact *pArrC, int toReset)
{
    pArrC[toReset].lastName = "";
    pArrC[toReset].firstName = "";
    pArrC[toReset].phone = "";
    pArrC[toReset].email = "";
    pArrC[toReset].month = 0;
    pArrC[toReset].day = 0;
    pArrC[toReset].year = 0;
    pArrC[toReset].time = 0;
    pArrC[toReset].unitOfTime = "";
    pArrC[toReset].isFavorite = 0;
    pArrC[toReset].favorite = -1;
}
void initialize (int *pArrF, int arraySize, int low)
{
    for (int i = low; i < arraySize; i++)
    {
        pArrF[i] = -1;
    }
}
void initialize (struct contact *pArrC, int arraySize, int low)
{
    for (int i = low; i < arraySize; i++)
    {
        resetElement (pArrC, i);
    }
}
struct contact *growArray (int &arraySize, struct contact *pointer)
{
    arraySize *= 2;
    struct contact* newPointer = new struct contact [arraySize];
    for (int i = 0; i < arraySize/2; i++)
    {
        newPointer[i].firstName  = pointer[i].firstName;
        newPointer[i].lastName  = pointer[i].lastName;
        newPointer[i].phone  = pointer[i].phone;
        newPointer[i].email  = pointer[i].email;
        newPointer[i].month  = pointer[i].month;
        newPointer[i].day  = pointer[i].day;
        newPointer[i].year  = pointer[i].year;
        newPointer[i].time  = pointer[i].time;
        newPointer[i].unitOfTime  = pointer[i].unitOfTime;
        newPointer[i].isFavorite = pointer[i].isFavorite;
        newPointer[i].favorite = pointer[i].favorite;
    }
    delete [] pointer;
    pointer = NULL;
    return newPointer;
}
int *growArray (int &arraySize, int *pointer)
{
    arraySize *= 2;
    int* newPointer = new int [arraySize];
    for (int i = 0; i < arraySize/2; i++)
    {
        newPointer[i]  = pointer[i];
        newPointer[i]  = pointer[i];
    }
    delete [] pointer;
    pointer = NULL;
    return newPointer;
}
