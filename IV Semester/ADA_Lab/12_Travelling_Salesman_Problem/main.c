#include<stdio.h>

//Function declarations
int tsp_dp(int source,int v[10]);
int tsp_nn(int source,int v[10]);
int g(int source,int s[10]);
int setempty(int s[10]);

//Global variables
int n,cost[10][10],start;

//Main function
int main()
{
    int v[10] = {0};		//Initialise all elements of v[] = 0
    int i, j;
    int mincost1, mincost2;

    //Read No. of cities
    printf("Enter no. of cities: ");
    scanf("%d",&n);

    //Read cost matrix
    printf("Enter cost matrix:\n");
    for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
	scanf("%d",&cost[i][j]);

    //Read starting node (to start journey)
    printf("Enter Source: ");
    scanf("%d",&start);


    //Solve TSP using nearest neighbour and find least path
    mincost1 = tsp_nn(start,v);

    //Initialise all elements of v[] = 0
    for(i=1; i<=n; i++)
	v[i] = 0;

    //Solve TSP using dynamic programming and find least path
    mincost2 = tsp_dp(start,v);

    //Print result
    printf("\n\nCost using NN = %5d\n\n",mincost1);
    printf("\n\nCost using DP = %5d\n\n",mincost2);
    printf("Deviation: %f\n\n",(float)mincost1/mincost2);

    return 0;
}

//Function to check set is empty or not
//returns 1 - if set is empty else returns 0
int setempty(int s[10])
{
     int i;
     for(i=1; i<=n; i++)
     {
	if(s[i] == 0) return 0;
     }
     return 1;
}

//Function to find the optimal path from source to source through all the remaining nodes(k)
int g(int source,int s[10])
{
    int k,sum,least;

    //If set empty return c(1,k)
   if(setempty(s))
	return cost[source][start];

    //Compute least cost path from source to source through all the remaining nodes(k)
    //for all combinations of remaining(k) nodes
    least = 999;
    for(k=1; k<=n; k++)
    {
	if(s[k] == 1) 		 	//If node k already visited then ignore
		continue;

	s[k] = 1;
	sum = cost[source][k] + g(k,s);

	if(sum < least)
	{
	    least = sum;
	}
	s[k] = 0;
    }// end for

    return least;
}// end g

//Function to find optimal path using Dynamic programming
int tsp_dp(int source,int v[10])
{
    int sum;

    v[source] = 1;			//mark source node as visited
    sum = g(source,v);  		//get optimal path cost

    return sum;
}

//Function to find optimal path using Nearest neighbour (Approximation technique)
int tsp_nn(int source,int v[10])
{
    int sum=0;
    int least=0;
    int nextnode;
    int i,j;

    //Make diagonal elements as infinity (999)
    for(i=1; i<=n; i++)
    {
       for(j=1; j<=n; j++)
	  if(i == j)
		cost[i][j] = 999;
    }

    printf("TSP Solution using Nearest neighbour:\n\n");
    printf("Path : %5d",source);

   //Find least cost neighbour and visit it.
   //Repeat the process for n-1 times
   for(i=1; i<n; i++)
   {
	v[source] = 1;
	least = 999;
	for(j=1; j<=n; j++)
	{
	    if(cost[source][j] < least && v[j] == 0)
	    {
		least = cost[source][j];
		nextnode = j;
	    }
	}
	sum += least;
	printf(" --> %5d",nextnode);
	source = nextnode;
    }

    //add cost from last node to start node
    sum += cost[nextnode][start];
    printf(" --> %5d\n\n",start);


    return sum;
}
