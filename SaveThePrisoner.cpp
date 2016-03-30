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
        int n = 0,m = 0,s = 0;
        cin >> n >> m >> s;
        int res = (s + (m - 1)) % n;
        if(res == 0)
        {
            cout << n << endl;
        }
        else
        {
            cout << res << endl;
        }
    }
    return 0;
}
