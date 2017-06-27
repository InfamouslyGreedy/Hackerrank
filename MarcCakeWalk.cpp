#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool func(int a, int b)
{
    return a > b;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> vals(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }
    sort(vals.begin(), vals.end(), func);
    long long int res = 0;
    for(int i = 0; i < n; i++)
    {
        res+=(vals[i] * pow(2,i)); 
    }
    cout << res << endl;
    return 0;
}
