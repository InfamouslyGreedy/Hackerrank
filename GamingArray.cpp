#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int g = 0;
    cin >> g;
    while(g--)
    {
        int n = 0;
        cin >> n;
        int currMax = 0; 
        cin >> currMax;
        int maxCount = 1;
        for(int i = 1; i < n; i++)
        {
           int test = 0;
           cin >> test;
           if(test > currMax)
           {
                maxCount++;
                currMax = test;
           }
        }
        if((maxCount % 2) == 0)
            cout << "ANDY" << endl;
        else
            cout << "BOB" << endl;
    }
}   
