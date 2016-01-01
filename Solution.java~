import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args)
    {
        Scanner getStuff = new Scanner(System.in);
        int t = getStuff.nextInt();
        int count = 0;
        while(count < t)
        {
            int N = getStuff.nextInt();
            BigInteger M = getStuff.nextBigInteger();
            BigInteger [] vals = new BigInteger[N];
            BigInteger [] maxs = new BigInteger[N];
            BigInteger ultMax = BigInteger.ZERO;
            for(int i = 0; i < N; i++)
            {
                vals[i] = getStuff.nextBigInteger();
            }
            for(int i = 0; i < N; i++)
            {
                maxs[i] = getMax(vals, i, M);
                if(maxs[i].compareTo(ultMax) == 1)
                {
                    ultMax = maxs[i];
                }
            }
            System.out.println(ultMax);
            count++;
        }
    }
    public static BigInteger getMax(BigInteger [] vals, int start, BigInteger
    modder)
    {
        int size = vals.length;
        BigInteger max = BigInteger.ZERO;
        BigInteger total = BigInteger.ZERO;
        for(int i = start; i < size; i++)
        {
            total = (total.add((vals[i].mod(modder)))).mod(modder);
            if(total.compareTo(max) == 1)
            {
                max = total;
            }
        }
        return max;
    }
}
