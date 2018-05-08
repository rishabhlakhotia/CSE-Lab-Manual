#include<stdio.h>
#include<conio.h>
void  kruskall(int cost[][10],int n)
{

    int parent[20]={0},min,mincost=0,ne=1;
    int i,j,u,v,a,b;
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
    while(parent[u])
        u=parent[u];
    while(parent[v])
        v=parent[v];
    if(u!=v)
    {
        printf("%d edge(%d %d)=%d\n", ne++,a,b,min);
        mincost+=min;
        parent[v]=u;
    }
    cost[a][b]=cost[b][a]=999;
    }
    printf("the min cost is %d",mincost);
}
int main()
{
    int n,cost[10][10],i,j;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
    kruskall(cost,n);
    return 0;
}
