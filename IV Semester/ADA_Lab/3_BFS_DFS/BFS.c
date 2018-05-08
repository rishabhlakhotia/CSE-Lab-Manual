#include<conio.h>
#include<stdio.h>

void BFS(int n,int graph[10][10], int source, int s[10])
{
	int i,f=0,r=-1,q[10],v;

	printf("%d",source);
	//assigning 1 as visted else default 0
	s[source] = 1;
	q[++r] = source;

	while(f <= r)
	{
		v = q[f++];
		for(i = 1; i<=n; i++)
		{
			if(s[i] ==0 && graph[v][i])
			{
				q[++r] = i;
				printf("-->%d",i);
				s[i] = 1;
			}
		}
	}
}
void main()
{
	int n,i,j,source,graph[10][10],s[10];


	printf("Enter Number of nodes: ");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
		s[i] = 0;

	printf("Enter source node: ");
	scanf("%d",&source);

	printf("Enter Graph Matrix: \n");
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d",&graph[i][j]);

	printf("Traversal is : ");
	BFS(n,graph,source,s);

	printf("\nreached nodes: ");
	for(i=1;i<=n; i++)
		if(s[i] == 1)
			printf("%d, ",i);
}
