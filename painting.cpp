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
        int n = 0;
        cin >> n;
        int tot = 0;
        for(int i = 0; i < n;i++)
        {
            tot += ((double)n/(double)i);
        }
        cout << tot << endl;
    }
    return 0;
}

