#include <cmath>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

void getPrimes(vector<int> & primes, int end)
{
    bool isPrime[end + 1];
    for(int i = 0; i < end + 1; i++)
        isPrime[i] = true;
    for(int i = 2; (i * i) <= end; i++)
    {
        for(int j = (i * i); j <= end; j+=i)
        {
            isPrime[j] = false;
        }
    }      
    for(int i = 2; i < end + 1; i++)
    {
        if(isPrime[i])
            primes.push_back(i);
    }
}
int main()
{
    vector<int>primes;
    getPrimes(primes, 1200);
    int n = 0, q = 0;
    cin >> n >> q;
    stack <int> s[q + 1];
    for(int i = 0; i < n; i++)
    {
        int val = 0;
        cin >> val;
        s[0].push(val);
    }
    int size = primes.size();
    for(int i = 1; i < (q + 1); i++)
    {
        stack<int> temp;
        while(!(s[0].empty()))
        {
            int val = s[0].top();
            s[0].pop();
            if((i - 1) < size && ((val % primes[i - 1]) == 0))
            {
                s[i].push(val); 
            }
            else
            {
                temp.push(val);
            }
        }
        s[0] = temp;
    }
    for(int i = 1; i < (q + 1); i++)
    {
        while(!s[i].empty())
        {
            cout << s[i].top() << endl;
            s[i].pop();
        }
    }
    while(!s[0].empty())
    {
        cout << s[0].top() << endl;
        s[0].pop();
    }
    return 0;
}
