#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int size = 0;
        cin >> size;
        int values[size];
        for(int i = 0; i < size; i++)
        {
            cin >> values[i];
        }
        int total = 0;
        int maxVal = 0;
        int maxTotal = 0;
        int altMax = -1000000;
        int posCount = 0;
        for(int i = 0;i < size; i++)
        {
            if(values[i] >= 0)
            {
                posCount++;
                maxTotal+=values[i];
            }
            else
            {
                if(values[i] > altMax)
                {
                    altMax = values[i];
                }
            }

            total+=values[i];
            
            if(total < 0)
            {
                total = 0;
            }
            if(total > maxVal)
            {
                maxVal = total;
            }
        }
        if(posCount == 0)
        {
            maxVal = maxTotal = altMax;
        }
        cout << maxVal << " " << maxTotal << endl;

    }
    return 0;
}

