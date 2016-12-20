#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
int main()
{
    int n = 0;
    cin >> n;
    vector<int> scores;
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        int val = 0;
        cin >> val;
        if(i == 0)
        {
            scores.push_back(val);
            index++;
        }
        else
        {
            if(val != scores[index - 1])
            {
                scores.push_back(val);
                index++;
            }
        }
    }
    int m = 0; 
    cin >> m;
    int start = index - 1;
    for(int i = 0; i < m; i++)
    {
        int currScore = 0;
        cin >> currScore;
        bool found = false;
        for(int j = start; j >= 0; j--)
        {
            if(scores[j] > currScore)
            {
                cout << (j + 2) << endl;
                found = true;
                start = j;
                break;
            }
        }
        if(found == false)
        {
            cout << 1 << endl;
            start = 0;
        }
    }
}   
