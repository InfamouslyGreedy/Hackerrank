#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getResEnergy(int heights[], int initE, int size)
{
    int res = initE;
    for(int i = 0; i < size; i++)
    {
        if(heights[i] > res)
        {
            res-=(heights[i] - res);
        }
        else
        {
            res+=(res - heights[i]);
        }
        if(res > 100000 || res < 0)
        {
            return res;
        }
    }
    return res;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N = 0;
    cin >> N;
    int heights[N];
    int max = 0; 
    for(int i = 0; i < N; i++)
    {
        cin >> heights[i];
        if(heights[i] > max)
        {
            max = heights[i];
        }
    }
    int res = max;
    for(int i = (max - 1); i > 0; i--)
    {
        int remE = getResEnergy(heights, i, N);
        if(remE >= 0)
        {
            res = i;
        }
        else
        {
            break;
        }
    }
    cout << res << endl;
    return 0;
}

