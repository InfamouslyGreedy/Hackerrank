#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool grid[1001][1001] = {};
int nodes[1001];
int weights[1001];
bool visited[1001];

class Point
{
    public:
    int x, y;
    double ang;
    int ind;
    Point(int x, int y, int ind) : x(x), y(y), ind(ind){} 
};
bool myfunc(Point a, Point b)
{
    return a.ang < b.ang;
}
void clearVisited(int n)
{
    for(int i = 1; i < (n + 1); i++)
    {
        visited[i] = false;
    }
}
int setWeights(int ind, int n)
{
    int weight = 0;
    visited[ind] = true;
    for(int i = 1; i < (n + 1); i++)
    {
        if(grid[ind][i] && visited[i] == false)
        {
            weight += setWeights(i, n);
        }
    }
    weight++;
    weights[ind] = weight;
    return weight;
}
double getMag(int x, int y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}
double dot(int x1, int y1, int x2, int y2)
{
    return (x1 * x2) + (y1 * y2); 
}
double getAng(int x, int y, Point p)
{
    int x2 = p.x - x;
    int y2 = p.y - y;
    return acos(dot(0, 1, x2, y2)/getMag(x2, y2)); 
}
void assignPoints(int ind, vector< Point > points, int n)
{
    //cout << " The currInd " << ind << endl;
    visited[ind] = true;
    int size = points.size();
    int minInd = -1;
    int minX = 1000000;
    int y;
    for(int i = 0; i < size; i++)
    {
        //cout << points[i].x << " " << points[i].y << endl;
        if(points[i].x < minX)
        {
            minX = points[i].x;
            y = points[i].y;
            minInd = points[i].ind;
        }
    }
    nodes[ind] = minInd;
    //cout << " The minInd is " << nodes[ind] << endl;

    for(int i = 0; i < size; i++)
    {
        points[i].ang = getAng(minX, y, points[i]);
    }

    sort(points.begin(), points.end(), myfunc);

    int currPInd = 0;
    for(int i = 1; i < (n + 1); i++)
    {
        if(grid[ind][i] && visited[i] == false)
        {
            vector< Point > subPoints;
            for(int j = 0; j < weights[i]; j++)
            {
                if(points[currPInd].ind != nodes[ind])
                {
                    subPoints.push_back(points[currPInd]);
                }
                else
                {
                    j--;
                }
                currPInd++;
            }
            assignPoints(i, subPoints, n);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < (n - 1); i++)
    {
        int s = 0, d = 0;
        cin >> s >> d;
        grid[s][d] = grid[d][s] = true;
    }
    vector< Point > points;
    for(int i = 1; i < (n + 1); i++)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        points.push_back(Point(x, y, i));
    }
    clearVisited(n);
    setWeights(1, n);
    
    clearVisited(n);
    assignPoints(1, points, n);
   
    for(int i = 1; i < (n + 1); i++)
    {
        cout << nodes[i] << " ";
    }
    cout << endl;
    return 0;
}
