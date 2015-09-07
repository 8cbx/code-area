import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String args[]) throws Exception
    {
        Scanner cin = new Scanner(System.in);
        int t;
        t=cin.nextInt();
        while (t>0)
        {
        	t--;
            BigInteger[] a= new BigInteger[110];
            int n,i;
            int coun=0;
            boolean flag=false;
            BigInteger tmp=BigInteger.ZERO;
            n = cin.nextInt();
            for(i=1; i<=n; i++)
            {
                a[i]=cin.nextBigInteger();
            	if(a[i].compareTo(BigInteger.ZERO)==0)
            	{
            		coun++;
            	}
            }
            if(coun==n||n==1)
            {
            	System.out.println("Yes");
            	continue;
            }
            if(coun!=0)
            {
            	System.out.println("No");
            	continue;
            }
            BigInteger t1=BigInteger.ONE,t2=BigInteger.ONE,t3,t4;
            for(i=1;i<=n;i++)
            {
                if(i==2)
                {
                	t1=a[1];
                	t2=a[2];
                	BigInteger g=t1.gcd(t2);
                	t1=t1.divide(g);
                	t2=t2.divide(g);
                }
                else if(i>2)
                {
                    t3=a[i-1];
                	t4=a[i];
                	BigInteger g=t3.gcd(t4);
                	t3=t3.divide(g);
                	t4=t4.divide(g);
                	if(!t3.equals(t1)||!t2.equals(t4))
                	{
                        flag=true;
                	}
                }
            }
            if(flag==false)
            {
                System.out.println("Yes");
            }
            else
            {
                System.out.println("No");
            }
        }
    }
}
