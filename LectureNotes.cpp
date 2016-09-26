#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int n;
    int k;
    cin >> n >> k;
    string s;
    cin >> s;
    int friends[k];
    for(int i = 0; i < k; i++)
        cin >> friends[i];
    int size = s.size();
    bool found = false;
    for(int i = 0; i < k; i++)
    {
        int ind = friends[i] - 1;
        if(s[ind] == '0')
        {
            found = true;
            break;
        }
    }
    if(found)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
