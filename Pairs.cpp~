#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int pairs(vector < int > a,int k) {
    int ans = 0;
    map<int, string>myMap;
    int largest = 0;
    stringstream convert;
    
    vector<int>::iterator vit = a.begin();
    vector<int>::iterator end = a.end();

    for(;vit != end; vit++)
    {
        int val = (*vit);
        string key = "swag";        
        myMap.insert(make_pair(val, key));
        if(val > largest)
        {
            largest = val;
        }  
    }
    map<int, string>::iterator it = myMap.begin();
    map<int, string>::iterator last = myMap.end();
    for(;it != last; it++)
    {
        int sum = it->first + k;
        if(sum > largest)
        {
            break;
        }
        else
        {
            if(myMap.find(sum) != last)
            {
                ans++;
            }
        }
    }
    return ans;
}

/* Tail starts here */
int main() {
    int res;
    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = pairs(_a,_k);
    cout << res;

    return 0;
}
