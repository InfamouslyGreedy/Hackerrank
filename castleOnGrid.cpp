#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;


class mycomparison
{
    public:
        bool operator()(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b)
        {
            return a.first > b.first; 
        }
};
void setArr(int r[], int c[],int n, int dir)
{
    for(int ind = 0; ind < n ; ind++)
    {
        if(dir == 0)
        {
            r[ind] = -(ind + 1);
            c[ind] = 0;
        }
        if(dir == 1)
        {
            r[ind] = (ind + 1);
            c[ind] = 0;
        }
        if(dir == 2)
        {
            r[ind] = 0;
            c[ind] = -(ind + 1);
        }
        if(dir == 3)
        {
            r[ind] = 0;
            c[ind] = (ind + 1);
        }
    }
}
int main() 
{
    int n = 0;
    scanf("%d", &n);
   // printf("%s%d\n", " successfully read ", n);
    bool v[n][n];
    bool allowed[n][n];
    int dist[n][n];
    char input[n + 1][n + 1];
    for(int i = 0; i < n; i++)
    {
        scanf("%s", input[i]); 
        //printf("%s%s\n", " successfully read ", input[i]);
    }
    typedef priority_queue< pair< int, pair< int, int > > ,vector< pair< int, pair< int, int > > >,mycomparison> mypq_type;
    mypq_type Q;
   // printf("%s\n", " about to enter the loop ");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            v[i][j] = false;
            dist[i][j] = 100000;
            char in[3];
            char no = 'X';
            if((int)input[i][j] == (int)no)
                allowed[i][j] = false;
            else
                allowed[i][j] = true;
            Q.push(make_pair(dist[i][j], make_pair(i,j)));
        }
    }
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    //printf("%s%d%s\n", " Just read n ", n, " about t read the start and end points ");
    
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if(x1 == x2 && y1 == y2)
    {
        printf("%d", 0);
        return 0;
    }
    int r[(n - 1)];
    int c[(n - 1)];
    Q.push(make_pair(1, make_pair(x1,y1)));
    while(!(Q.empty()))
    {
        pair<int, pair<int, int> > curr = Q.top();
        Q.pop();
        int currX = curr.second.first;
        int currY = curr.second.second;
        int add = 0;
        if(currX == x1 && currY == y1)
            add = 0;
        else
            add = 1;
        
        if(v[currX][currY] == false)
        {
           // printf("%s%d%s%d%s%d\n", " The curr " , currX, " ", currY, " and dist ", curr.first);
            v[currX][currY] = true;
            dist[currX][currY] = curr.first;
            for(int i = 0; i < 4; i++)
            {
                setArr(r,c,n,i);
                for(int j = 0; j < (n-1); j++)
                {
                    int x = currX + r[j];
                    int y = currY + c[j];
                  //  printf("%s%d%s%d%s%d%s%d\n", " The cood ", x, " ",y
                   // , " ", r[j], " ",c[j]);
                    if(x >= 0 && x < n && y >= 0 && y < n && allowed[x][y])
                    {
                        if(v[x][y] == false)
                        {
                            if(curr.first + add < dist[x][y])
                            {
                                Q.push(make_pair(curr.first + add, make_pair(x,y)));
                            }
                        }
                    }
                    else
                        break;
                }
            }
        }
    }
    printf("%d\n", dist[x2][y2]);
    return 0;
}
