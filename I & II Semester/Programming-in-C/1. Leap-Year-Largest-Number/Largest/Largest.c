#include <stdio.h>

void main(){
  int a,b,c;
  printf("Enter three numbers:\n ");
  scanf("%d%d%d",&a,&b,&c);
  ((a>b)&&(a>c))?printf("\n%d is largest",a):(b>c)?printf("\n%d is the largest",b):printf("\n%d is the largest",c);
}
