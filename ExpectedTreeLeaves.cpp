#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;

lli modder = pow(10, 9) + 7;

lli modPow(lli val, lli y)
{
    if(y == 1)
    {
        return (val % modder);
    }
    if((y % 2) == 1)
    {
        return (val * (modPow(val, y - 1))) % modder;
    }
    else
    {
        lli res = modPow(val, y/2);
        return (res * res) % modder;
    }
}
lli modFact(lli val)
{
    if(val > modder)
        return 0;
    lli res = 0;
    res = -1;
    for(lli i = val + 1; i < modder; i++)
    {
        res = (res * (modPow(i, modder - 2))) % modder;
    }
    return res;
}
int main()
{
    int n = 0;
    cin >> n;
    lli res = 0;
    if(n != 1)
        res = (n * modPow(2, modder - 2)) % modder;
    else
        res = 1;
    for(int i = 1; i <= n; i++)
    {
           res = (res * i) % modder;
    }
    cout << res << endl;
}
