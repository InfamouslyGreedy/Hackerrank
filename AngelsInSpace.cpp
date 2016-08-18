#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class cood
{
    public:
        int x, y, z;
    cood(int x, int y, int z): x(x), y(y), z(z){}
    cood(){}
};
double getAng(cood a, cood b, cood c)
{
    double x1 = a.x - b.x, y1 = a.y - b.y, z1 = a.z - b.z;
    double x2 = c.x - b.x, y2 = c.y - b.y, z2 = c.z - b.z;
    
    double l1 = sqrt(pow(x1,2) + pow(y1,2) + pow(z1,2));
    double l2 = sqrt(pow(x2,2) + pow(y2,2) + pow(z2,2));
    
    double dotP = (x1 * x2) + (y1 * y2) + (z1 * z2);
    return acos((dotP/(l1 * l2)));
    
}
int main() {
    int n = 0;
    scanf("%d", &n);
    cood pts[n];
    for(int i = 0; i < n; i++)
    {
        int x = 0, y = 0, z = 0;
        scanf("%d%d%d",&x, &y, &z);
        pts[i] = cood(x,y,z);
    }
    int totP = 1;
    for(int i = n; i > (n - 3); i--)
    {
        totP *= i; 
    }
    totP /= 6;
    double prob = (double)1/(double)totP;
    double totAng = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                totAng += getAng(pts[i], pts[j], pts[k]);
            }
        }
    }
    printf("%.11f\n",(prob * totAng)); 
    return 0;
}
