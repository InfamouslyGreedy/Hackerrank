#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int s = 0;
        scanf("%d", &s);
        if(s % 2 == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

