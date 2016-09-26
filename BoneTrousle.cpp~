#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int main() {
    int t = 0;
    cin >> t;
    typedef long double lld;
    /*ofstream out;
    out.open("outFile.txt"); */
    while(t--)
    {
        long long int b = 0;
        long long int n = 0, k = 0;
        cin >> n >> k >> b;
        long long int sumB = (b * (b + 1))/2;
        if(n < sumB || (long double)(k - b) < ((long double )(n -sumB)/(long double)b))
        {
            cout << -1 << endl;
        }
        else
        {
            long long int vals[b + 1];
            for(int i = 0; i < (b + 1); i++)
            {
                vals[i] = i;
            }
            long long int bound = k, rem = n - sumB;
            for(int i = b; i >= 1; i--)
            {
                if(rem == 0)
                    break;
              //  cerr << " The vals before " << vals[i] << endl;
                long long int diff = bound - vals[i];
              //  cerr << " The diff " << diff << " the rem " << rem << endl;
                vals[i] += min(rem,diff);
                rem -= min(rem,diff);
               // cerr << " The vals " << vals[i] << " rem after " << rem << endl; 
                bound--;
            }
            for(int i = 1; i < b; i++)
                cout << vals[i] << " ";
            cout << vals[b] << endl;
        }
    }
    return 0;
}
