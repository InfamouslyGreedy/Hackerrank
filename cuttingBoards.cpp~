#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

class Slicer
{
    public:
        string key;
        long long cost;
        Slicer(string key, long long cost)
        {
            this->cost = cost;
            this->key = key;
        }
};
class mycomparison
{
    public:
    bool operator() (Slicer * a, Slicer * b) const
    {
        return a->cost < b->cost;
    }
};
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long t = 0;
    cin >> t;
    while(t--)
    {
        long long m, n = 0;
        cin >> m >> n;
        vector<Slicer*> allSlicers;
        allSlicers.clear();
        long long xVal = 0, yVal = 0;
        for(long long i = 0; i < (m - 1); i++)
        {
            cin >> yVal;   
           // cerr << " the yVal " << yVal << endl;
            Slicer * ySlicer = new Slicer("y",yVal);
            allSlicers.push_back(ySlicer);
            //cerr << " just made " << ySlicer->key << " and cost " << ySlicer->cost;

        }
        for(long long i = 0; i < (n - 1); i++)
        {
            cin >> xVal;
            Slicer * xSlicer = new Slicer("x",xVal);
            allSlicers.push_back(xSlicer);
        }
        long long xCount = 0;
        long long yCount = 0;
        long long total = 0;
        long long weight = 0;
            
        typedef priority_queue<long long,vector<Slicer *>,mycomparison>
        mypq_type;
        mypq_type myQ;
        vector<Slicer *>::iterator it = allSlicers.begin();
        vector<Slicer *>::iterator last = allSlicers.end();
        for(;it != last; it++)
        {
            myQ.push((*it));
        }
        while(!myQ.empty())
        {
            Slicer * currMax = myQ.top();
           // cerr << " The curr " << currMax->key << " and cost " <<
           // currMax->cost << endl;
            myQ.pop();
            long long modder = pow(10,9) + 7;
            if(currMax->key == "x")
            {
                xCount++;
                weight = (((yCount + 1) % modder) * (currMax->cost %
                modder));
            }
            if(currMax->key == "y")
            {
                yCount++;
                weight = (((xCount + 1) % modder) * (currMax->cost %
                modder));
            }
            total= ((total % modder) + (weight % modder)) % modder;
            // cerr << " xCount " << xCount << " upbound " << (n-1) << endl;
        }
        cout << total << endl;
    }

    return 0;
}
