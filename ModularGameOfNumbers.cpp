#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n = 0;
    int p = 0, q = 0;
    cin >> n >> p >> q;
    int pArr[p];
    int qArr[q];
    for(int i = 0; i < p; i++)
    {
        cin >> pArr[i];    
    }
    for(int i = 0;i < q; i++)
    {
        cin >> qArr[i];
    }
    int ams[n] = {0};
    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < q; j++)
        {
            int ind = (pArr[i] + qArr[j]) % n;
            ams[ind]++;
        }
    }
    int minVal = 50000;
    int minInd = 0;
    for(int i = 0; i < n; i++)
    {
        if(ams[i] <= minVal)
        {
            minVal = ams[i];
            minInd = i;
        }
    }
    cout << n - minInd << endl;
    return 0;
}
