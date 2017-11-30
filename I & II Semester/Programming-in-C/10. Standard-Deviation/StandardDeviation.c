#include<stdio.h>
#include<math.h>

void main() {

  //Declare Variables
  float a[10],*ptr,mean=0,sum=0,sd=0,sumsd=0;
  int i,n;

  //Taking inputs
  printf("\nEnter the number of element\n");
  scanf("%d",&n);
  printf("\nEnter the elements:\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  ptr=a;
  for(i=0;i<n;i++){
    sum=sum+(*ptr);
    ptr++;
  }
  mean=sum/n;
  ptr=a;
  for(i=0;i<n;i++){
    sumsd=sumsd+pow((*ptr-mean),2);
    ptr++;
  }
  sd=sqrt(sumsd/n);
  printf("\nSum=%f ",sum);
  printf("\nMean=%f ",mean);
  printf("\nStandard deviation=%f ",sd);

}
