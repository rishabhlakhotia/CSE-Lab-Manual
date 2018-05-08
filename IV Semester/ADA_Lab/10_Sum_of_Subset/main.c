#include<stdio.h>
#include<conio.h>
int count;   //to count no of solutions
int w[10];   //items
int m;       //required sum
int x[10];   //items whose sum is d
void subset(int wsf,int k,int trm)
{
	int i;
	x[k]=1;
	if(wsf+w[k]==m)
	{
		printf("\n subset solution%d\n",count++);
		for(i=0;i<=k;i++)
		{
			if(x[i]==1)
			printf("%d",w[i]);
		}
		return;
	}
		if(wsf+w[k]+w[k+1]<=m)
		subset(wsf+w[k],k+1,trm-w[k]);
		if((wsf+trm-w[k]>=m) && (wsf+w[k+1]<=m))
		{
			x[k]=0;
			subset(wsf,k+1,trm-w[k]);
		}
}
void main()
{
	int sum=0;
	int i,n;
	printf("enter n\n");
	scanf("%d",&n);
	printf("enter items in increasing order\n");
	for(i=0;i<n;i++)
	scanf("%d",&w[i]);
	printf("enter required sum\n");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	sum=sum+w[i];
	subset(0,0,sum);
	getch();
}
