#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0, p = 0;
    cin >> n >> p;
    int a = p/2;
    int b = 0;
    if((n % 2) == 0)
    {
        if(p == n)
            b = 0;
        else if(p == (n - 1))
            b = 1;
        else
            b = (n - p)/2;
    }
    else
    {
        b = (n - p)/2;
    }
    cout << min(a,b) << endl;
    return 0;
}
