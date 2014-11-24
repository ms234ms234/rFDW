package codegenerator;

import java.util.Arrays;
import java.util.Vector;

/**
 *
 * @author Ms
 */
public class CodeGenerator {

    static int low = 0;
    static int high = 1;
    static int maxmessage = 6;
    static String port = "PORTD";
    static int rarity_of_pulse = 1000;  // outputs debug more often with this lower, less often with this higher
    static StringBuilder ouptut;    // misprint intentional
    
    static String  twoLetters(int n)
    {
        if(n>10)        return Integer.toString(n);
        else      return " " + Integer.toString(n);
    }
    
    static String  bitsFrom(Vector bits, Vector kolec)
    {
        StringBuilder sb = new StringBuilder(16);
        for(int i=kolec.size()-1; i>=0; i--)
        {
            if(bits.contains(kolec.get(i)))
                sb.append(Integer.toString(low));
            else
                sb.append(Integer.toString(high));
        }
        for(int i=8-kolec.size(); i>0; i--)
            sb.insert(0, Integer.toString(high));
        
        return sb.toString();
    }
    
    static void  recur(int d,String prev,String finis, Vector kolek, Vector bits)
    {
        if(d == 1)
            for(Object sm: kolek)
            {
                Vector nu = ((Vector)bits.clone());
                nu.add(sm);
                ouptut.append(prev + twoLetters((int) sm) + finis + bitsFrom(nu,kolek)+"\n");
                if(ouptut.length() % rarity_of_pulse == 0) System.out.println(ouptut.length());
            }
        else if (d > 1)
            for(Object sm: kolek)
            {
                Vector nu = ((Vector)bits.clone());
                nu.add(sm);
                recur(d-1, prev + twoLetters((int) sm) + ",",  
                        finis, kolek, nu);
            }
        else
            System.err.println("weirdly low d");
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Integer[] arr = {0,1,2,3,4,5,6,7}; 
        Vector Colec = new Vector(Arrays.asList(arr));
        ouptut = new StringBuilder(2*58*((int) Math.round(Math.pow(arr.length,maxmessage))));
        System.out.println("With buffer = "+ouptut.capacity());
        try
        {
        for(int i=1;i<=maxmessage;i++)
            recur(i,"#define		rFDW(",","+low+")		"+port+" "+ (low==0?"&":"|")+"= ",Colec,new Vector());
        
        low = 1;
        high = 0;
        for(int i=1;i<=maxmessage;i++)
            recur(i,"#define		rFDW(",","+low+")		"+port+" "+ (low==0?"&":"|")+"= ",Colec,new Vector());
        }
        catch(Exception E)
        {
            System.out.println("Wow!");
            System.out.println("Enjoy this while you're at it, and we're closing now.");
        }
        System.out.println(ouptut.toString());
    }
    
}
