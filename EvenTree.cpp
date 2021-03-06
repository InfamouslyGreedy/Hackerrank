#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool map[101][101];
int good[101][101];

int dfs(int curr, int n, bool v[])
{
    v[curr] = true;
    int res = 0;
    bool found = false;
    for(int i = 1; i < (n + 1); i++)
    {
        if(map[curr][i] && v[i] == false)
        {
            found = true;
            int temp = dfs(i,n,v);
            good[curr][i] = temp;
            res += temp;
        }
    }
    if(found == false)
        return 1; 
    return res + 1;
}

int main()
{
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    bool v[n + 1];
    for(int i = 1; i < (n + 1); i++)
    {
        for(int j = 1; j < (n + 1); j++)
        {
            map[i][j] = false;
            good[i][j] = -1;
            v[i] = false;
        }
    }
    for(int i = 0; i < m; i++)
    {
        int s = 0, d = 0;
        scanf("%d%d", &s, &d);
        map[s][d] = map[d][s] = true;
    }
    dfs(1, n, v);
    int res = 0;
    for(int i = 1; i < (n + 1); i++)
    {
        for(int j = 1; j < (n + 1); j++)
        {
            if(good[i][j] != -1)
            {
                if(good[i][j] % 2 == 0 && (n - good[i][j]) % 2 == 0)
                {
                    //printf("%s%d%s%d\n", " The good ", i, " ", j);
                    res++;
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
