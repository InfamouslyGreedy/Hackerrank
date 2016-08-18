#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Query
{
    public:
        int l;
        int r;
        Query(int l, int r): l(l), r(r){}
        Query(){}
};
bool comp(Query a, Query b)
{
    if(a.l != b.l)
        return a.l < b.l;
    return a.r < b.r;
}
int main()
{
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    int vals[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vals[i]);
    }
    Query q[m];
    int res[m];
    for(int i = 0; i < m; i++)
    {
        int l , r = 0;
        scanf("%d%d", &l, &r);
        q[i] = Query(l,r);
        res[i] = 0;
    }
    sort(q, q + m, comp);
    int size = sqrt(n);
    int t = n / size;
    int j = 0;
    bool first = false;
    for(int i = 0; i < m; i++)
    {
        if(q[i].l < (j * t))
        {
            if(first == true)
            {
                for(int k = q[i].l; k <= q[i].r; k++)
                {                    
                    res[i] += vals[k];
                }
                first = false;
            }
            else
            {
                res[i] = res[i - 1];
                if(q[i].r > q[i - 1].r)
                {
                    for(int k = q[i - 1].r + 1; k <= q[i].r; k++)
                    {
                        res[i] += vals[k]; 
                    }
                }
                if(q[i].l > q[i - 1].l)
                {
                    for(int k = q[i - 1].l; k < q[i].l; k++)
                    {
                        res[i] -= vals[k];
                    }
                }
                if(q[i].r < q[i - 1].r)
                {
                    for(int k = q[i - 1].r; k > q[i].r; k--)
                    {
                        res[i] -= vals[k];
                    }
                }
            }
        }
        else
        {
            first = true;
            i--;
            j++;
        }
    }
    for(int i = 0; i < m; i++)
    {
        printf("%d%s%d%s%d\n", q[i].l, " " , q[i].r, " ", res[i]);
    }
    return 0;
}

