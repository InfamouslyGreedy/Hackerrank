#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

class incComp
{
    public:
        bool operator()(const int a, const int b)
        {
            return a < b;
        }
};

class decComp
{
    public:
        bool operator()(const int a, const int b)
        {
            return a > b;
        }
};

typedef priority_queue<int, vector<int>, incComp> incQType;
typedef priority_queue<int, vector<int>, decComp> decQType;

incQType incQ;
decQType decQ;

void add(int val, int count)
{
    if(count == 1)
    {
        incQ.push(val);
    }
    else
    {
        if(count % 2)
        {
            if(val > decQ.top())
            {
                incQ.push(decQ.top());
                decQ.pop();
                decQ.push(val);
            }
            else
            {
                incQ.push(val);
            }
        }
        else
        {
            if(val < incQ.top())
            {
                decQ.push(incQ.top());
                incQ.pop();
                incQ.push(val);
            }
            else
            {
                decQ.push(val); 
            }
        }
    }
}
int main()
{
   int n = 0;
   cin >> n;
   for(int i = 0; i < n; i++)
   {
        int val = 0;
        cin >> val;
        add(val, (i + 1));
        if(((i + 1) % 2) == 1)
            cout << fixed << setprecision(1) << (double)incQ.top() << endl;
        else
        {
            cout << fixed << setprecision(1) << (double)(incQ.top() + decQ.top())/(double)2 << endl;
        }
   }
}
