#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    string val;
    cin >> val;
    int rd1[n/2];
    int rd2[n/2];
    int half = (n/2);
    for(int i = 0; i < half; i++)
    {
        if((int)val[i] != (int)val[(n - 1) - i])
            rd1[i] = 1;
        else
            rd1[i] = 0;

        if(val[i] == '9' && val[(n - 1) - i] != '9')
            rd2[i] = 1;
        else if(val[i] != '9' && val[(n - 1) - i] == '9')
            rd2[i] = 1;
        else if(val[i] == '9' && val[(n - 1) - i] == '9')
            rd2[i] = 0;
        else
            rd2[i] = 2;
    }
    for(int i = 0; i < half; i++)
    {
        if(rd1[i] != 0)
        {
            if(k > 0)
            {
                val[i] = val[(n - 1) - i] = max((int)val[i], (int)val[(n - 1) - i]);
                k--;
            }
            else
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < half; i++)
    {
        if((rd2[i] - rd1[i]) > 0)
        {
            if((rd2[i] - rd1[i]) <= k)
            {
                val[i] = val[(n - 1) - i] = '9';
                k -= (rd2[i] - rd1[i]);
            }
        }
    }
    if((n % 2) != 0)
    {
        if(k > 0)
            val[half] = '9';
    }
    cout << val << endl;
    return 0;
}
