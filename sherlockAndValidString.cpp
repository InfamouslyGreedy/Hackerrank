#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int vals[26];
    int size = s.size();

    for(int i = 0; i < 26; i++)
        vals[i] = 0;

    for(int i = 0; i < size; i++)
        vals[(int)s[i] - 97]++;

    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();

    for(int i = 0; i < 26; i++)
    {
        if(vals[i] != 0)
        {
            minVal = min(minVal, vals[i]);
            maxVal = max(maxVal, vals[i]);
        }
    }

    int tot = 0;
    bool removeMin = true;
    for(int i = 0; i < 26; i++)
    {
        if(vals[i] != 0 && vals[i] > minVal)
            tot++;
    }
    bool found = false;
    if(tot > 1)
    {
        int count = 0;
        for(int i = 0; i < 26; i++)
        {
            if(vals[i] < maxVal && vals[i] != 0)
            {
                count++;
                if(count == 1 && vals[i] == 1)
                {
                    found = true;
                }
                else
                {
                    found = false;
                    break;
                }
            }
        }
        if(found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;

}
