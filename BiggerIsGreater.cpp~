#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string swapAndTrunc(int prePos, int trialPos, string & prevString)
{
    char temp = prevString[prePos];
    prevString[prePos] = prevString[trialPos];
    prevString[trialPos] = temp;
    int resSize = prevString.size() - (prePos + 1);
    string res = prevString.substr(prePos + 1, resSize);
    prevString = prevString.substr(0, (prePos + 1));
    return res;


}
string sort(string & sub)
{
    int swaps = 0;
    int size = sub.size();
    for(int i = 0; i < (size - 1); i++)
    {
        if(sub[i + 1] < sub[i])
        {
            char temp = sub[i];
            sub[i] = sub[i + 1];
            sub[i + 1] = temp;
            swaps++;
        }
    }
    if(swaps > 0)
    {
        sort(sub);
    }
    return sub;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        bool found = false;
        string fullTest;
        cin >> fullTest;
        int size = fullTest.size();
        int lowBound = 0;
        int lowDist = 1000;
        int coord[2];
        for(int i = (size - 1);i >= lowBound;i--)
        {
            char testChar = fullTest[i];
            for(int j = i; j >= lowBound; j--)
            {
                if(testChar > fullTest[j])
                {
                     lowBound = j;
                     int currDist = size - j;
                     if(currDist < lowDist)
                     {
                        lowDist = currDist;
                        coord[0] = i;
                        coord[1] = j;
                     }
                     found = true;
                }
                if(i == lowBound && found == true)
                {
                    string sub = swapAndTrunc(coord[1],coord[0],fullTest);
                    fullTest+=sort(sub);
                    cout << fullTest << endl;
                    break;
                }
            }
            if(found && i == lowBound)
            {
                break;
            }
        }
        if(!found)
        {
            cout << "no answer" << endl;
        }
    }
    return 0;
}
