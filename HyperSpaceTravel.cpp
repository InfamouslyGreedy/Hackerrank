#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }
int main() {
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);
    int coods[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &coods[i][j]);
        }
    }
    int test[n];
    int opt[m];
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            test[i] = coods[i][j];  
        }
        sort(test, test + n);
        opt[j] = test[(n - 1)/2]; 
    }
    for(int i = 0; i < m; i++)
        printf("%d%s", opt[i], " ");
    printf("\n");
    return 0;
}
