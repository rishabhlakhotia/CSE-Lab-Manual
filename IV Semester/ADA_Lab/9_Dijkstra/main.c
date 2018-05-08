#include<stdio.h>
#include<conio.h>
void dijk(int cost[10][10],int n,int v[10],int d[10],int source)
{
	int i,j,min,u;
	v[source]=1;
	for(i=0;i<n;i++)
	{
		min=999;
		for(j=0;j<n;j++)
		{
			if(v[j]==0 && d[j]<min)
			{
				min=d[j];
				u=j;
			}
		}
	v[u]=1;
	for(j=0;j<n;j++)
	{
		if(v[j]==0 && d[j]>d[u]+cost[u][j])
		d[j]=d[u]+cost[u][j];
	}
}
}
void main()
{
	int i,j,n,source,cost[10][10],v[10],d[10];
	printf("enter n \n");
	scanf("%d",&n);
	printf("enter cost matrix\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&cost[i][j]);
	printf("enter source\n");
	scanf("%d",&source);
	for(i=0;i<n;i++)
	{
		d[i]=cost[source][i];
		v[i]=0;
	}
	dijk(cost,n,v,d,source);
	for(i=0;i<n;i++)
	printf("%d---->%d===%d\n",source,i,d[i]);
	getch();
}
