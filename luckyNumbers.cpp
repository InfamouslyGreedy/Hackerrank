#include <iostream>
#include <cmath>
#include <string>

using namespace std;

typedef long long int lli;

bool check(lli n)
{
    int res = n % 4;
    if(res == 0)
        return true;
    if(res == 1 && n >= 21)
        return true;
    if(res == 2 && n >= 14)
        return true;
    if(res == 3 && n >= 7)
        return true;
    return false;
}

int main()
{
    int q = 0; 
    cin >> q;
    while(q--)
    {
        lli n = 0;
        cin >> n;
        if(check(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}   
