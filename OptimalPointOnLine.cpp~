#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


int main() {
    int n = 0;
    scanf("%d", &n);
    int vals[n];
    int minN = numeric_limits<int>::max();
    int maxN = numeric_limits<int>::min();
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
        minN = min(minN, vals[i]);
        maxN = max(maxN, vals[i]);
    }
    int mid = minN + ((maxN - minN)/2);
    int pivN = 0;
    int dist = numeric_limits<int>::max();
    for(int i = 0; i < n; i++)
    {
        int tDist = abs(vals[i] - mid);
        if(tDist < dist)
        {
            pivN = vals[i];
            dist = tDist;
        }
        else if(tDist == dist)
        {
            if(vals[i] < pivN)
                pivN = vals[i];
        }
    }  
    printf("%d", pivN);
    return 0;
}
