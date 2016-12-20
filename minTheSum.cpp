#include <iostream>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

typedef long long int lli;
bool func(int a, int b)
{
    return a < b;
}
lli sqrSum = 0;
lli sumSqr = 0;
long long int getSum(int start, int end, int k, int vals[])
{
    if(start == 0)
    {
        for(int i = start; i <= end; i++)
        {
            sqrSum += pow(vals[i], 2);
            sumSqr += vals[i];
        }
    }
    else
    {
        sqrSum += (pow(vals[end], 2) - pow(vals[start - 1], 2));
        sumSqr += (vals[end] - vals[start - 1]);
    }
    lli res =  (2 * k * sqrSum) - (2 * (lli)pow(sumSqr, 2)); 
    return res;
}
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int vals[n];
    for(int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }
    sort(vals, vals + n);
    long long int res = numeric_limits<long long int >::max(); 
    for(int i = 0; i <= n - k; i++)
    {
        int start = i;
        int end = start + k - 1;
        res = min(res, getSum(start, end,k, vals));
    }
    cout << res << endl;
    return 0;
}
