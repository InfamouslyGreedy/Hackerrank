#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> getPrimeFactors(int max, int small)
{
    bool prime[max + 1];
    for(int i = 0 ; i < max + 1; i++)
    {
        prime[i] = true;
    }
    for(int i = 2; i < max + 1; i++)
    {
        if(prime[i])
        {
            for(int j = pow(i,2); j < max + 1; j+=i)
                prime[j] = false;
        }
    }
    vector<int> res;
    for(int i = 2; i < max + 1; i++)
    {
        if(prime[i] && small % i == 0)
            res.push_back(i);
    }
    return res;
}
int main(){
    int n;
    int k;
    scanf("%d%d",&n,&k);
    int vals[n];
    int small = numeric_limits<int>::max();
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
        small = min(vals[i], small);
    }
    vector<int> factors = getPrimeFactors(ceil(sqrt(small)), small);
    int size = factors.size();
   // printf("%s%d\n", " The size of the factors ", size);
    vector<int> common;
    for(int i = 0; i < size; i++)
    {
        int curr = factors[i];
        bool comm = true;
        for(int j = 0; j < n; j++)
        {
           if(vals[j] % curr != 0)
               comm = false;
        }
        if(comm)
            common.push_back(curr);
    }
    size = common.size();
    int large = 0;
    for(int i = 0; i < size; i++)
    {
        int test = (k/common[i]) * common[i];
       // printf("%s%d%s%d%s%d\n", " The test ", test, " the common ",
        //common[i], " divide ", k/common[i]);
        large = max(large, test);
    }
    printf("%s%d\n","I wheel chare stunt all day swag all day ",large);
    return 0;
}
