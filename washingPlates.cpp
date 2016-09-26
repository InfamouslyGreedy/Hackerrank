#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool func(pair<int , long long int> a, pair< int , long long int > b)
{
    return a.second > b.second;
}

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    int g[n];
    int l[n];
    long long int rL[n];
    int v[n];
    pair<int , long long int> diff[n];
    long long int totLoss = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> g[i] >> l[i];
        totLoss += l[i];
        v[i] = false;
    }
    for(int i = 0; i < n; i++)
    {
        rL[i] = totLoss - l[i];
        diff[i] = make_pair(i, g[i] - (totLoss - l[i]));
       // cout << " The first second " << g[i] - (totLoss - l[i]) << endl;
    }
    sort(diff, diff + n, func);
    long long int res = 0;
    int end = min(n,k);
    for(int i = 0; i < end; i++)
    {
        res += g[diff[i].first];
        v[diff[i].first] = true;
    }
    //cout << " The res before the fall " << res << endl;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == false)
        {
      //      cout << " We are about to remove " << l[i] << endl;
            res -= l[i];
        }
    }
    if(res >= 0)
        cout << res << endl;
    else
        cout << 0 << endl;
    return 0;
}

