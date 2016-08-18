#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int nextP(int primes[], int pos)
{   
    int res = -1;
    for(int i = primes[pos - 1] + 1; i < (i + 1); i++)
    {
        bool found = true;
        for(int j = 1; j < pos;j++)
        {
            if(i % primes[j] == 0)
            {
                found = false;  
            }
        }
        if(found)
        {
            res = i;
            break;
        }
    }
    return res; 
}
int main()
{
    int n = 0;
    int q = 0;
    scanf("%d%d",&n, &q);
    int vals[n];
    bool v[n];
    int primes[q + 1];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
        v[i] = false;
    }
    primes[0] = 0;
    primes[1] = 2;
    int p = 0;
    list<int>res;
    for(int i = 1; i <= q; i++)
    {
        list<int> temp;
        temp.clear();
        if(i == 1)
            p = primes[1];
        else
            p = nextP(primes,i);
        for(int i = n - 1; i >= 0; i--)
        {
            if(v[i] == false)
            {
                if(vals[i] % p == 0)
                {
                    v[i] = true;
                    temp.push_back(vals[i]);
                }
            }
        }
        while(!(temp.empty()))
        {
            res.push_front(temp.back());
            temp.pop_back();
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(v[i] == false)
        {
            res.push_front(vals[i]);
        }
    }
    while(!(res.empty()))
    {
        printf("%d\n",res.back());
        res.pop_back();
    }
    return 0;
}