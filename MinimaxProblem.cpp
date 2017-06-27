#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    int n = 0; 
    cin >> n;
    int vals[n];
    for(int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }
    vector< int > highs;
    vector< int > lows;
    while(true)
    {
        int maxVal = 0;
        for(int i = 0; i < n; i++)
        {
            maxVal = max(maxVal,vals[i]);
        }
        if(maxVal == 0 || maxVal == 1)
        {
            maxVal = vals[0];
            for(int i = 0; i < n; i++)
            {
                if(vals[i] != maxVal)
                {
                    cout << 1 << endl;
                    return 0;
                }
            }
            cout << 0 << endl;
            return 0;
        }
        int maxBits = (int)log2(maxVal) + 1;
        for(int i = 0; i < n; i++)
        {
            int bits = (int)log2(vals[i]) + 1;
            if(bits == maxBits)
                highs.push_back(vals[i]);
            else
                lows.push_back(vals[i]);
        }
        if(lows.size() == 0)
        {
            for(int i = 0; i < n; i++)
            {
                vals[i] ^= (int)pow(2, maxBits - 1);
            }
        }
        else
        {
            break;
        }
    }
    int hSize = highs.size();
    int lSize = lows.size();
    int res = numeric_limits<int>::max();
    for(int i = 0; i < hSize; i++)
    {
        for(int j = 0; j < lSize; j++)
        {
           res = min(res, (highs[i] ^ lows[j]));  
        }
    }
    cout << res << endl;
}
