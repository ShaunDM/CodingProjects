/*
Creator: Shaun McRae
Jumping Into C++ by Alex Allain
Chapter 9
Problem 1
*/

#include <iostream>

using namespace std;

string less_than_20(int number)
{
    string conversion;
    switch (number)
    {
    case 0:
        {
            conversion = "";
            break;
        }
    case 1:
        {
            conversion = "One ";
            break;
        }
    case 2:
        {
            conversion = "Two ";
            break;
        }
    case 3:
        {
            conversion = "Three ";
            break;
        }
    case 4:
        {
            conversion = "Four ";
            break;
        }
    case 5:
        {
            conversion = "Five ";
            break;
        }
    case 6:
        {
            conversion = "Six ";
            break;
        }
    case 7:
        {
            conversion = "Seven ";
            break;
        }
    case 8:
        {
            conversion = "Eight ";
            break;
        }
    case 9:
        {
            conversion = "Nine ";
            break;
        }
    case 10:
        {
            conversion = "Ten ";
            break;
        }
    case 11:
        {
            conversion = "Eleven ";
            break;
        }
    case 12:
        {
            conversion = "Twelve ";
            break;
        }
    case 13:
        {
            conversion = "Thirteen ";
            break;
        }
    case 14:
        {
            conversion = "Fourteen ";
            break;
        }
    case 15:
        {
            conversion = "Fifteen ";
            break;
        }
    case 16:
        {
            conversion = "Sixteen ";
            break;
        }
    case 17:
        {
            conversion = "Seventeen ";
            break;
        }
    case 18:
        {
            conversion = "Eighteen ";
            break;
        }
    case 19:
        {
            conversion = "Nineteen ";
            break;
        }
    }
    return conversion;
}

string tens (int number)
{
    string conversion;
    switch (number)
    {
    case 0:
        {

        }
    case 1:
        {
            conversion = less_than_20(number);
            break;
        }

    case 2:
        {
            conversion = "Twenty ";
            break;
        }
    case 3:
        {
            conversion = "Thirty ";
            break;
        }
    case 4:
        {
            conversion = "Forty ";
            break;
        }
    case 5:
        {
            conversion = "Fifty ";
            break;
        }
    case 6:
        {
            conversion = "Sixty ";
            break;
        }
    case 7:
        {
            conversion = "Seventy ";
            break;
        }
    case 8:
        {
            conversion = "Eighty ";
            break;
        }
    case 9:
        {
            conversion = "Ninety ";
            break;
        }
    default:
        {
            cout << "Error " << endl;
            conversion = "Error ";
            break;
        }
    return conversion;
    }
}

int main()
{
    cout << "Input an integer less than |1,000,000| and I will translate it into text!" << endl;
    int number;
    cin >> number;
    while (number >= 1000000 || number <= -1000000)
    {
        cout << "Invalid entry, try again" << endl;
        cin >> number;
    }
    if (number == 0)
        {
           cout << "Zero" << endl;
           return 0;
        }
    int absolute, var_switch;
    string hundred_thousand = "", ten_thousand = "", thousand = "", hundred = "", ten = "", one = "";
    if(number < 0)
    {
        cout << "Negative ";
        absolute = number * -1;
    }
    else
        absolute = number;
    if (absolute >= 100000)
        var_switch = 0;
    else if(absolute >= 10000)
        var_switch = 1;
    else if (absolute >= 1000)
        var_switch = 2;
    else if (absolute >= 100)
        var_switch = 3;
    else if (absolute >= 20)
        var_switch = 4;
    else
        var_switch = 5;
    int rid6 = 0, rid5 = 0, rid4 = 0, rid3 = 0, rid2 = 0, rid1 = 0;
    switch (var_switch)
    {
    case 0:
        {
        rid6 = absolute/100000;
        hundred_thousand = less_than_20(rid6);
        rid6 = rid6 * 100000;
        }
    case 1:
        {
            rid5 = (absolute - rid6)/1000;
            if (rid5 < 20)
                {
                ten_thousand = less_than_20(rid5);
                rid5 *= 1000;
                }
            else
            {
                rid5 /= 10;
                ten_thousand = tens(rid5);
                rid5 *= 10000;
            }
        }
    case 2:
        {
            if (rid5 <= 20000)
            {

            }
            else
            {
               rid4 = (absolute - rid6 - rid5)/1000;
                thousand = less_than_20(rid4);
                rid4 *= 1000;
            }

        }
    case 3:
        {
        rid3 = (absolute - rid6 - rid5 - rid4)/100;
        hundred = less_than_20(rid3);
        rid3 = rid3 * 100;
        }
    case 4:
        {
            rid2 = (absolute - rid6 - rid5 - rid4 - rid3);
            if (rid2 < 20)
                {
                ten = less_than_20(rid2);
                }
            else
            {
                rid2 /= 10;
                ten = tens(rid2);
                rid2 *= 10;
            }
        }
    case 5:
        {
            if (rid2 <= 20)
                break;
            rid1 = (absolute - rid6 - rid5 - rid4 - rid3 - rid2);
            one = less_than_20(rid1);
        }
    }
    string name_hundred_thousand = "", name_thousand = "", name_hundred = "";
    if (absolute >= 100000)
        name_hundred_thousand = "Hundred ";
    if (absolute >= 1000)
        name_thousand = "Thousand ";
    if (absolute >= 100)
        name_hundred = "Hundred ";
    cout << hundred_thousand << name_hundred_thousand << ten_thousand << thousand << name_thousand << hundred << name_hundred << ten << one << endl;

    return 0;
}
