#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string reverse(string val)
{
    int size = val.size();
    string res = "";
    for(int i = 0; i < size; i++)
    {
        res = val[i] + res;
    }
    return res;
}
void fill(int arr[])
{
    int val = 48;
    int ind = 0;
    for(int i = 0; i < 10; i++)
    {
        arr[ind] = val++;
        ind++;
    }
    val = 65;
    for(int i = 0; i < 26; i++)
    {
        arr[ind] = val++;
        ind++;
    }
    val = 97;
    for(int i = 0; i < 26; i++)
    {
        arr[ind] = val++;
        ind++;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string a;
    string b;
    cin >> a;
    cin >> b;
    int aSize = a.size();
    int bSize = b.size();
    int prefix[aSize + 1][bSize + 1];
    int suffix[aSize + 1][bSize + 1];
    for(int i = 0; i < aSize + 1; i++)
    {
        for(int j = 0; j < bSize + 1; j++)
        {
            prefix[i][j] = suffix[i][j] =  0;
        }      
    }
    for(int i = 1; i < aSize + 1; i++)
    {
        for(int j = 1; j < bSize + 1; j++)
        {
            if((int)a[i - 1] == (int)b[j - 1])
                prefix[i][j] = prefix[i - 1][j - 1] + 1;
            else
                prefix[i][j] = max(prefix[i - 1][j], prefix[i][j - 1]);
        }
    }
    int l = prefix[aSize][bSize];
   // cout << " The l " << l << endl;
    string aRev = reverse(a);
    string bRev = reverse(b);
    for(int i = 1; i < aSize + 1; i++)
    {
        for(int j = 1; j < bSize + 1; j++)
        {
            if((int)aRev[i - 1] == (int)bRev[j - 1])
                suffix[i][j] = suffix[i - 1][j - 1] + 1;
            else
                suffix[i][j] = max(suffix[i - 1][j], suffix[i][j - 1]);

           // cerr << suffix[i][j] << " ";
        }
       // cerr << endl;
    }
    int arr[62];
    fill(arr);
    int res = 0;
    for(int i = 0; i < aSize + 1; i++)
    {
        for(int j = 0; j < 62; j++)
        {
            for(int k = 0; k < bSize; k++)
            {
                int p = 0, s = 0;
                if(arr[j] == (int)b[k])
                {
                        p = prefix[i][k];
                        s = suffix[aSize - i][bSize - (k + 1)];

                       /* cout << " The test " << (char)arr[j] << " the b "
                            << b[k] <<" the ind " << i << " the b Ind "
                            << k << " p " << p << " s " << s << endl; */
                        if(p + s == l)
                        {
                          /*  cout << " The test " << (char)arr[j] << " the b "
                                << b[k] <<" the ind " << i << " the b Ind "
                                << k << endl;  */
                            res++;
                        }
                }
            }
        }
    }
    cout << res << endl;
    
    return 0;
}
