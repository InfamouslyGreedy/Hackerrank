#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    pair<int, int> inst[m];
    map<int,int> flips;
    for(int i = 0; i < m; i++)
    {
        int s;
        int d;
        scanf("%i%d", &s, &d);
        if(s == 2)
        {
            map<int, int>::iterator mit;
            mit = flips.find(s + d);
            if(mit != flips.end())
                mit->second++;
            else
                flips.insert(make_pair(s + d,1));

        }
        else
        {
            inst[i] = make_pair(s,d);
        }
    }
    map<int,int>::iterator mit = flips.begin();
    map<int,int>::iterator mend = flips.end();
    int oddCount = 0;
    int cause = 0;
    for(; mit != mend; mit++)
    {
        if(mit->second % 2 != 0)
        {
            cause = mit->first;
            oddCount++;
        }
    }
    if(oddCount == 1)
    {
        printf("%d%s%d\n", 2, " ", cause - 2);
    }
    else if (oddCount != 0)
    {
       // printf("%s\n", "You dont mean it ");
    }
    else
    {
        double diff = 0;
        for(int i = 0; i < m; i++)
        {
            diff = fmod((diff + ((double)(360 * inst[i].second)/(double)(n))), 360);
            //printf("%s%f\n", " The diff 2 ", diff);
        }
        for(int i = 0; i < n; i++)
        {
            double test = ((double)(360 * i)/(double)(n));
            if(fmod(diff + test, 360) == 0)
            {
                printf("%i%s%d\n", 1, " ",i);
                break;
            }
        }
    } 
    return 0;
}

