#include<stdio.h>
#include<conio.h>
int prims(int cost[10][10],int n,int v[10],int d[10],int source)
{
	int i,j,min,u;
	v[source]=1;
	int sum=0;
	for(i=1;i<=n-1;i++)
	{
		min=999;
		for(j=1;j<=n;j++)
		{
			if(v[j]==0 && d[j]<min)
			{
				min=d[j];
				u=j;
			}
		}
        v[u]=1;
        sum=sum+d[u];

        for(j=1;j<=n;j++)
        {
            if(v[j]==0 && d[j]>cost[u][j])
                d[j]=cost[u][j];
        }
    }
    return sum;
}
int main()
{
	int i,j,n,source,cost[10][10],v[10],d[10],sum=999;
	printf("enter n \n");
	scanf("%d",&n);
	printf("enter cost matrix\n");
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    printf("enter source\n");
	scanf("%d",&source);
	for(i=1;i<=n;i++)
	{
		d[i]=cost[source][i];
		v[i]=0;
	}
	sum=prims(cost,n,v,d,source);
    if(sum>=999)
        printf("MST DOESN'T EXIST\n");
    else
        printf("cost of mst is %d",sum);
	return 0;
}
