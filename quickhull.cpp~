#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Point
{
    public:
        double x;
        double y;
        Point(double x, double y):x(x),y(y){}
        Point(){}
};
vector < Point > hull;
int ori(Point p1, Point p2, Point p3)
{
    double test = ((p2.y - p1.y) * (p3.x - p2.x)) - ((p3.y - p2.y) * (p2.x - p1.x));
    if(test > 0)
        return 1;
    else if (test < 0)
        return -1;
    else 
        return 0;
}
double getSlope(Point a, Point b, bool & vert)
{
    if(a.x == b.x)
    {
        vert = true;
        return 0;
    }
    else    
        return (double)(b.y - a.y)/(double)(b.x - a.x);    
}
double getDist(Point a, Point b, Point c)
{
    bool vert = false;
    double m = getSlope(a,b,vert);
    if(vert)    
        return abs(a.x - c.x);    
    else if(m == 0)
        return abs(a.y - c.y);
    else
    {
        double m2 = ((double)1/m) * -1;
        double c1 = a.y  - (m * a.x);
        double c2 = c.y - (m2 * c.x);
        double xInt = (c2 - c1)/(m - m2);
        double yInt = (m * a.x) + c1;
        return sqrt(pow(yInt - c.y, 2) + pow(xInt - c.x, 2));
    }
}
void findHull(Point a, Point b, vector < Point > s)
{
    int size = s.size();
    if(size == 0)
        return;
    double maxDist = -1;
    Point nHull;
    for(int i = 0; i < size; i++)
    {
        double dist = getDist(a,b,s[i]);
        if(dist > maxDist)
        {
            maxDist = dist;
            nHull = s[i];
        }
    }
    hull.push_back(nHull);
    vector< Point > s1;
    vector< Point > s2;
    for(int i = 0; i < size; i++)
    {
        if(ori(nHull, a, s[i]) > 0)
            s1.push_back(s[i]);
        if(ori(b,nHull,s[i]) > 0)
            s2.push_back(s[i]);
    }
    findHull(a,nHull, s1);
    findHull(nHull,b,s2);
}
void quickHull(Point points[], int n)
{
    double maxX = numeric_limits<double>::min();
    double minX = numeric_limits<double>::max();
    Point xMax;
    Point xMin;
    for(int i = 0; i < n; i++)
    {
        if(points[i].x > maxX)
        {
            xMax = points[i];
            maxX = points[i].x;
        }
        if(points[i].x < minX)
        {
            xMin = points[i];
            minX = points[i].x;
        }
    }
    hull.push_back(xMax);
    hull.push_back(xMin);

    vector <Point> s1;
    vector <Point> s2;
    for(int i = 0; i < n; i++)
    {
        if(ori(xMax, xMin, points[i]) > 0)
            s1.push_back(points[i]);
        if(ori(xMin, xMax, points[i]) > 0)
            s2.push_back(points[i]);
    }
    findHull(xMin, xMax, s1);
    findHull(xMax, xMin, s2);
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n = 0;
    scanf("%d",&n);
    Point points[n];
    for(int i = 0; i < n; i++)
    {
        double x = 0, y = 0;
        scanf("%lf%lf",&x,&y);
        points[i] = Point(x,y);
    }
    quickHull(points,n); 
    int hSize = hull.size();
    for(int i = 0; i < hSize; i++)
    {
        printf("%lf%s%lf\n", hull[i].x," ", hull[i].y);
    }
    return 0;
}

