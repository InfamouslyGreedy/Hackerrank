#include <iostream>
#include <cmath>

using namespace std;

int getFactNum(int val)
{
    int end = sqrt(val);
    int res = 0;
    for(int i = 1; i <= end; i++)
    {
        if((val % i) == 0)
            res++;
    }
   // cout << res << endl;
    return (res - 1);
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        int xorRes = 0;
        for(int i = 0; i < n; i++)
        {
            int val = 0;
            cin >> val;
            xorRes ^= getFactNum(val);
        }
        if(xorRes != 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}
