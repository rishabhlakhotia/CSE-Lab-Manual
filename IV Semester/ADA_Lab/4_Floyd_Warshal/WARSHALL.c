#include<stdio.h>
#include<conio.h>

int i,j,k,n,a[50][50];

void Warshall( int a[50][50],int n){

for(k=1;k<=n;k++){
 for(i=1;i<=n;i++){
  for(j=1;j<=n;j++){
    if((a[i][j]==0)&&(a[i][k]==1 && a[k][j]==1))
       a[i][j]=1;

       }
     }
  }

printf("the modified matrix is\n");
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
       printf("%d\t",a[i][j]);
    }
   printf("\n");
  }
}

int main(){
printf("enter the no. of nodes\n");
scanf("%d",&n);
printf("Enter the adjacency matrix\n");
for(i=1;i<=n;i++)
  for(j=1;j<=n;j++){
    scanf("%d",&a[i][j]);
 }

Warshall(a,n);
return 0;
}
