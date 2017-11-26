#include <stdio.h>
#include <math.h>
void main(){
  float a,b,c,r1,r2,d,rpart,ipart;
  printf("Enter the non zero coefficient values of a,b and c: ");
  scanf("%d%d%d",&a,&b,&c);
  d=(b*b)-(4*a*c);
  if(d==0){
    printf("\nThe roots are real and equal");
    r1=-b/(2*a);
    r2=r1;
    printf("\nRoot1=%f\tRoot2=%f",r1,r2);
  }
  else if(d>0){
    printf("\nThe roots are real and distinct");
    r1=((-b)+sqrt(d))/(2*a);
    r1=((-b)-sqrt(d))/(2*a);
    printf("Root1=%f\nRoot2=%f",r1,r2);
  }
  else{
    printf("The roots are imaginary\n");
    rpart=-b/(2*a);
    ipart=sqrt(fabs(d))/(2*a);
    printf("Root1=%f+i%f\n",rpart,ipart);
    printf("Root1=%f-i%f\n",rpart,ipart);
  }
}
