#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef long long int lli;
int n = 0;
lli adj[5001][5001];
lli dist[5001][5001];
int k[5001][5001];
lli modder = pow(10,9) + 9;

void dijk(int ind)
{
    int d[n + 1];
    int kLoc[n + 1];
    for(int i = 0; i < (n + 1); i++)
    {
        d[i] = 0;
        kLoc[i] = -1;
    }
    queue<int> q;
    q.push(ind);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int i = 1; i < (n + 1); i++)
        {
            if(adj[curr][i] != -1)
            {
                d[i] = (adj[curr][i] + d[curr]) % modder;
                kLoc[i] = kLoc[curr] + 1;
                if(dist[ind][i] == -1)
                {
                    dist[ind][i] = dist[i][ind] = d[i];
                    k[ind][i] = k[i][ind] = kLoc[i];
                    q.push(i);
                }
            }
        }
    }
}
lli modPow(lli val, int pow)
{
    if(pow == 1)
        return val % modder;
    if(pow % 2)
        return ((val % modder) * (modPow(val, pow - 1))) % modder;
    else
    {
        lli res = modPow(val, pow/2);
        return (res * res) % modder;
    }
}
lli getFact(int val)
{
    if(val == 0)
        return 1;
    return (val * getFact(val - 1)) % modder;
}
int main()
{
    cin >> n;
    for(int i = 0; i < (n + 1); i++)
    {
        for(int j = 0; j < (n + 1); j++)
        {
            adj[i][j] = -1;
            dist[i][j] = -1;
            k[i][j] = -1;
        }
    }
    for(int i = 0; i < (n - 1); i++)
    {
        int s = 0, d = 0, l = 0;
        cin >> s >> d >> l;
        adj[s][d] = adj[d][s] = l;
    }
    for(int i = 1; i < (n + 1); i++)
        dijk(i);
    lli exp = 0;
    for(int i = 1; i < (n + 1); i++)
    {
        for(int j = i + 1; j < (n + 1); j++)
        {
            exp += (dist[i][j]  * ((2 * (modPow(k[i][j] + 2, modder - 2))) % modder) % modder); 
        }
    }
    cout << ((exp * getFact(n)) % modder) << endl;
}
