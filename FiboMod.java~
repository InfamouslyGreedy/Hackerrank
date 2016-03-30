import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class FiboMod {

    public static void main(String[] args)
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner getStuff = new Scanner(System.in);
        int a = getStuff.nextInt();
        int b = getStuff.nextInt();
        int N = getStuff.nextInt();
        BigInteger [] fibs = new BigInteger[N];
        fibs[0] = new BigInteger("" + a);
        fibs[1] = new BigInteger("" + b);
        for(int i = 2; i < N; i++)
        {
            fibs[i] = (fibs[i - 1].multiply(fibs[i - 1])).add(fibs[i - 2]);            
        }
        System.out.println(fibs[N - 1]);
    }
}
