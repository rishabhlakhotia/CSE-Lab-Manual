#include<stdio.h>

struct network
{
    int dist[10], outgoing[10];
};
struct network nodes[10];

void intialize(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            nodes[i].outgoing[j] = j;
            if(i == j)
                nodes[i].dist[j] = 0;
            else
                nodes[i].dist[j] = 999;
        }
}

void floyd(int n)
{
    int i, j, k;

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(nodes[i].dist[j] > nodes[i].dist[k] + nodes[k].dist[j])
                {
                    nodes[i].outgoing[j] = k;
                    nodes[i].dist[j] = nodes[i].dist[k] + nodes[k].dist[j];
                }
}

int main()
{
    int n, i, j;

    printf("Enter number  of Nodes: ");
    scanf("%d",&n);
    intialize(n);

    printf("Enter the Distances\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i != j)
            {
                printf("Enter distance from %d to %d: ", i + 1, j + 1);
                scanf("%d",&nodes[i].dist[j]);
            }

    floyd(n);

    printf("\n\nDistance Vector Routing Algorithm\n");
    for(i = 0; i < n; i++)
    {
        printf("\nNode: %d (Vector Table)\n", i + 1);
        printf("\tDEST\tDIST\tHOP\n");
        for(j = 0; j < n; j++)
            if(i != j)
                printf("\t%d\t%d\t%d\n", (j + 1), nodes[i].dist[j], nodes[i].outgoing[j] + 1);
    }
    return(0);
}
