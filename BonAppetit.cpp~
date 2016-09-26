#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 0;
    int k = 0;
    scanf("%d%d", &n, &k);
    int c[n];
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
        res += c[i];
    }
    int charge = 0;
    scanf("%d", &charge);
    int act = (res - c[k])/2;
    if(act == charge)
        printf("%s\n", "Bon Appetit");
    else
        printf("%d\n", (charge - act));
    return 0;
}
