#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int arr [], int pSize, int start, int left)
{
    int pivPos = start + pSize - 1;
    int pivot = arr[pivPos];
    int i = start - 1, j = start;
    /*if(left == 2)
    {
        cerr << " The left side start " << start << endl;
    }
    if(left == 0)
    {
        cerr << " The right side start " << start << endl;
    } */
    //cerr << " The starting i " << i << " size " << pSize << endl;
    if(pSize <= 1)
    {
        return;
    }
    for(;j < pivPos; j++)
    {
      //  cerr << " The curr " << arr[j] << " The pivot " << pivot << endl;
        if(arr[j] < pivot)
        {
        //    cerr << " got in!! " << endl;
            i++;
            if(arr[i] >= pivot)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        //cerr << " The i mark " << i << endl;
    }
    for(int index = pivPos - 1; index > i; index--)
    {
        arr[index + 1] = arr[index];
    }
    arr[i + 1] = pivot;
    /*for(int i = 0; i < pSize; i++)
    {
        cerr << arr[i] << " ";
    }
    cerr << endl; */
    quickSort(arr,(i + 1) - start,start, 2);
    int rSize = (pSize - ((i + 2) - start));
    quickSort(arr,rSize,(i + 2), 0);
}
int main() 
{
    int unsorted[] = {7,5,1,1,5, 36, -98, 5, 23, 0};
    quickSort(unsorted, 10,0,1);
    for(int i = 0; i < 10; i++)
    {
        cout << unsorted[i] << endl;
    }
    return 0;
}

