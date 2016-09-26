#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isUpper(int val)
{
  //  cout << " The val is " << val << endl;
    if(val >= 65 && val <= 90)
        return true;
    else
        return false;
}
int main() {
    int q = 0;
    cin >> q;
    while(q--)
    {
        string a, b;
        cin >> a >> b;
        int bAlph[26];
        int aAlph[26];
        int aAlph2[26];
        for(int i = 0; i < 26; i++)
            bAlph[i] = aAlph[i] = aAlph2[i] = 0;
        int bSize = b.size();
        for(int i = 0; i < bSize; i++)
        {
            bAlph[(int)b[i] - 65]++;
        }
        int aSize = a.size();
        for(int i = 0; i < aSize; i++)
        {
            int val = (int)a[i];
            if(isUpper(val))
            {
               // cout << " There is an upper in a " << endl;
                aAlph[val - 65]++;
            }
            else
            {
               // cout << " Not upper " << endl;
                aAlph2[val - 97]++;
            }
        }
        bool reject = false;
        for(int i = 0; i < 26; i++)
        {
            if(aAlph[i] > bAlph[i])
            {
                //cout << " The a val is " << aAlph[i] << " and b is " <<
               // bAlph[i] << endl; 
                reject = true;
                // cout << " The a has more and the i is  " << i  << endl;
            }
            if(bAlph[i] > (aAlph[i] + aAlph2[i]))
            {
               // cout << " The i is " << i << " the 2 " << aAlph2[i] << endl;
                reject = true;
                //cout << " The b has more " << endl; 
            }
        }
        if(reject == true)
            cout << "NO" << endl;
        else
        {
            for(int i = 0; i < 26; i++)
            {
                if(aAlph[i] < bAlph[i])
                {
                   // cout << " In here " << endl;
                    int diff = bAlph[i] - aAlph[i];
                    for(int j = 0; j < aSize; j++)
                    {
                        if((int)a[j] == (i + 97))
                        {
                            a[j] = (i + 65);
                           // cout << a[j] << endl;
                            diff--;
                        }
                        if(diff == 0)
                            break;
                    }       
                }
            }
           // cout << " The a is " << a << endl;
            int end = 0;                
            for(int i = 0; i < aSize; i++)
            {
                if(isUpper((int)a[i]))
                {
                    bool found = false;
                    for(int j = end; j < bSize; j++)
                    {
                        end = j;
                        if(a[i] == b[j])
                        {
                            found = true;
                            break;
                        }
                    }
                    if(found == false)
                    {
                       // cout << " was caught here " << a <<  endl;
                        cout << "NO" << endl;
                        reject = true;
                        break;
                    }
                }
            }
            if(reject == false)
                cout << "YES" << endl;
        }
    }
    return 0;
}
