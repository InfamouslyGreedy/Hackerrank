#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;



class comp1 // smallest first
{
    public:
        bool operator() (int a, int  b) const
        {
            return a > b;
        }
};
class comp2 // largest first
{
    public:
        bool operator() (int a, int  b) const
        {
            return a < b;
        }
};

/*
 * Complete the function below.
 */
vector < int > wiggleArrangeArray(vector < int > intArr) 
{
    typedef priority_queue<int, vector<int>, comp1> smallFirst;   
    typedef priority_queue<int, vector<int>, comp2> largeFirst;

    smallFirst q1;
    largeFirst q2;
    
    vector<int>::iterator it = intArr.begin();
    vector<int>::iterator last = intArr.end();
    int count;
    for(;it != last; it++)
    {
        count++;
        q1.push(*it);
        q2.push(*it);
    }

    vector<int> res;
    for(int i = 0; i < count; i++)
    {
        res.push_back(q2.top());
        q2.pop();
        i++;
        if(i >= count)
        {
            break;
        }
        res.push_back(q1.top());
        q1.pop();
    }
    return res;

}


int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < int > res;
    
    int _intArr_size;
    cin >> _intArr_size;
    
    vector<int> _intArr;
    int _intArr_item;
    for(int _intArr_i=0; _intArr_i<_intArr_size; _intArr_i++) {
        cin >> _intArr_item;
    
        _intArr.push_back(_intArr_item);
    }
    
    res = wiggleArrangeArray(_intArr);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }
    
    fout.close();
    return 0;
}
