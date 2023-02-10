#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;

struct test
{
    int i = 1;
    int j = 2;
};
int call (struct test *pArr, int k)
{
    pArr[1].i = 5;
    k++;
    return k;
}
func (int *pArrI)
{
    pArrI[3] = 3;
}

int main()
{
    struct test arr [5];
    struct test *pArr;
    int k = 0;
    int l [10];
    int *pArrI = l;
    for (int i = 0; i < 10; i++)
    {
        pArrI[i] = 0;
    }
    func (pArrI);
    pArr = arr;
    pArr[pArrI[3]].i = 10;
    k = call (pArr, k);
    cout << pArr[0].i << endl;
    cout << pArr[1].i << endl;
    cout << pArr[3].i << endl;
    cout << pArrI[3] << endl;
    cout << "Made branch successfully" << endl;
    return 0;
}
