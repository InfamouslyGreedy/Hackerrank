#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int maxN = pow(10,5);
void sieve(vector<int> & primes)
{
    bool vals[maxN + 1];
    for(int i = 0; i < maxN + 1; i++)
        vals[i] = true;
    vals[0] = vals[1] = false;
    int stop = ceil(sqrt(maxN));
    for(int i = 2; i < stop; i++)
    {
        if(vals[i])
        {
            for(int j = pow(i, 2); j <= maxN; j += i)
            {
                vals[j] = false;
            }
        }
    }
    for(int i = 2; i <= maxN; i++)
    {
        if(vals[i])
            primes.push_back(i);
    }
}
int getNum(vector<int>primes, int val)
{
    int res = 0;
    int size = primes.size();
    for(int i = 0; i < size; i++)
    {
        if(primes[i] <= val)
            res++;

    }
    return res;
}
int main()
{
    vector<int> primes;
    sieve(primes);
    int g = 0;
    cin >> g;
    while(g--)
    {
        int val = 0;
        cin >> val;
        if((getNum(primes, val) % 2) == 0)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }

}
