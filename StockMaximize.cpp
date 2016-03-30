#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

long long int getMax(int arr[], int size, int start)
{
    long long int max = -1;
    for(long long int i = start; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main() 
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int size = 0;
        cin >> size;
        int days[size];
        for(int i = 0; i < size; i++)
        {
            cin >> days[i];
        }
        int goodDay = getMax(days, size, 0);
        long long int profit = 0;
        long long int prevCost = 0;
        int segCount = 0;
        int pos = 0;
        for(int i = 0; i < size; i++)
        {
            if(days[i] == goodDay)
            {
                cerr << " The day " << days[i] << " good " << goodDay <<
                endl;
                cerr << " The pos " << i << endl;
                profit+=((segCount * goodDay) - prevCost);
                prevCost = 0;
                goodDay = getMax(days, size, i + 1);
                segCount = 0;
                cerr << " The current profit " << profit << endl;
            }
            else
            {
                prevCost+=days[i];
                segCount++;
            }
        }
        cout << profit << endl;
    }
    return 0;
}

