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
    string s;
    cin >> s;
    long n;
    cin >> n;
    int size = s.size();
    long times = n/size, rem = n % size, count = 0, remC = 0;
    for(int i = 0; i < size; i++)
    {
        if((int)s[i] == 'a')
            count++;
    }
    count *= times;
    for(int i = 0; i < rem; i++)
    {
        if((int)s[i] == 'a')
            count++;
    }
    cout << count << endl; 
    return 0;
}
