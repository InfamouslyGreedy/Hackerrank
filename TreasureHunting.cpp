#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int x = 0, y = 0, a = 0, b = 0;
    cin >> x >> y >> a >>  b;
    long double mag = sqrt(pow(a,2) + pow(b,2));
    long double tHype = sqrt(pow(x,2) + pow(y,2));
    long double sumSq = pow(tHype, 2)/pow(mag, 2);
    long int cross = (x * a) + (y * b);
    if(cross < 0)
    {
        a *= -1;
        b *= -1;
    }
    double ang = acos(double((x * a) + (y * b))/(mag * tHype));
    double n = (tHype * sin(ang))/mag;
    double k = sqrt(sumSq - pow(n,2));
    if(cross > 0)
    {
        if((a * y) - (x * b) < 0)
            n *= -1;
    }
    else
    {
        k *= -1;
        if((x * b) - (y * a) < 0)
            n *= -1;
    }
    cout << fixed << setprecision(12) << k << endl;
    cout << fixed << setprecision(12) << n << endl;
    return 0;
}
