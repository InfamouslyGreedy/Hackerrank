#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int game(int vals[], int start, int end)
{ 
   // cerr << " The bounds " << start << " " << end << endl;
    int leftTot = 0;
    int rightTot = 0;
    int mainTot = 0;
    if(end - start <= 1)
    {
        return 0;
    }
    for(int i = start; i < end; i++)
    {
        leftTot += vals[i];
        rightTot = 0;
        for(int j = i + 1; j < end; j++)
        {
            rightTot += vals[j];
        }
       // cerr << "The tots " << rightTot << " " << leftTot << endl;
        if(rightTot == leftTot)        
        {
            int left = game(vals,start,i + 1);
            int right = game(vals,i + 1, end);
            if(left > right)
            {
                mainTot = 1 +  left;
            }
            else
            {
                mainTot = 1 + right;
            }
            return mainTot;
        }
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        int vals[n];
        for(int i = 0; i < n; i++)
        {
            cin >> vals[i];
        }
        cout << game(vals,0,n) << endl;

    }
    return 0;
}
