#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void next_move(int posr, int posc, vector <string> board)
{
    vector<string>::iterator it = board.begin();
    vector<string>::iterator last = board.end();
    int coord[2];
    int i = 0;
    int smallTot = 1000000;
    for(;it != last; it++)
    {
        string current = (*it);
        int size = current.size();
        for(int j = 0; j < size; j++)
        {
            int total = 0;
            if(current[j] == 'd')
            {
                total = abs((i - posr)) + abs((j - posc));
                if(total < smallTot)
                {
                    smallTot = total;
                    coord[0] = i;
                    coord[1] = j;
                }
            }
        }
        i++;
    }
    if(coord[0] == posr && coord[1] == posc)
    {
        cout << "CLEAN" << endl;        
    }
    else if(coord[1] > posc)
    {
        cout << "RIGHT" << endl;
    }
    else if(coord[1] < posc)
    {
        cout << "LEFT" << endl;
    }    
    else if(coord[0] < posr) 
    {
        cout << "UP" << endl;
    }
    else if(coord[0] > posr)
    {
        cout << "DOWN" << endl;
    }
    return;

}
int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
