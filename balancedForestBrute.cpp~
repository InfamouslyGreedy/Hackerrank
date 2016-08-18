#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

bool ** map;

void reset(bool v[], int s1, int d1, int s2, int d2, int n)
{
    for(int i = 1; i < n + 1; i++)
        v[i] = false;
    map[s1][d1] = map[d1][s1] = map[s2][d2] = map[d2][s2] = true;
}


int explore(int c[], bool v[], int n, int curr)
{
  //  printf("%s%d\n"," The curr is ",curr);
    int res = 0;
    v[curr] = true;
    for(int i = 1; i < (n + 1); i++)
    {
        if(map[curr][i] && v[i] == false)
        {
            res += explore(c,v,n,i);
        }
    }
    return (res + c[curr]);
}
int getAdd(int c[], bool v[], int n)
{
    int res[3];
    int index = 0;
    for(int i = 1; i < (n + 1); i++)
    {
    //    printf(" In get add 1 \n");
        if(!v[i])
        {
      //      printf(" about to execute \n ");
            res[index] = explore(c,v,n,i);
        //    printf("%s\n", "executed");
            index++;
        }
        //printf(" In get add 2 \n");
    }
    if(res[0] == res[1])
    {
        if(res[2] < res[0])
            return res[0] - res[2];
        else
            return -1;
    }
    else if(res[0] == res[2]) 
    {
        if(res[1] < res[0])
            return res[0] - res[1];
        else
           return -1;
    }
    else if (res[1] == res[2])
    {
        if(res[0] < res[1])
            return res[1] - res[0];
        else
            return -1;
    }
    else
        return -1;
}
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q = 0;
    scanf("%d", &q);
    while(q--)
    {
        int n = 0;
        scanf("%d", &n);
        int c[n + 1];
        bool v[n + 1];
        pair<int, int> e [n-1];

        map = new bool *[n + 1];
        for(int i = 0; i < n + 1; i++)
            map[i] = new bool[n + 1];

        for(int i = 0; i < n + 1; i++)
        {
            for(int j = 0; j < n + 1; j++)
            {
                map[i][j] = false; 
            }
        }
        for(int i = 1; i < (n + 1); i++)
        {
            scanf("%d", &c[i]);
            v[i] = false;
        }
        for(int i = 0; i < (n - 1); i++)
        {
            int s = 0, d = 0;
            scanf("%d%d", &s, &d);
            e[i] = make_pair(s,d);
            map[s][d] = map[d][s] = true;
        }
        int res = numeric_limits<int>::max();
        int found = false;
        for(int i = 0; i < (n - 1); i++)
        {
            for(int j = 0; j < (n -1); j++)
            {
                if(j != i)
                {
                //    printf("%s%d%s%d\n", " The i ", i, " and the j ", j);
                    map[e[i].first][e[i].second] =
                    map[e[i].second][e[i].first] = false;
                    
                 //   printf(" Got this far 1 \n");
                    map[e[j].first][e[j].second] =
                    map[e[j].second][e[j].first] = false;

                  //  printf(" Got this far 2 \n");

                    int test = getAdd(c,v,n);
                  //  printf("%s%d\n", " The test is ",test); 
                    if(test != -1)
                    {
                        found = true;
                        res = min(res, test);
                    }
                   // printf(" Before the segfault \n");
                   /** printf("%s%d%s%d%s%d%s%d\n", " about to reset ",
                    e[i].first," ", e[i].second," ", e[j].first," ",
                    e[j].second); **/
                    reset(v,e[i].first, e[i].second,e[j].first,e[j].second, n);
                  //  printf(" after the segfault \n");
                }
            }
        }
        if(found)
            printf("%d\n", res);
        else
            printf("%d\n", -1);
    }   
    return 0;
}
