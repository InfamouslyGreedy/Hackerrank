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
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        char s[100001];
        scanf("%s", s);
        int size = strlen(s);
       // printf("%s%s%s%d\n", " The string is ", s, " and size ", size);
        int alph[26];
        for(int i = 0; i < 26; i++)
            alph[i] = 0;
        for(int i = 0; i < size; i++)
        {
            alph[(int)s[i] - 97]++;
           // printf("%s%d%d%d\n", " The value of letter ", (int)s[i], (int)s[i] - 97,
          //  alph[(int)s[i] - 97]);
        }
        int res = 0;
        for(int i = 0; i < 26; i++)
        {
            if(alph[i] != 0)
                res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
