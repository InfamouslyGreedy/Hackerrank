#include <iostream>
#include <algorithm>

using namespace std;

bool func(long long int a, long long int b)
{
    return a < b;
}
int main()
{
    int q = 0;
    cin >> q;
    while(q--)
    {
        int n = 0;
        cin >> n;
        int vals[n][n];
        long long int caps[n] = {0};
        long long int balls[n] = {0};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> vals[i][j];
                caps[i] += vals[i][j];
            }
        }
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i < n; i++)
            {
                balls[j] += vals[i][j];
            }
        }
        sort(caps, caps + n, func);
        sort(balls, balls + n, func);
        bool failed = false;
        for(int i = 0; i < n; i++)
        {
            if(caps[i] != balls[i])
            {
                cout << "Impossible" << endl;
                failed = true;
                break;
            }
        }
        if(failed == false)
            cout << "Possible" << endl;
    }
}
