#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool testAnagram(string testA, string testB)
{
	int letters1[26] = {0};
	int letters2[26] = {0};
	int size = testA.size();
	for(int i = 0; i < size; i++)
	{
		//cerr << "Into the A " << (int)testA[i] << " into " <<
		//(int)testB[i] << endl;
		letters1[((int)testA[i] - 97)]++;
		letters2[((int)testB[i] - 97)]++;
	}
	for(int i = 0; i < 26; i++)
	{
		/*	cerr << " The a " << testS << " and " << letters2[i]
			<< endl; */
		if(letters1[i] != letters2[i])
		{
			return false;
		}
	}
	return true;
}

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		string test;
		cin >> test;
		int size = test.size();
		int times = 345;
		int pairs = 0;
		int totIt = 0;
		while(totIt < (size - 1))
		{
			times = size - 1;
			while(times)
			{
				int start = totIt;
				int subSize = size - times;
				if(start + (subSize - 1) < size - 1)
                {
                    string testSub = test.substr(start,subSize);
                    //cerr << " test sub " << testSub << endl;
                    for(int i = (start + 1); i < size; i++)
                    {				
                        if(i + (subSize - 1) < size)
                        {
                            string trial = test.substr(i,subSize);
                            cerr << " The starter " << testSub << " and "
                            << "trial " << trial << endl;
                            if(testAnagram(testSub,trial))
                            {
                                //cerr << " testSub "<< testSub << " trial " << trial << endl;
                                pairs++;
                            }
                        }
                    }	
                }	
                times--;
            }
            totIt++;
        }
        cout << pairs << endl;
    }
    return 0;
}

