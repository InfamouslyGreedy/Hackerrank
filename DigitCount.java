/**
 * This program needs to 
 * 
 * @author (OLujimi) 
 * @version (a version number or a date)
 */
import java.util.*;
import java.lang.*;
public class DigitCount
{
    // instance variables - replace the example below with your own
    private static final int DECI = 10;
    
    public static void main(String[]args)
    {
       Scanner input = new Scanner(System.in);
       System.out.print(" Enter a string please : ");
       String d = input.nextLine();
       for(int s = 0; s < DECI ; s++)
       {
          System.out.println( s + " occurs " + countDigit(d)[s] + " times ");   
       }
    }

    public static int[] countDigit(String y)
    {
        int[] occurrence = new int[DECI];    
       
           for(int i = 0; i < y.length(); i++)
           {           
              for(int pos = 0; pos < DECI ; pos++)
              {
                 char p = Integer.toString(pos).charAt(0);//convert pos value to a char
                 Character position = new Character(p);
                 Character current = new Character(y.charAt(i));//the character on the i position
              
                 if(current.equals(position))
                 {                 
                    occurrence[pos]++;                     
                 }
              }
           }
        
        return occurrence;
    }
}

