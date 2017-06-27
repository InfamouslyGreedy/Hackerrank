#include <iostream>

using namespace std;
int n = 0, m = 0;
int grid[2004][2004];
int x[1001];
int y[1001];
int a[1001];
int p[1001];
int cap[2004];

int tryFlow(int index, int flow)
{
    for(int i = 1; i < n;      
}

int ff()
{
    for(int i = 0; i < n; i++)
    {
        
    }
}

int main()
{
    for(int i = 0; i < 2004; i++)
    {
        for(int j = 0; j < 2004; j++)
        {
            grid[i][j] = 0;
        }
    }
    cin >> n >> m;
    for(int i = 1; i < (n + 1); i++)
    {
        cin >> a[i] >> p[i];
    }
    for(int i = 1; i < (m + 1); i++)
    {
        cin >> x[i] >> y[i];
    }
    cap[0] = 0;
    for(int i = 1; i < (n + 1); i++)
    {
        grid[0][i] = 1;
        cap[i] = 1;
    }
    for(int i = (n + 1); i < (n + m + 1); i++)
    {
        grid[i][(n + m + 1)] = 1;
        cap[i] = 1;
    }
    cap[n + m + 1] = n;

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(x[j] >= a[i] && y[j] <= p[i])
            {
                grid[i][j + n] = 1;
            }
        }
    }
    cout << ff() << endl;
    return 0;
}
