#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int q = 0;
    cin >> q;
    while(q--)
    {
        int x = 0, y = 0, z = 0;
        cin >> x >> y >> z;
        if(abs(x - z) > abs(y - z))
            cout << "Cat A" << endl;
        else if (abs(x - z) < abs(y - z))
            cout << "Cat B" << endl;
        else
            cout << "Mouse C" << endl;
    }
}
