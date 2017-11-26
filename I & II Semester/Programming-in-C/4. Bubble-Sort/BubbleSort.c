#include <stdio.h>
void main(){
  int a[100],n,i,j,temp;
  printf("Enter the number of elements\n");
  scanf("%d",&n);
  printf("Enter the %d elements of array\n",n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  printf("The Input array is\n");
  for(int i=0;i<n;i++){
    printf("%d\n",a[i]);
  }
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1;j++){
      if(a[j]>a[j+1]){
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }

  printf("The sorted array is\n");
  for(int i=0;i<n;i++){
    printf("%d\n",a[i]);
  }
}
