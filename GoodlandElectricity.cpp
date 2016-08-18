#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n = 0, k = 0;
    scanf("%d%d",&n,&k);
    int tow = 0;
    bool tower[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tow);
        if(tow == 1)
            tower[i] = true;
        else
            tower[i] = false;
    }
    int wall = k;
    int am = 0;
    bool first = false;
    bool found = false;
    int x = 0;
    for(int i = 0; i < n; i++)
    {
        if(x + k < n)
        {
            if(i < wall)           
            {
                if(tower[i])
                {
                    found = true;
                    x = i;
                    if(first == false)
                    {
                        am++;
                        first = true;
                    }
                }
            }
            else
            {
               // printf("%s%d\n", " The last x ",x);
                if(!found)
                {
                    am = -1;
                    break;
                }
                wall = x + (2 * k);
                if(tower[i])
                {
                    x = i;
                    //printf("%s%d\n", " The last x squeeked ",x);
                    am++;
                }
                else
                {
                    found = false;
                    first = false;
                }
            }
        }
        else
        {
           // printf("%s%d\n", " The last x ",x);
            break;
        }
    }
    printf("%d\n",am);
    return 0;
}