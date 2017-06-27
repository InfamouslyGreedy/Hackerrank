#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long int lli;
void fillVals(int hackoVals[], int vals[], int n)
{
    vals[0] = vals[1] = vals[2] = vals[3] =  0;
    for(int i = 1; i < (n + 1); i++)
    {
        for(int j = 1; j < (n + 1); j++)
        {
            int a = (((i * j) % 7) * ((i * j) % 7) % 7);

            int b = (j * ((n + 1) - i)) % 7;
            b = ((b * b) % 7); 
            //  cout << " The a0 " << a << " The b0 " << b << endl;
            if(hackoVals[a - 1] != hackoVals[b - 1])
                vals[1]++;
            
            b = (((n + 1) - i) * ((n + 1) - j)) % 7;
            b = ((b * b) % 7); 
            //cout << " The a1 " << a << " The b1 " << b << endl;
            if(hackoVals[a - 1] != hackoVals[b - 1])
                vals[2]++;
            
            b = (((n + 1) - j) * i) % 7;
            b = ((b * b) % 7); 
            //cout << " The a2 " << a << " The b2 " << b << endl;
            if(hackoVals[a - 1] != hackoVals[b - 1])
                vals[3]++;
        }
    }
    cout << " vals " << vals[0] <<  " " << vals[1] << " " <<  vals[2] <<  " " << vals[3] << endl;
}
int main()
{
    int n = 0, q = 0;
    cin >> n >> q;
    int hackoVals[7] = {1, 0, 1, 0, 0, 1, 1};
    int vals[4];
    fillVals(hackoVals, vals, n);
    for(int i = 0; i < q; i++)
    {
        int ang = 0;
        cin >> ang;
        int ind = (ang/90) % 4;
        cout << vals[ind] << endl;
    }
    return 0;
}


