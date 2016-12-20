#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int lli;
bool myfunction (int i,int j) { return (i<j); }

int main()
{
    int n = 0;
    int p = 0;
    cin >> n >> p;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, myfunction);
    int prev = -1;
    lli res = 0;
    for(int i = 0; i < n; i++)
    {
        int val = ceil((double)a[i]/(double)p);
        if(val > prev)
        {
            prev = val;
        }
        else
        {
            val = ++prev;
        }
        res += val;
    }
    cout << res << endl;
    return 0;
}
