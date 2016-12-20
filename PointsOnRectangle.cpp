#include <iostream>
#include <algorithm>

using namespace std;

int minVal = -100000;
int maxVal = 100000;

class Point
{
    public:
        int x;
        int y;
        Point(int x, int y):x(x), y(y){}
        Point(){}
};
bool isOnline(int val, bool horiz, Point p)
{
    if(horiz)
        return val == p.y;
    else
        return val == p.x;
}
int main()
{
    int q = 0;
    cin >> q;
    while(q--)
    {
        int n = 0;
        cin >> n;
        Point ps[n];
        bool v[n];
        int minX = maxVal, maxX = minVal, minY = maxVal, maxY = minVal;

        for(int i = 0; i < n; i++)
        {
            int x = 0, y = 0;
            cin >> x >> y;
            ps[i] = Point(x,y);
            minX = min(minX, x);
            maxX = max(maxX, x);
            minY = min(minY, y);
            maxY = max(maxY, y);
            v[i] = false;
        }
        for(int i = 0; i < n; i++)
        {
            if(isOnline(minX, false, ps[i]))
                v[i] = true;
            if(isOnline(maxX, false, ps[i]))
                v[i] = true;
            if(isOnline(minY, true, ps[i]))
                v[i] = true;
            if(isOnline(maxY, true, ps[i]))
                v[i] = true;
        }
        bool comp = true;
        for(int i = 0; i < n; i++)
        {
            if(v[i] == false)
            {
                comp = false;
                break;
            }
        }
        if(comp)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
