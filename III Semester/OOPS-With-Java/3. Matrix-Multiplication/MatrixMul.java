import java.util.Scanner;

public class MatrixMul {

	public static void main(String[] args) {
		
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		
		int m,n;
		System.out.println("enter the values of m and n");
		m=s.nextInt();
		n=s.nextInt();
		
		int p,q;
		System.out.println("enter the values of p and q");
		p=s.nextInt();
		q=s.nextInt();
		
		if(n!=p)
			System.out.println("Matrix multiplication not possible");
		else
		{
			int a[][]=new int[m][n];
			int b[][]=new int[p][q];
			int i,j,k;
			int c[][]=new int[m][q];
			
			System.out.println("enter the elements of Matrix A");
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					a[i][j]=s.nextInt();
			
			System.out.println("enter the elements of Matrix B");
			for(i=0;i<p;i++)
				for(j=0;j<q;j++)
					b[i][j]=s.nextInt();
			
			//Matrix multiplication
			
			for(i=0;i<m;i++)
			{
				for(j=0;j<q;j++)
				{
					c[i][j]=0;
					for(k=0;k<n;k++)
						c[i][j]=c[i][j]+a[i][k]*b[k][j];
				}
					
			}
			
			System.out.println("Contents of Matrix A");
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
					System.out.print(a[i][j]+" ");
				System.out.println();
			}
			
			System.out.println("Contents of Matrix B");
			for(i=0;i<p;i++)
			{
				for(j=0;j<q;j++)
					System.out.print(b[i][j]+" ");
				System.out.println();
			}
			
			System.out.println("Contents of Matrix C");
			for(i=0;i<m;i++)
			{
				for(j=0;j<q;j++)
					System.out.print(c[i][j]+" ");
				System.out.println();
			}
				
				
		}
	}

}
