#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef unordered_map<char, int>::iterator uMITType;
int globIndex = 0;
class Node
{
    public:
        char id;
        bool root;
        bool end;
        int index;
        int count;
        Node(char id, bool root, bool end)
        {
            this->id = id;
            this->index = globIndex++;
            this->root = root;
            this->end = end;
            this->count = 1;
        }
        vector<int> vecAdj;
        unordered_map<char, int> adj;
};
int createNode(char id, bool root, bool end, vector<Node > & nodes)
{
    Node newNode = Node(id, root, end);
    nodes.push_back(newNode);
    return newNode.index;
}
void addWord(vector<Node > & nodes, string word)
{
    int size = word.size();
    int currInd = 0;
    bool end = false;
    for(int i = 0; i < size; i++)
    {
        uMITType it = nodes[currInd].adj.find(word[i]);
        if(i == (size - 1))
            end = true;
        int index = 0;
        if(it == nodes[currInd].adj.end())
        {
            index = createNode(word[i], false, end, nodes);
            nodes[currInd].adj.insert(make_pair(word[i], index));
        }
        else
        {
            nodes[it->second].end = nodes[it->second].end | end;
            nodes[it->second].count++;
            index = it->second;
        }
        currInd = index;
    }
}
int numPaths(vector< Node > & nodes, string word)
{
    int size = word.size();
    int currInd = 0;
    for(int i = 0; i < size; i++)
    {
        uMITType it = nodes[currInd].adj.find(word[i]);
        if(it == nodes[currInd].adj.end())
        {
            return 0;
        }
        else
        {
            currInd = it->second;
        }
    }
    return nodes[currInd].count;
}
int main()
{
    int n = 0;
    cin >> n;
    vector< Node > nodes;
    createNode('A', true, false, nodes);
    while(n--)
    {
        string instr;
        string word;
        //Create the root node 
        cin >> instr >> word;
        if(instr.compare("add") == 0)
        {
            addWord(nodes, word);
            //cout << " The after size " << nodes[0].adj.size() << endl;
        }
        else
        {
            cout << numPaths(nodes, word) << endl;
        }
    }
    return 0;
}
