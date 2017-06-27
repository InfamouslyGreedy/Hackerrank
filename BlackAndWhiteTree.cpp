#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int > pii;
int n = 0, m = 0;
class Node
{
    public:
        int id;
        bool visited;
        bool white;
        vector<int>adj;
        Node(int id):id(id), visited(false), white(false){}
        Node(){}
};
void explore(Node nodes[], int curr, vector<int> & comp, bool white)
{
   nodes[curr].visited = true;
   nodes[curr].white = white;
   int size = nodes[curr].adj.size();
   for(int i = 0; i < size; i++)
   {
        int ind = nodes[curr].adj[i];
        if(nodes[ind].visited == false)
        {
            explore(nodes, ind, comp, (white ^ true));
        }
   }
   comp.push_back(curr);
}
int dfs(Node nodes[], vector< pii > & newEdges)
{
    vector< vector< int > > comps;
    bool white = true;
    for(int i = 1; i < (n + 1); i++)
    {
        if(nodes[i].visited == false)
        {
            vector< int > currComp;
            //cout << " We are restarting " << endl;
            explore(nodes, i, currComp, white);
            comps.push_back(currComp);
        }
    }

    int size = comps.size();
    for(int i = 0; i < (size - 1); i++)
    {
        int currInd = comps[i][0];
        newEdges.push_back(make_pair(comps[i][0], comps[i + 1][0]));
    }

    int wCount = 0;
    int bCount = 0;
    for(int i = 1; i < (n + 1); i++)
    {
        if(nodes[i].white)
            wCount++;
        else
            bCount++;
    }
    return abs(wCount - bCount);
}
int main()
{
    cin >> n >> m;
    Node nodes[n + 1];
    for(int i = 0; i < (n + 1); i++)
        nodes[i] = Node(i);
    for(int i = 0; i < m; i++)
    {
        int s = 0, d = 0;
        cin >> s >> d;
        nodes[s].adj.push_back(d);
        nodes[d].adj.push_back(s);
    }
    vector< pii > newEdges;
    int diff = dfs(nodes, newEdges);
    int k = newEdges.size();
    cout << diff << " " << k << endl;
    for(int i = 0; i < k; i++)
        cout << newEdges[i].first << " " << newEdges[i].second << endl;
}
