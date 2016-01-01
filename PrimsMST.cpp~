#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class Edge;
class GNode
{
    public:
        GNode(int key): visited(false),key(key){}
        int key;
        bool visited;
        vector<Edge *> edges;
};
class Edge
{
    public:
        Edge(GNode * adj, long length):adj(adj), length(length){}
        GNode * adj;
        long length;
};
class Graph
{
    public:
        map<int, GNode *>allNodes;
};

class comp
{
    public:
        bool operator() (Edge * a, Edge * b) const
        {
            if(a->length == b->length)
            {
                return a->adj->key > b->adj->key;
            }
            else
            {
                return a->length > b->length;
            }
        }
};

int main() 
{
    int nodeAm = 0;
    int edgeAm = 0;
    cin >> nodeAm >> edgeAm;
    Graph * currGraph = new Graph();
    for(int i = 1; i <= nodeAm; i++)
    {
        GNode * current = new GNode(i);
        currGraph->allNodes.insert(make_pair(i, current));
    }
    for(int i = 0; i < edgeAm; i++)
    {
        int x = 0,y = 0;
        long r = 0;
        cin >> x >> y >> r;
        GNode * currX = currGraph->allNodes.find(x)->second;
        GNode * currY = currGraph->allNodes.find(y)->second;
        Edge * toX = new Edge(currX, r);
        Edge * toY = new Edge(currY, r);
        currX->edges.push_back(toY);
        currY->edges.push_back(toX);
    }
    int start = 0;
    cin >> start;
    typedef priority_queue<Edge *,vector<Edge *>,comp> mypq_type;
    mypq_type pQ;
    GNode * curr = currGraph->allNodes.find(start)->second;
    Edge * init = new Edge(curr, 0);
    pQ.push(init);
    long total = 0;
    while(!(pQ.empty()))
    {
        Edge * current = pQ.top();
        pQ.pop();
        if(current->adj->visited == false)
        {    
            current->adj->visited = true;
            // cerr << " The current length " << current->length << endl;
            total += current->length;
            vector<Edge *>::iterator vin = current->adj->edges.begin();
            vector<Edge *>::iterator ven = current->adj->edges.end();
            for(;vin != ven; vin++)
            {
                if((*vin)->adj->visited == false)
                {
                    pQ.push(*vin);
                }
            }
        }
    }
    cout << total << endl;
    return 0;
}

