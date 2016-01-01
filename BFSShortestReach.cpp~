#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

class GNode{
    public:
        int key;
        int dist;
        bool visited;
        vector<GNode*> adjNodes;
        bool inQueue;
        GNode(int key):dist(-1),visited(false),key(key),inQueue(false){}
};
class Graph{
    public:
        map<int, GNode*> allNodes;      

};
int main() 
{
    int t = 0;
    cin >> t;
    while(t--)
    {
       int nodeAm = 0;
       int edgeAm = 0;
       cin >> nodeAm >> edgeAm;
       Graph currGraph = Graph();
       GNode * current;
       for(int i = 1; i <= nodeAm; i++)
       {
           current = new GNode(i);
           currGraph.allNodes.insert(make_pair(i, current));
       }
       
       for(int i = 0; i < edgeAm; i++)
       {
            int x = 0, y = 0;
            cin >> x >> y;
            ((currGraph.allNodes.find(x))->second)->adjNodes.push_back((currGraph.allNodes.find(y))->second);
            ((currGraph.allNodes.find(y))->second)->adjNodes.push_back((currGraph.allNodes.find(x))->second);
       }

       int start = 0;
       cin >> start;
       list<GNode *> queue;

       current = currGraph.allNodes.find(start)->second;
       current->dist = 0;
       queue.push_back(current);
       current->inQueue = true;
       while(!(queue.empty()))
       {
            current = queue.front();
            current->visited = true;
            queue.pop_front();
            vector<GNode*>::iterator it = current->adjNodes.begin();
            vector<GNode*>::iterator last = current->adjNodes.end();
            for(;it != last; it++)
            {
                if((*it)->visited == false)
                {
                   if((*it)->inQueue == false)
                   {
                        (*it)->dist = current->dist + 6;
                        queue.push_back(*it);
                        (*it)->inQueue = true;
                   }
                }
            }
       }
       map<int, GNode*>::iterator it = currGraph.allNodes.begin();
       map<int, GNode*>::iterator last = currGraph.allNodes.end();
       for(;it != last; it++)
       {
           if(it->second->key != start)
           {
                cout << (it->second)->dist << " "; 
           }
       } 
       cout << endl; 
    } 
    return 0;
}
