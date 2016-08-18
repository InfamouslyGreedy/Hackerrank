#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int mMax = (5 * pow(10,5)) + 1;
int nMax = pow(10,5) + 1;
int modder = pow(10,9) + 7;
void prec(long long int * mFacts)
{
    mFacts[1] = 1;
    for(int i = 2; i < mMax; i++)
    {       
        mFacts[i] = ((i % modder) * mFacts[i - 1]) % modder;
        //printf("%s%lld\n", " The m ", mFacts[i]);
    } 
}
long long int power(int val, int n)
{
    long long int res = 1;
    for(int i = 1; i < (n + 1); i++)
    {
       res = ((res % modder) * (val)) % modder;
    }
}

int main() {
    int p = 0;
    scanf("%d", &p);
    long long int * mFacts = new long long int[mMax];
    long long int * nFacts = new long long int[nMax];
    prec(mFacts);
    while(p--)
    {
        int m = 0, n = 0; 
        scanf("%d%d", &m, &n);
        int diff = m - n;
        long long int res = 0;
        for(int i = 0; i < diff; i++)
        {
           long long int comb = mFacts[m - i - 1]/
           ((mFacts[(m - i - 1) - (n - 1)] % modder) * (mFacts[(n - 1)] %
           modder)) % modder;
           res = res + 
           (((comb * (power(n,i) % modder)) % modder) *
           (power(n - 1, m - n - i)) % modder) % modder;
           res = res % modder;
        }
        printf("%lld\n", res);
    } 
    return 0;
}
