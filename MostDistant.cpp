#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <iomanip>
using namespace std;


int main() {
    int n = 0;
    
    cin >> n;
    double x[n];
    double y[n];
    double minX = numeric_limits<double>::max();
    double minY = numeric_limits<double>::max();
    double maxX = numeric_limits<double>::min();
    double maxY = numeric_limits<double>::min();
    
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        if(x[i] < minX)
            minX = x[i];
        if(x[i] > maxX)
            maxX = x[i];
        if(y[i] < minY)
            minY = y[i];
        if(y[i] > maxY)
            maxY = y[i];
    }
    double maxDist = numeric_limits<double>::min();
    maxDist = max(maxDist, maxX - minX);
    maxDist = max(maxDist, maxY - minY);
    maxDist = max(maxDist, sqrt(pow(minX,2) + pow(maxY, 2)));
    maxDist = max(maxDist, sqrt(pow(minX,2) + pow(minY, 2)));
    maxDist = max(maxDist, sqrt(pow(maxX,2) + pow(maxY, 2)));
    maxDist = max(maxDist, sqrt(pow(maxX,2) + pow(minY, 2)));
    cout << fixed << setprecision(7) << maxDist << endl; 
    return 0;
}
