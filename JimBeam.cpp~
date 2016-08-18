#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Point
{
    public:
        double x;
        double y;
    Point(double x, double y):x(x), y(y){}
};
double ori(Point p1, Point p2, Point p3)
{
    double res = ((p2.y - p1.y) * (p3.x - p2.x)) - ((p3.y - p2.y) * (p2.x -
    p1.x)); 
    if(res > 0)
        return 1;
    else if(res < 0)
        return -1;
    else
        return 0;
}
bool overlap(Point p1, Point p2, Point p3, Point p4)
{
    if(p4.x <= p1.x && p3.x >= p2.x && p4.y <= p1.y && p3.y >= p2.y)
        return true;
    else if(p4.x <= p1.x && p4.x >= p2.x && p4.y >= p1.y && p4.y <= p2.y)
        return true;
    else if(p4.x >= p1.x && p4.x <= p2.x && p4.y <= p1.y && p4.y >= p2.y)
        return true;
    else if(p4.x >= p1.x && p4.x <= p2.x && p4.y >= p1.y && p3.y <= p2.y)
        return true;
    else 
        return false;
}
bool intersect(Point p1, Point p2, Point p3, Point p4)
{
    double o1 = ori(p1,p2,p3);
    double o2 = ori(p1,p2,p4);
    double o3 = ori(p3,p4,p1);
    double o4 = ori(p3,p4,p2);
    if(o1 != o2 && o3 != o4)
    {
        return true;
    }
    else if(o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0)
    {
        //printf(" colinear \n");
        if(overlap(p1,p2,p3,p4))
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{
    int t = 0;
    scanf("%d", &t);
    while(t--)
    {
        double x1 = 0,y1 = 0,x2 = 0,y2 = 0,xm = 0,ym = 0;
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&xm,&ym);
        Point p1 = Point(x1,y1);
        Point p2 = Point(x2,y2);
        Point p3 = Point(xm,ym);
        Point p4 = Point(0,0);
        
        if(intersect(p1,p2,p3,p4))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

