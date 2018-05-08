#include<stdio.h>
#include<conio.h>

void DFS(int n,int a[10][10],int src,int s[10])
{

 int i;
 s[src]=1;
 printf("%d=>",src);
 for(i=1;i<=n;i++){
  if(s[i]==0 && a[src][i]==1)
   DFS(n,a,i,s);
  }
}

int main()
{
 int src,n,i,j,s[10],a[10][10];


 printf("Enter the no. of nodes\n");
 scanf("%d",&n);

 for(i=1;i<=n;i++)
  s[i]=0;


printf("Enter the adjacency matrix\n");
for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);

printf("Enter the source node\n");
scanf("%d",&src);

printf("The DFS tarversal is:\n");
DFS(n,a,src,s);

printf("The reached nodes are:\n");
for(i=1;i<=n;i++)
 if(s[i]==1)
   printf("%d\t",i);

return 0;

}
