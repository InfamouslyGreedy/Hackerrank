#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    long maxVal1 = numeric_limits<int>::min();
    long minVal1 = numeric_limits<int>::max();
    long maxVal2 = maxVal1;
    long minVal2 = minVal1;
    for(int i = 0; i < n; i++)
    {
        int val = 0;
        cin >> val;
        if(val < minVal2)
        {
            minVal2 = val;
            if(val < minVal1)
            {
                minVal2 = minVal1;
                minVal1 = val;
            }
        }
        if(val > maxVal2)
        {
            maxVal2 = val;
            if(val > maxVal1)
            {
                maxVal2 = maxVal1;
                maxVal1 = val;
            }
        }   
    }
    long res = min(abs(maxVal1 - minVal1), abs(maxVal1 - minVal2));
    res = min(res, abs(maxVal2 - minVal1));
    cout << res << endl;
    return 0;
}
