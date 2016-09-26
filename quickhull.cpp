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
double detArea(Point p1, Point p2, Point p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}
void findHull(Point a, Point b, vector < pair< Point, double >  > s)
{
    int size = s.size();
    if(size == 0)
        return;
    double maxDist = -1;
    Point nHull;
    for(int i = 0; i < size; i++)
    {
        if(s[i].second > maxDist)
        {
            maxDist = s[i].second;
            nHull = s[i].first;
        }
    }
    hull.push_back(nHull);
    vector< pair<Point, double> > s1;
    vector< pair<Point, double> > s2;
    for(int i = 0; i < size; i++)
    {
        int area = detArea(a, nHull, s[i].first);
        if(area > 0)
            s1.push_back(make_pair(s[i].first, area));
        area = detArea(nHull, b, s[i].first);
        if(area > 0)
            s2.push_back(make_pair(s[i].first,area));
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

    vector < pair< Point, double > > s1;
    vector < pair< Point, double > > s2;
    for(int i = 0; i < n; i++)
    {
        double a = detArea(xMin, xMax, points[i]);
        if(a > 0)
            s1.push_back(make_pair(points[i],a));
        a = detArea(xMax, xMin, points[i]);
        if(a > 0)
            s2.push_back(make_pair(points[i],a));
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

