import java.util.Scanner;
class Fib {
	public int recfib(int n)
    {
	   if(n==0)
            return 0;
         else if(n==1)
	      return 1;
        else 
           return recfib(n-1)+recfib(n-2);
   }


public int nonrecfib(int n)
    {
	    int fib1=0, fib2=1, fib3=0;
          if (n==0)
             System.out.println(fib1);
	   else if (n==1)
	       System.out.println(fib1+" "+fib2);
         else
         {
             System.out.println("0  1");
	        for(int i=0;i<n-1;i++)
	        { 
                 fib3=fib1+fib2;
      	System.out.print( " " +fib3);
		fib1=fib2;
		fib2=fib3;
	}	
	return fib3;
         }
   return n;
 }

}

public class FibDemo
{
           public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
	   int n;
        Fib f=new Fib();
        System.out.println("Enter the n value");
        n=s.nextInt();
	System.out.println("Fibonacci series using recursion:");
	int resf=0;
	for(int i=0;i<=n;i++)
      {
		resf=f.recfib(i);
		System.out.print(resf+" ");
      }
     System.out.println("\n"+n+"th Fibonacci value using recursion is "+resf);
	System.out.println("Fibonacci series using iterative method:");
	int resi= f.nonrecfib(n);
	System.out.println("\n"+"th Fibonacci value using iterative method  is "+resi);

    }
}
