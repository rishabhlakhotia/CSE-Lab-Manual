#include<stdio.h>
void main(){
  int a[10][10],b[10][10],c[10][10],i,j,k,m,n,p,q;
  printf("Enter the size of matrix A\n");
  scanf("\n%d%d",&m,&n);//read size of Matrix A
  printf("Enter the size of matrix B\n");
  scanf("\n%d%d",&p,&q);//read size of Matrix B
  if(n!=p)//check for compatability
  printf("Matrix multiplication is not possible");
  else
  {
    printf("Enter the elements of Matrix A\n");
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);//read matrix A
    printf("Enter the elements of Matrix A\n");
    for(i=0;i<p;i++)
      for(j=0;j<q;j++)
        scanf("%d",&b[i][j]);//read matrix B
    for(i=0;i<m;i++){
      for(j=0;j<q;j++){
        c[i][j]=0;
        for(k=0;k<n;k++){
          c[i][j]=c[i][j]+a[i][k]*b[k][j];//aXb logic
        }
      }
    }
    printf("\nA-Matrix is\n");
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
        printf("%d  ",a[i][j]);
        printf("\n");
    }
    printf("\nB-Matrix is\n");
    for(i=0;i<p;i++)
    {
      for(j=0;j<q;j++)
        printf("%d  ",b[i][j]);
        printf("\n");
    }
    printf("\nResultant-Matrix is\n");
    for(i=0;i<m;i++)
    {
      for(j=0;j<q;j++)
        printf("%d  ",c[i][j]);
        printf("\n");
    }
  }
}
