import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args)
    {
        int n = 0;
        Scanner getStuff = new Scanner(System.in);
        n = getStuff.nextInt();
        int arr [n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = getStuff.nextInt();
        }
        ArrayList al = new ArrayList();
        for(int i = 0; i < n; i++)
        {
            if(!(al.contains(arr[i])))
            {
                al.add(arr[i]);
            }   
        }
        int size = al.size();
        int uq [size];
        uq = (int)al.toArray();
        int counts[size];
        for(int i = 0; i < size; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(uq[i] = arr[j])
                {
                    count++;
                }
            }
            counts[i] = count;
        }
        List<BigInteger> list  = new ArrayList<BigInteger>();
        for(int i = 0; i < size; i++)
        {
            if(counts[i] > 1)
            {
                list.add(new BigInteger("" + counts[i] + ""));
            }
        }
        int lSize = list.size();
        for(int i = 0; i < lSize
    }
    public static BigInteger factorial(BigInteger curr)
    {
        return curr.multiply(factorial(curr.subtract(new BigInteger("1"))));
    }
}
