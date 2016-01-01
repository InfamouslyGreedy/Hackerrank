#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getR(int prime, int n)
{
    int low = pow((prime - 1), n);
    int high = pow((prime + 1), n);
    int pSquared = pow(prime,2);
    int r = (low + high)/pSquared;
    return r;
}
bool isPrime(int test)
{
    int base = 3;
    while(base < test)
    {
        
    }
    return 
}
int main() 
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int prime = 1;
        while(true)
        {
            int prime

        }


    }
    return 0;
}

