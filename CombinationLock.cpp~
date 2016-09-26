#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int pres[5];
    int fut[5];
    for(int i = 0; i < 5; i++)
        scanf("%d", &pres[i]);
    for(int i = 0; i < 5; i++)
        scanf("%d", &fut[i]);
    int res = 0;
    for(int i = 0; i < 5; i++)
    {
        int a = min(fut[i], pres[i]);
        int b = max(fut[i], pres[i]);
        res += min(b - a,(10 + a) - b);
    }
    printf("%d\n",res);
    return 0;
}
