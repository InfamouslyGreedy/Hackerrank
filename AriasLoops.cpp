#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 0;
    int k = 0;
    cin >> n >> k;
    int rem[k + 1];
    rem[0] = rem[1] = 0;    
    for(int i = 2; i < k + 1; i++)
    {
        rem[i] = ((rem[i - 1] + 1) + (i - 1)) - 1;
    }
    int modder = pow(10, 9) + 7;
    int allowed = n - rem[k];
    int res = 1;
    if(allowed <= 0)
        cout <<  0 << endl;
    else
    {
        for(int i = 1; i < allowed; i++)
        {
            int s = i + 1;
            int trial = 1;
            for(int i = 0; i < k - 1; i++)
            {
                trial = (trial* s) % modder; 
            }
            res = (res + trial) % modder;
        }
        cout << res << endl;
    }
    return 0;
}

