#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int vals[n + 2];
    int prefSum[n + 2];
    int sufSum[n + 2];
    map<int, int> cnt;
    vals[0] = vals[n + 1] = 0;
    cout << " About to read in the vals " << endl;
    for(int i = 1; i < (n + 1); i++)
    {
        cin >> vals[i];
        cout << " Just read " << vals[i] << endl;
        cout << " The i is " << i << " with n " << n << endl;
    }
    cout << " Got passed reading in the vals " << endl;
    prefSum[0] = 0;
    for(int i = 1; i < (n + 2); i++)
    {
        prefSum[i] = prefSum[i - 1] ^ vals[i];
    }
    cout << " Got passed filling the prefix arrays " << endl;
    sufSum[n + 1] = 0;
    cnt[sufSum[n + 1]] = 1;
    for(int i = n; i >= 0; i--)
    {
        sufSum[i] = sufSum[i + 1] ^ vals[i];
        if(cnt.find(sufSum[i]) == cnt.end())
        {
            cnt[sufSum[i]] = 1;    
        }
        else
        {
            cnt[sufSum[i]]++;
        }
    }
   /* cout << " The prefSum " << endl;
    for(int i = 0; i < (n + 2); i++)
        cout << prefSum[i] << " ";
    cout << endl;
    cout << " The sufSum " << endl;
    for(int i = 0; i < (n + 2); i++)
        cout << sufSum[i] << " ";
    cout << endl; */
    int total = 0;
    for(int i = 0; i < (n + 1); i++)
    {
        cnt[sufSum[i]]--;
        if(cnt.find(prefSum[i]) != cnt.end())
        {
            if(prefSum[i] != sufSum[i + 1] || sufSum[i + 1] > 1)
            {
                total += cnt[prefSum[i]];
            }
        }
    }
    cout << total << endl;
    return 0;
}

