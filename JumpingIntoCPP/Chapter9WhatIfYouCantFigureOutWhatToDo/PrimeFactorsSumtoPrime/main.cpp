/*
Creator: Shaun McRae
Jumping Into C++ by Alex Allain
Chapter 9
Problem 3
*/

#include <iostream>
#include <cmath>

using namespace std;

void evaluateIfSumIsPrime (int sum, int number)
{
    if (sum > 1000)
    {
        cout << "Need higher i in evaluate" << endl;
    }
    int isPrime = 0;
    for(int i = 3; i < 1000; i++)
    {
        for(int j = 2; j <= sqrt(i); j++)
        {
            isPrime = 0;
            if (i % j == 0)
            {
                isPrime = 1;
                break;
            }

        }
        if (isPrime == 0)
        {
            if (i == sum)
                cout << number << " " << sum << endl;
        }
    }
}


int main()
{

    int factor1 = 0, factor2 = 0, factor3 = 0, factor4 = 0, factor5 = 0, factor6 = 0, factor7 = 0, factor8 = 0, factor9 = 0, factor10 = 0;
    for (int i = 2; i < 1001; i++)
    {
        int factor1 = 0, factor2 = 0, factor3 = 0, factor4 = 0, factor5 = 0, factor6 = 0, factor7 = 0, factor8 = 0, factor9 = 0, factor10 = 0;
        int factorCounter = 0, dividend = i;
        while (dividend % 2 == 0)
        {
            dividend /= 2;
            switch (factorCounter)
            {
            case 0:
                {
                    factor1 = 2;
                    break;
                }
            case 1:
                {
                    factor2 = 2;
                    break;
                }
            case 2:
                {
                    factor3 = 2;
                    break;
                }
            case 3:
                {
                    factor4 = 2;
                    break;
                }
            case 4:
                {
                    factor5 = 2;
                    break;
                }
            case 5:
                {
                    factor6 = 2;
                    break;
                }
            case 6:
                {
                    factor7 = 2;
                    break;
                }
            case 7:
                {
                    factor8 = 2;
                    break;
                }
            case 8:
                {
                    factor9 = 2;
                    break;
                }
            case 9:
                {
                    factor10 = 2;
                    break;
                }
            default:
                {
                  cout << "Not enough" << endl;
                }
            }
            ++factorCounter;
        }
        for(int j = 3; j <= sqrt(dividend); j += 2)
        {
            while(dividend % j == 0)
            {
                dividend /= j;
                switch (factorCounter)
                {
                case 0:
                    {
                        factor1 = j;
                        break;
                    }
                case 1:
                    {
                        factor2 = j;
                        break;
                    }
                case 2:
                    {
                        factor3 = j;
                        break;
                    }
                case 3:
                    {
                        factor4 = j;
                        break;
                    }
                case 4:
                    {
                        factor5 = j;
                        break;
                    }
                case 5:
                    {
                        factor6 = j;
                        break;
                    }
                case 6:
                    {
                        factor7 = j;
                        break;
                    }
                case 7:
                    {
                        factor8 = j;
                        break;
                    }
                case 8:
                    {
                        factor9 = j;
                        break;
                    }
                case 9:
                    {
                        factor10 = j;
                        break;
                    }
                default:
                    {
                        cout << "Not enough" << endl;
                    }
                }
            ++factorCounter;
            }
        }
        if (dividend != 1 && dividend != i)
        {
            switch (factorCounter)
            {
            case 0:
                {
                    factor1 = dividend;
                    break;
                }
            case 1:
                {
                    factor2 = dividend;
                    break;
                }
            case 2:
                {
                    factor3 = dividend;
                    break;
                }
            case 3:
                {
                    factor4 = dividend;
                    break;
                }
            case 4:
                {
                    factor5 = dividend;
                    break;
                }
            case 5:
                {
                    factor6 = dividend;
                    break;
                }
            case 6:
                {
                    factor7 = dividend;
                    break;
                }
            case 7:
                {
                    factor8 = dividend;
                    break;
                }
            case 8:
                {
                    factor9 = dividend;
                    break;
                }
            case 9:
                {
                    factor10 = dividend;
                    break;
                }
            default:
                {
                    cout << "Not enough" << endl;
                }
            }
        ++factorCounter;
        }
        int factorsum = 0;
        if (factorCounter != 0)
        {
            switch(factorCounter)
            {
            case 10:
                {
                    factorsum += factor10;
                }
            case 9:
                {
                    factorsum += factor9;
                }
            case 8:
                {
                    factorsum += factor8;
                }
            case 7:
                {
                    factorsum += factor7;
                }
            case 6:
                {
                    factorsum += factor6;
                }
            case 5:
                {
                    factorsum += factor5;
                }
            case 4:
                {
                    factorsum += factor4;
                }
            case 3:
                {
                    factorsum += factor3;
                }
            case 2:
                {
                    factorsum += factor2;
                }
            case 1:
                {
                    factorsum += factor1;
                    break;
                }
            case 0:
                {
                    break;
                }
            default:
                {
                    cout << "Error" << endl;
                }
            }

        evaluateIfSumIsPrime (factorsum, i);
        }
    }

    return 0;
}
