#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> lower, vector<int> upper)
{
    vector<int> res;
    int i = 0, j = 0;
    int lSize = lower.size(), uSize = upper.size();
    int size  = lSize + uSize;
    for(int k = 0; k < size; k++)
    {
        if(i < lSize && j < uSize)
        {
            if(lower[i] < upper[j])
            {
                res.push_back(lower[i]);
                i++;
            }
            else
            {
                res.push_back(upper[j]);
                j++;
            }
        }
        else if(i < lSize)
        {
            res.push_back(lower[i]);
            i++;
        }
        else if(j < uSize)
        {
            res.push_back(upper[j]);
            j++;
        }
    }
    return res;
}
void mergeSort(vector<int> & l)
{
    int size = l.size();
    if(size <= 1)
        return;
    int pivot = size / 2;
    vector < int > lower;
    vector < int> upper;
    for(int i = 0; i < size; i++)
    {
        if(i < pivot)
            lower.push_back(l[i]);
        else
            upper.push_back(l[i]);
    }
    mergeSort(lower);
    mergeSort(upper);
    l = merge(lower, upper);
}
int main()
{
    int n = 0; 
    cin >> n;
    vector<int> l;
    for(int i = 0; i < n; i++)
    {
        int val = 0;
        cin >> val;
        l.push_back(val);
    }
    mergeSort(l);
    int size = l.size();
    for(int i = 0; i < size; i++)
    {   
        cout << l[i] << " ";
    }
    cout << endl;
    return 0;
}
