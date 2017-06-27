#include <iostream>

using namespace std;
int minInt = 1000000;
int main()
{
    int n = 0;
    cin >> n;
    int vals[n];
    int minInd = 0;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> vals[i];
        if(vals[i] < minInt)
        {
            count = 1;
            minInt = vals[i];
            minInd = i;
        }
        else if(vals[i] == minInt)
        {
            count++;
        }
    }
    vals[minInd] *= 2;
    minInt = 1000000;
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        minInt = min(vals[i], minInt);
    }
    //cout << " The count is " << count << endl;
    if(count == 1)
        cout << minInt << " " << 1 << endl;
    else
        cout << minInt << " " << n << endl;
    return 0;
}
