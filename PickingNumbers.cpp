#include <iostream>
#include <algorithm>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }
int main()
{
    int n = 0;
    cin >> n;
    int vals[n];
    for(int i = 0; i < n; i++)
        cin >> vals[i];
    sort(vals, vals + n);
    int maxAm = 0;
    for(int i = 0; i < n; i++)
    {
       int am = 1;
       for(int j = i + 1; j < n; j++)
       {
            if(abs(vals[j] - vals[i]) <= 1)
                am++;
            else
                break;
       }
       maxAm = max(maxAm, am);
    }
    cout << maxAm << endl;
}
