#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int q = 0;
    cin >> q;
    while(q--)
    {
        int n = 0;
        cin >> n;
        int evenMisp = 0, oddMisp = 0;
        int evenExp = 0, oddExp = 0;
        for(int i = 0; i < n; i++)
        {
            int val = 0;
            cin >> val;
            if(i % 2 == 0)
            {
                if(val % 2 != 0)
                {
                    evenMisp++;
                }
                else
                {
                    evenExp += (val - 2);
                }
            }
            else
            {
                if(val % 2 == 0)
                {
                    oddMisp++;
                }
                else
                {
                    oddExp += (val - 1);
                }
            }
        }
        if(oddMisp != evenMisp)
        {
            int diff = abs(evenMisp - oddMisp);
            if(diff % 2)
                cout << -1 << endl;
            else
            {
                if((oddExp + evenExp) >= diff)
                {
                    cout << (diff + (min(evenMisp, oddMisp))) << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
        else
            cout << oddMisp << endl;
    }
    return 0;
}
