#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include<sstream>
using namespace std;

int n = 0, m = 0;

bool inRange(int test, int ref)
{
    bool okay = false;
   // cout << " test " << test << " ref " << ref << " anded " << (1 & 6) << endl;
    if((test & ref) != 0)
    {
      //  cerr << " The test " << test << " the ref " << ref << endl;
        for(int i = 0; i < n; i++)
        {
            int val = pow(2,i);
            if((val & ref) != 0)
                okay = true;
            if((val & test) != 0 && okay == false)
                return false;

        }
        okay = false;
        for(int i = (n - 1); i >= 0; i--)
        {
            int val = pow(2,i);
            if((val & ref) != 0)
                okay = true;
            if((val & test) != 0 && okay == false)
                return false;
        }
        return true;
    } 
    return false; 
}

string getBin(int x)
{
    string res = "";
   /** while(x != 0)
    {
        if(x % 2 == 0)
            res = "0" + res;
        else
            res = "1" + res;
        x /= 2;
    }
    int size = n - res.size();
    for(int i = 0; i < size; i++)
        res = "0" + res; **/
    return res;
}
int getInt(char *  binStr)
{
    int res = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(binStr[(n - 1) - i] == '1')
            res += pow(2, (n - 1) - i);
    } 
  //  cout << " The res " << res << endl;
    return res;
}
void setVals(int val[], int size, int x, int c, char * binString)
{
    if(c == 2)
        val[0]^=x;
    else
        val[0] = x;
    for(int i = 1; i < size; i++)
    {
        if(inRange(i,getInt(binString)))
        {
           // cout << " The i " << i << " bin " << getBin(i) << endl;
            if(c == 2)
                val[i] ^= x;
            else
                val[i] = x;
        }
    }
}
int main() 
{
    cin >> n >> m;
    int size = pow(2,n);
    int val[size];

    for(int i = 0; i < size; i++)
    {
        val[i] = 0;
    }
    string s;
    char binStr[n + 1];
    int c = 0, x = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> c; 
        if(c == 1)
        {
            cin >> x;
            cin >> binStr;
            cerr << " The binStr " << binStr << endl;
            setVals(val,size,x,1,binStr);
        }
        else if (c == 2)
        {
            cin >> x;
            cin >> binStr;
            setVals(val,size,x,2,binStr); 
        }
        else 
        {
           cin >> binStr;
          // cout << " The print out " << getInt(binStr) << endl;
           cout << val[getInt(binStr)] << endl; 
        }
    }
    return 0;
}
