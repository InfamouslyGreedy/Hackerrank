#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long int lli;
int n = 0;
void updateWinner(int currPlayer, bool & johnWin)
{
    if(currPlayer == 0)
        johnWin = true;
    else
        johnWin = false;
}
void playOptMove(bool & johnWin, int & numPiles, lli piles[], bool & pileDone, int currPlayer)
{
    lli val = 0;
    lli maxVal = 0;
    int maxInd = 0;
    for(int i = 0; i < n; i++)
    {
        val ^= piles[i];
        if(maxVal < piles[i])
        {
            maxVal = piles[i];
            maxInd = i;
        }
    }
    if(val > 0)
    {
        piles[maxInd] = maxVal ^ val;
        if(piles[maxInd] == 0)
            numPiles--;
        updateWinner(currPlayer, johnWin);
    }
    else
    {
        if((numPiles % 2) == 1 && pileDone == false)
        {
            updateWinner(currPlayer, johnWin);
            pileDone = true;
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(piles[i] > 0)
                {
                    piles[i] = 0;
                    numPiles--;
                    break;
                }
            }
        }
    }
}

int main()
{
    int g = 0;
    cin >> g;
    while(g--)
    {
        cin >> n;
        lli piles[n];
        int numPiles = n;
        lli init = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> piles[i];
            init ^= piles[i]; 
        }
        bool johnWin = false;
        bool pileDone = false;
        int currPlayer = 0;
        while(numPiles > 0)
        {
            playOptMove(johnWin, numPiles, piles, pileDone, currPlayer);
            /*for(int i = 0; i < n; i++)
                cout << piles[i] << " ";
            cout << endl;*/
            currPlayer = (currPlayer + 1) % 2;
        }
        if(johnWin)
            cout << "W" << endl;
        else
            cout << "L" << endl;
    }
    return 0;
}


