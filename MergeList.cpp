#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t = 0;
    scanf("%d", &t);
    long long int triangle[201][201];
   long long mVal = pow(10,9) + 7;
    for(int i = 0; i < (200 + 1); i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || i == j)
                triangle[i][j] = 1;
            else
            {
                triangle[i][j] = ((triangle[i - 1][j - 1] % mVal) + (triangle[i -
                1][j] % mVal)) % mVal ;
            }
        }
    }
    while(t--)
    {
        int n = 0, m = 0;
        scanf("%d%d",&n,&m);
        printf("%lld\n",(triangle[n + m][m]));
    }
    return 0;
}
