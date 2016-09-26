#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void getCood(pair<int, int> c [], int x, int y, int s)
{
    c[0] = make_pair(x,y);
    c[1] = make_pair(x, s - y);
    c[2] = make_pair(s - x, y);
    c[3] = make_pair(s - x, s - y);
}
int main() {
    int q = 0;
    cin >> q;
    while(q--)
    {
        int n = 0;
        cin >> n;
        int mat[(2 * n)][(2 * n)];
        int size = (2 * n);
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                cin >> mat[i][j];
            }
        }
        long long int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                pair<int , int> c[4];
                getCood(c,i,j,(2 * n) - 1);
                int test = 0;
                for(int k = 0; k < 4; k++)
                {
                    int x = c[k].first, y = c[k].second;
                    test = max(test, mat[x][y]);
                }
                res += test;
            }
        }
        cout << res << endl;
    }
    return 0;
}
