#include <cmath>
#include <iostream>

using namespace std;

#define PI 3.14159265

float getMag(int x, int y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}
float getDist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
float getAng(int x1, int y1, int x2, int y2, int xB, int yB)
{
    float dotVal = (x1 - xB) * (x2 - xB) + (y1 - yB) * (y2 - yB);
    float magMult = getMag(x1 - xB, y1 - yB) * getMag(x2 - xB, y2 - yB);
    return acos(dotVal/magMult) * (180.0f/PI);
}
bool inCircle(int x, int y, int xCent, int yCent, int r)
{
    if(getDist(xCent, yCent, x, y) <= (float)r)
    {
        return true;
    }
    return false;
}
bool inSquare(int x, int y, int x1, int y1, int x3, int y3)
{
    float ang = getAng(x1, y1, x, y, x3, y3);
    cout << " The cood " << x << " " << y << " and the ang " << ang << endl;
    float diagDist = getDist(x3, y3, x1, y1);
    float tDist = getDist(x3, y3, x, y);
    if(ang <= 45.0f || ang >= 270.0f && tDist <= diagDist)
    {
        return true;
    }
    return false; 
}
int main()
{
    int w = 0, h = 0;
    cin >> w >> h;
    int xCent = 0, yCent = 0, r = 0;
    cin >> xCent >> yCent >> r;
    int x1 = 0, y1 = 0, x3 = 0, y3 = 0;
    cin >> x1 >> y1 >> x3 >> y3;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(inCircle(j,i,xCent, yCent, r) || inSquare(j, i, x1, y1, x3, y3))
            {
                cout << "#";
            }  
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
    return 0;
}
