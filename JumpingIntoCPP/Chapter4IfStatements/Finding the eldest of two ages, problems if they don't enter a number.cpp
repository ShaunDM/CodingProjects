/*
Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 4 If Statements
Problem 1
*/

#include <iostream>

using namespace std;

int age_verify(int &age){
    if (age < 0 || age > 120){
        cout << "Please put in a legitimate age!" << endl << "Retry: ";
        cin >> age;
    }
        while (age < 0 || age > 120){
            cout << "Retry: ";
            cin >> age;
        }
    return age;
}

int age_verify(string age){
    int actual_age;
    cout << "This is not a number!" << endl << "Retry: ";
    cin >> actual_age;
    age_verify(actual_age);
    return actual_age;
}

int main (void) {
    int age1, age2;
    cout << "Input two ages in years and I will tell you which one is larger." << endl;
    cout << "First age: ";
    cin >> age1;
    age_verify (age1);
    cout << "Second age: ";
    cin >> age2;
    age_verify (age2);
    if (age1 > 100 && age2 > 100) {
        cout << "Damn they're old.";
        return 0;
    }
    int eldest = age1;
    if (age1 < age2)
        eldest = age2;
    else if (age1 == age2){
        cout << "They are the same age." << endl;
        return 0;
    }
    cout << "The eldest is: " << eldest << endl;
    cout << age1 << endl;
    cout << age2 << endl;
    return 0;
}
