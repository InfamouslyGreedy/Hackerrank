import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class longFactorial {

    public static void main(String[] args)
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner getStuff = new Scanner(System.in);
        int testFact = getStuff.nextInt();
        BigInteger test = new BigInteger("" + testFact + "");
        System.out.println(fact(test));
    }
    public static BigInteger fact(BigInteger param)
    {
        BigInteger start = new BigInteger("" + param + "");
        BigInteger one = new BigInteger("1");
        if(start.equals(one))
        {
            return one;
        }
        else
        {
            BigInteger oneLess = new BigInteger("" + param.subtract(one) + "");
            start = start.multiply(fact(oneLess));               
            return start;
        }
    }
}
