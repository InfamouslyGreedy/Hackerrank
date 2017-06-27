#include <iostream>
#include <cmath>

using namespace std;
typedef long long int lli;
int fastExp(int val, int exp, int modder)
{
    if(exp == 0)
        return 1;
    if((exp % 2))
    {
        return ((lli)val * (lli)fastExp(val, exp - 1, modder)) % modder; 
    }
    else
    {
        lli op1 = fastExp(val, exp / 2, modder);
        return (op1 * op1) % modder;
    }
}
int main()
{
    int n;
    cin >> n;
    int modder = pow(10, 9) + 7;
    int firstExp = fastExp(3, n, modder - 1);
    cout << fastExp(3, firstExp, modder) << endl;
}
