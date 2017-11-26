#include <stdio.h>

void main() {

  // Declare Variables
  int a,b,c;

  printf("Enter three numbers:\n ");

  // Ask for input
  scanf("%d%d%d",&a,&b,&c);

  // Using Ternary Operator
  ((a>b)&&(a>c))?printf("\n%d is largest",a):(b>c)?printf("\n%d is the largest",b):printf("\n%d is the largest",c);
}
