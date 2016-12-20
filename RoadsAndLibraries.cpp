#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;
class City
{
    public:
        int id;
        bool visited;
        vector< int > adj;
        City(int id):id(id), visited(false){}
};
int explore(City * cities[], int currId)
{
    City * curr = cities[currId];
    curr->visited = true;
    int size = curr->adj.size();
    int res = 1;
    for(int i = 0; i < size; i++)
    {
        int nId = curr->adj[i];
        if(cities[nId]->visited == false)
            res += explore(cities, nId);
    }
    return res;
}
void dfs(City * cities[], vector< int > & sizes, int cityNum)
{
    for(int i = 1; i < cityNum; i++)
    {
        if(cities[i]->visited == false)
        {
            sizes.push_back(explore(cities,i));
        }
    }
}
int main()
{
    int q = 0;
    cin >> q;
    while(q--)
    {
        int n = 0, m = 0, libCost = 0, rdCost = 0;
        cin >> n >> m >> libCost >> rdCost;
        City * cities[n + 1];
        for(int i = 1; i < (n + 1); i++)
        {
            cities[i] = new City(i); 
        }
        for(int i = 0; i < m; i++)
        {
            int s = 0, d = 0;
            cin >> s >> d;
            cities[s]->adj.push_back(d);
            cities[d]->adj.push_back(s);
        }
        vector<int> sizes;
        dfs(cities, sizes, n);
        lli res = 0;
        int size = sizes.size();
        for(int i = 0; i < size; i++)
        {
            if(libCost > rdCost)
            {
                res += (((sizes[i] - 1) * rdCost) + libCost); 
            }
            else
            {
                res += (sizes[i] * libCost);
            }
        }
        cout << res << endl;
    }
    return 0;
}
