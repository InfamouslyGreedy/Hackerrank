#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0; 
    cin >> n;
    int vals[n + 1];
    for(int i = 1; i < (n + 1); i++)
    {
        cin >> vals[i];
    }
    for(int i = 1; i < (n + 1); i++)
    {
        for(int j = 1; j < (n + 1); j++)
        {
            if(vals[vals[j]] == i)
                cout << j << endl;
        }
    }
}
