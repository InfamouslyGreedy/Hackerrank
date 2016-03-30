#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t = 0;
    cin >> t;
    while(t--)
    {
        long long x,a,b = 0;
        cin >> a >> b >> x;
        long long aToB = pow(a,b);
       // cerr << " the pow " << aToB << endl;
        long long lowBound = x * (aToB/x);
        long long upBound = (x * (aToB/x)) + x;

        /*cerr << " the upBound " << upBound << " LowBound " << lowBound <<
        endl; */
        if(abs(upBound - aToB) < abs(lowBound - aToB))
        {
            cout << upBound << endl;
        }
        else
        {
            cout << lowBound << endl;
        }
    }
    return 0;
}
