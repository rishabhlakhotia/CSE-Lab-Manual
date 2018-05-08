#include<stdio.h>
#include<conio.h>
void nqueen(int);
int place(int [],int);
void main()
{
int n;
printf("enter n\n");
scanf("%d",&n);
nqueen(n);
}
void nqueen(int n)
{
int k=1,x[100],count=0,i;
x[k]=0;
while(k!=0)
{
	x[k]+=1;
	while((x[k]<=n) && (place(x,k)==0))
	x[k]+=1;
	if(x[k]<=n)
	{
		if(k==n)
		{
			printf("solution no %d\n",count++);
			for(i=1;i<=n;i++)
			printf("%d ",x[i]);
			getch();
		}
		else
		{
			k++;
			x[k]=0;
		}
	}
	k--;
}
}
int place(int x[100],int k)
{
	int i;
	for(i=1;i<=k-1;i++)
	{
		if(x[i]==x[k])
		return 0;
		if(abs(i-k)==abs(x[i]-x[k]))
		return 0;
	}
	return 1;
}
