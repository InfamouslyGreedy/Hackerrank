#include <iostream>

using namespace std;

int main()
{
    int n = 0, k = 0, q = 0;
    cin >> n >> k >> q;
    int nVals[n];
    for(int i = 0; i < n; i++)
    {
        int curr = 0;
        cin >> curr;
        nVals[(i + k) % n] = curr;
    }
    while(q--)
    {
        int ind = 0;
        cin >> ind;
        cout << nVals[ind] << endl;
    }
    
    return 0;
}
