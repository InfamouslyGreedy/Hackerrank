#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxG = 0;
int map[34][34]
vector< string > maxes;

bool isAnagram(string a, string b)
{
    for(int i = 0; i < a.size; i++)
    {
        
    }
}
bool isPresent(string test)
{
    stringstream ss 
    ss << path;
    string pt = ss.str();
    int size = maxes.size();
    for(int i = 0; i < size; i++)
    {
        
    }
}
pair<string, int> explore(int c[],int ind, bool v[], int size, int pt)
{
    int locMax = 0;
    for(int i = 1; i < size; i++)
    {
        if(v[i] == false)
        {
            bool subV[size];
            for(int j = 0; j < size; j++)
            {
                if(map[i][j] == 0)
                {
                    subV[i] = true;
                }
                else
                {
                    subV[i] = v[i];
                }
            }
            pair<string, int> ret = explore(c,i,subV,size, path);
            int res = c[ind] + ret.second;
            if(res > locMax)
            {
                locMax = res;
            }
            string path = string(&(char(ind + 65))) + ret.first;  
            if(res > maxG)
            {
                maxes.clear();
                maxes.push_back(path);
            }
            else if(res == maxG)
            {
                if(!(isPresent(path)))
                {
                    maxes.push_back(path);
                }
            }
        }
    }
    return locMax;
}
void start(int c[], int size)
{
    for(int i = 1; i < size; i++)
    {
        vector<int> path;
        int v[size];
        for(int k = 0; k < size; k++)
            v[k] = false;
        for(int j = 1; j < size; j++)
        {
            if(map[i][j] == 0)
            {
                v[i] = true;
            }
        }
        int res = explore(path,c,i,v, size, i);
    }
}
int main() {
    int n = 0, m = 0;
    scanf("%d%d",&n, &m);
    int c[n + 1];
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < n + 1; j++)
        {
            if(i == j)
            {
                map[i][j] = 0;
            }
            else
                map[i][j] = 1;
        }
    }
    for(int i = 1; i < n + 1; i++)
    {
        scanf("%d", &c[i]);    
    }
    for(int i = 0; i < m; i++)
    {
        int s = 0, d = 0;
        scanf("%d%d", &s, &d);
        map[s][d] = map[d][s] = 0;
    }
    start(c,n + 1);
    printf("%d%s%d\n",maxG,maxes.size());
    return 0;
}

