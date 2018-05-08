#include<stdio.h>
#include<conio.h>

int knpsk ( int ,int ,int[], int[], int[][100]);
void optn ( int ,int,int[],int[],int[][100]);
int max(int, int);

void main(){

int w[20], max_wt,p[20],n,i,j,value,v[10][100];
clrscr();

printf("Enter the no. of items\n");
scanf("%d",&n);

printf("Enter the capacity of the KNAPSACK\n");
scanf("%d",&max_wt);

printf("Enter the value of each item\n");
for(i=1;i<=n;i++)
  scanf("%d",&p[i]);

printf("Enter the weight of each item\n");
for(i=1;i<=n;i++)
  scanf("%d",&w[i]);

value=knpsk(n,max_wt,w,p,v);

printf("Solution of the KNAPSACK problem is \n");
for(i=0;i<=n;i++){
  for(j=0;j<=max_wt;j++){
    printf("%d\t",v[i][j]);
     }
     printf("\n");
   }


printf("The maximum profit is %d:\n",value);
printf("The option selected are :\n");
optn(n,max_wt,w,p,v);

getch();

}

int knpsk (int n, int max_wt, int w[], int p[], int v[10][100])
{
 int i,j;
 for(i=0;i<=n;i++)
{
  for(j=0;j<=max_wt;j++)
  {

    //if there is no item or capacity of Knapsack is zero
    if(i==0 || j==0)
      v[i][j]=0;
    //if weight of ith item is greater than the capacity of knapsack
    else if(w[i]>j)
       v[i][j]= v[i-1][j];
    else
     v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);
  }

 }
 return (v[n][max_wt]);
}

void optn (int n,int max_wt,int w[],int p[],int v[10][100])
{
  int i,j;
  i=n;
  j=max_wt;
  while((i!=0)&& (j!=0))
  {
   if( v[i][j]!= v[i-1][j] )
   {
    printf("Value:%d Weight %d:\n",p[i],w[i]);
    j=j-w[i];
   }
   i--;
  }

}

int max ( int a, int b)
{
 return ( (a>b)?a:b);
}
